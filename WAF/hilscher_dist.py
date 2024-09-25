#! /usr/bin/env python
# encoding: utf-8
########################################################################################
# Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
########################################################################################
# $Id:  $:
#
# Description:
# Distribution generation functions
########################################################################################
import itertools
from waflib import Task, Logs, Context, Options, Node, Errors, Utils
from waflib.Configure import conf
from waflib.Build import BuildContext
from waflib.TaskGen import feature, after_method, before_method, taskgen_method
from waflib.Context import WSCRIPT_FILE
import shutil
import time, os, re, sys, string

template_wscript_header = string.Template('''\
def configure(conf):
    ${EXTRA_CONFIGURE}
    pass

def build(bld):
''')

template_wscript_sdk = string.Template('''\
    bld(
        name            = '${NAME}',
        description     = '${DESCRIPTION}',
        displaygroup    = '${DISPLAYGROUP}',
        version         = '${VERSION}',

        SDK             = True,
        export_includes = [${INCLUDE_PATHS}],
        export_defines  = [${EXPORT_DEFINES}],
    )
''')

template_wscript_extlib = string.Template('''\
    bld.externalcomponent(
        name            = '${NAME}',
        description     = '${DESCRIPTION}',
        displaygroup    = '${DISPLAYGROUP}',
        version         = '${VERSION}',

        target          = '${TARGET}',
        path            = '${PATH}',
        export_includes = [${INCLUDE_PATHS}],
        export_defines  = [${EXPORT_DEFINES}],
        uselib          = [${USELIB}],
    )
''')


@conf
def distribute_lib(bld, install_path, use , **kw):
    if not getattr(bld,'is_install', False):
        return

    kw.setdefault('wscript_name', 'wscript')
    kw.setdefault('dist_includes', [])

    # mandatory parameters:
    kw['use']          = Utils.to_list(use)[:]
    kw['install_path'] = install_path
    kw['target']       = install_path + '/' + kw['wscript_name']
    kw['name']         = kw['target']

    bld.check_args(**kw)

    use_ltd =  Utils.to_list(kw.get('use_ltd', []))[:]
    use_usedlibs = Utils.to_list(use)[:] + use_ltd

    # generate distribution folder
    bld(features = 'distribute distribute_lib',
        hidden_from_list = "Internal",
        **kw)

    # generate libsused file
    bld(name     = '%s/libsused' % install_path,
        target   = 'libsused.txt',
        features = 'libsused_explicit',
        use      = use_usedlibs,
        include_SDK = True,
        hidden_from_list = "Internal",
        install_path = '%s/ReleaseNotes/' % install_path)

@conf
def distribute_firmware(bld, install_path, use , **kw):
    if not getattr(bld,'is_install', False):
        return

    kw.setdefault('dist_includes', [])

    # mandatory parameters:
    kw['use']          = use[:]
    kw['install_path'] = install_path
    kw['name']         = install_path

    bld.check_args(**kw)

    use_ltd =  kw.get('usr_ltd', [])[:]
    use_usedlibs = list(x for x,p in (use + use_ltd))

    # generate distribution folder
    bld(features = 'distribute distribute_firmware',
        hidden_from_list = "Internal",
        **kw)

    # generate libsused file
    bld(name     = '%s/libsused' % install_path,
        target   = 'libsused.txt',
        features = 'libsused_explicit',
        use      = use_usedlibs,
        hidden_from_list = "Internal",
        install_path = '%s/ReleaseNotes/' % install_path)

@conf
def distribute_doc(bld, install_path, use_doc , **kw):
    if not getattr(bld,'is_install', False):
        return

    kw.setdefault('dist_includes', [])

    # mandatory parameters:
    kw['use_doc']      = use_doc[:]
    kw['install_path'] = install_path
    kw['name']         = install_path

    bld.check_args(**kw)

    # generate distribution folder
    bld(features = 'distribute',
        hidden_from_list = "Internal",
        **kw)

@feature('distribute_lib', 'distribute_firmware')
@before_method('set_default_folders')
def set_default_folders_lib_firmware(self):
    dct = self.__dict__

    dct.setdefault('doc_folder_name',          'Documentation')
    dct.setdefault('include_folder_name',      'Includes')
    dct.setdefault('lib_folder_name',          'Lib')
    dct.setdefault('lib_ltd_folder_name',      'Lib_Ltd')
    dct.setdefault('firmware_folder_name',     'Firmware')
    dct.setdefault('firmware_ltd_folder_name', 'Firmware_Ltd')

@feature('distribute')
def set_default_folders(self):
    dct = self.__dict__
    dct.setdefault('doc_folder_name', '')

@taskgen_method
def dist_iterate_use(self, use):
    for x in use:
        if isinstance(x,(tuple,list)):
            name, subdir_path = tuple(x)
        else:
            name, subdir_path  = x, None

        tgen = self.bld.get_tgen_by_name(name)

        if not getattr(tgen, 'posted', None):
            tgen.post()

        yield x, name, subdir_path, tgen

@feature('distribute_lib', 'distribute_firmware')
@after_method('set_default_folders')
@before_method('check_tgen_availability')
def dist_binary(self):
    bld = self.bld

    install_path = Utils.split_path(self.install_path)

    include_dist_paths   = set()

    tsk_debug_archive = None

    if 'distribute_lib' in self.features:
        name = 'generated_' + '_' .join(Utils.split_path(self.install_path) + [self.wscript_name])

        wscript_node = self.path.find_or_declare(name)
        tsk = self.wscript_task = self.create_task('distribute_generate_wscript', [], [wscript_node])
        tsk.install_dirs  = {}
        tsk.generators     = []

        bld.install_as('/'.join(install_path + [self.wscript_name]), wscript_node)
        tsk.install_dirs[wscript_node] = '/'.join(install_path)

        include_dist_paths.add(tuple(install_path[:]))

    install_debug_path = getattr(self, 'install_debug_path', None)

    if install_debug_path:
        name = 'generated_' + '_' .join(Utils.split_path(self.install_path) + Utils.split_path(self.install_debug_path))

        debug_archive_node = self.path.find_or_declare(name)

        tsk_debug_archive  = self.debug_archive_task = self.create_task('distribute_generate_debug', [], [debug_archive_node])
        tsk_debug_archive.install_paths = {}

        bld.install_as(install_debug_path, debug_archive_node)

    use     = self.to_list(self.use)
    use_ltd = self.to_list(getattr(self,'use_ltd', []))

    include_search_paths = []

    for x, name, subdir_path, tgen in self.dist_iterate_use(use + use_ltd):
        ltd = x in use_ltd

        # build list of used task generators
        include_tgen     = [tgen]

        for y in Utils.to_list(getattr(tgen,'use',[])):
            include_tgen.append(self.bld.get_tgen_by_name(y))

        # additional nodes to distribute for debug purposes
        dist_debug_nodes = []

        for y in include_tgen:
            # collect include search paths
            include_search_paths.extend(getattr(y, "include_nodes", [])[:])

            # collect exported include search paths
            for z in getattr(y, "export_includes", []):
                include_search_paths.append(y.path.find_node(z))

            # collect debug nodes for distribution
            dist_debug_nodes.extend(getattr(y, 'dist_debug_nodes', []))

        parts    = tgen.name.split('/')

        # get distribution nodes
        dist_nodes = getattr(tgen,'dist_nodes', [])

        if getattr(tgen,'SDK', False):
            dst_subdir_parts       = None
        elif set(tgen.features) & set(['fake_lib', 'shlib', 'stlib', 'cshlib', 'cstlib']):
            try:
                link_task = tgen.link_task
            except AttributeError:
                reason = getattr(tgen,'tgen_disabled', None)
                bld.fatal(u'Library distribution target %r not available or disabled. reason: %r' % (tgen.name, reason))

            if not hasattr(tgen, 'dist_nodes'):
                dist_nodes.append(link_task.outputs[0])

            if ltd:
                dst_subdir_parts = install_path + [self.lib_ltd_folder_name]
            else:
                dst_subdir_parts = install_path + [self.lib_folder_name]
        else:
            if not hasattr(tgen, 'dist_nodes'):
                dist_nodes.append(tgen.path.find_or_declare(tgen.target))

            if ltd:
                dst_subdir_parts = install_path + [self.firmware_ltd_folder_name]
            else:
                dst_subdir_parts = install_path + [self.firmware_folder_name]

            include_dist_paths.add(tuple(dst_subdir_parts[:]))

        # init list of destination file names
        dst_names   = list(x.name for x in dist_nodes)

        if 'fake_lib' in tgen.features:
            # an external library is to be distributed with this distribution, extract
            # original path from library and reuse it if possible
            prefix = ('%s/%s/' % (parts[0], parts[1])).lower()
            orig_path = '/'.join(Utils.split_path(dist_nodes[0].path_from(tgen.path)))

            i = orig_path.lower().find(prefix)

            if i >= 0:
                p = Utils.split_path(prefix + orig_path[ i + len(prefix):])
            else:
                Logs.warn(u'Unable to extract prefix for %s' % tgen.name)
                p = Utils.split_path(orig_path)

            # Last item in p is the name of the library file itself
            # we just want the prefix path
            dst_subdir_parts.extend(p[0:-1])

        elif len(dist_nodes) > 0:
            if subdir_path is not None:
                if subdir_path.endswith('/') or subdir_path.endswith('\\'):
                    # subdir_path is a directory:
                    dst_subdir_parts.extend(Utils.split_path(subdir_path))
                else:
                    # subdir_path is a file

                    if len(dist_nodes) > 1:
                        bld.fatal(u'Can not distribute multiple targets to single filename for %r' % tgen.name)

                    p = Utils.split_path(subdir_path)

                    dst_subdir_parts.extend(p[0:-1])
                    dst_names[0] = p[-1]

                    base, ext = os.path.splitext(dst_names[0].lower())

                    if ext not in '.nxi .nxf .nxo .rom'.split():
                        Logs.warn(u'Missing file extension for distribution %s. (Check for missing trailing slash sub-path?)' % ('/'.join(p)))

                # also install libsused file if available
                libsused_task = getattr(tgen, 'libsused_task', None)

                if libsused_task is not None:
                    bld.install_as('/'.join( dst_subdir_parts + ['%s_usedlibs.txt' % dst_names[0]]),
                                   libsused_task.outputs[0])

            elif 'distribute_lib' in self.features:
                toolchain, toolchain_version, dummy = bld.get_name_prefix(
                  toolchain = tgen.toolchain,platform  = tgen.platform).split('/', 2)

                if len(parts) not in (3,4):
                    bld.fatal(u'Invalid generator name %s' % tgen.name)

                if parts[0] != toolchain:
                    Logs.warn(u'Unexpected toolchain in generator %s' % tgen.name)

                if parts[1] != toolchain_version:
                    Logs.warn(u'Unexpected toolchain version in generator %s' % tgen.name)

                dst_subdir_parts.extend([toolchain, toolchain_version])

                if len(parts) == 4:
                    os_label = parts[2]
                    dst_subdir_parts.append(os_label)

                platform_label = tgen.platform.lower()

                if platform_label not in ('netx'):
                    dst_subdir_parts.append(platform_label)

            else:
                bld.fatal(u'Unable to determine install path for %s' % tgen.name)

        dst_subdir = '/'.join(dst_subdir_parts or [])

        for node, n in zip(dist_nodes,dst_names):
            bld.install_as(dst_subdir + '/' + n, node)

        if 'distribute_lib' in self.features:
            tsk.set_inputs(dist_nodes)

            for x in dist_nodes:
                tsk.install_dirs[x] = '/'.join(dst_subdir_parts)

            tsk.generators.append((tgen, x))

        if tsk_debug_archive:
            for node in dist_debug_nodes:
                tsk_debug_archive.set_inputs(node)
                tsk_debug_archive.install_paths[node] = dst_subdir + '/' + node.name

    for x in self.dist_includes:
        if isinstance(x,(tuple,list)):
            src_path, subdir_path = x
        else:
            src_path, subdir_path = x, None

        for x in include_search_paths:
            include_node = x.find_node(src_path)

            if include_node:
                if subdir_path is None:
                    subdir_path = include_node.parent.path_from(x)
                break
        else:
            bld.fatal(u'Include file %s not found in use/use_ltd targets' % src_path)

        for y in include_dist_paths:
            dst_path_parts = list(y) +  [self.include_folder_name] + Utils.split_path(subdir_path)
            bld.install_files('/'.join(dst_path_parts), [include_node])

@feature('distribute')
@after_method('set_default_folders')
@before_method('check_tgen_availability')
def dist_doc(self):
    bld = self.bld
    use_doc = self.to_list(getattr(self, 'use_doc', []))

    install_path = Utils.split_path(self.install_path)

    for x, name, subdir_path, tgen in self.dist_iterate_use(use_doc):
        dist_nodes = getattr(tgen,'dist_nodes', [])

        dst_subdir_parts = install_path + [self.doc_folder_name]

        # init list of destination file names
        dst_names   = list(x.name for x in dist_nodes)

        if subdir_path is not None:
            if subdir_path.endswith('/') or subdir_path.endswith('\\'):
                # subdir_path is a directory:
                dst_subdir_parts.extend(Utils.split_path(subdir_path))
            else:
                # subdir_path is a file
                if len(dist_nodes) > 1:
                    bld.fatal(u'Can not distribute multiple targets to single filename for %r' % tgen.name)

                p = Utils.split_path(subdir_path)

                dst_subdir_parts.extend(p[0:-1])
                dst_names[0] = p[-1]

        dst_subdir = '/'.join(dst_subdir_parts or [])

        for node, n in zip(dist_nodes, dst_names):
            bld.install_as(dst_subdir + '/' + n, node)

class distribute_generate_wscript(Task.Task):
    u''' Generate wscript in distribution folder '''
    log_str   = "[WSCRIPT] $TARGET"
    color     = 'PINK'
    inst_to   = None
    cmdline   = None

    def run(self):
        output_node = self.outputs[0]

        output_node.parent.mkdir()

        with open(output_node.abspath(), 'wt') as fh:
            dct = {}

            extra_configure = getattr(self.generator, 'extra_configure', '').splitlines()

            indent = ' ' * 4
            dct['EXTRA_CONFIGURE'] = ('\n' + indent).join(x.lstrip() for x in extra_configure)

            wscript_header = template_wscript_header.substitute(dct)
            fh.write(''.join((x.rstrip() + '\n') for x in wscript_header.splitlines()))
            separator = ''

            remove_prefix = self.install_dirs[output_node] + '/'
            for tgen, node in self.generators:
                dct = {
                    'NAME'           : tgen.name,
                    'DESCRIPTION'    : tgen.description,
                    'DISPLAYGROUP'   : tgen.displaygroup,
                    'VERSION'        : tgen.version,
                    'INCLUDE_PATHS'  : "'%s'" % self.generator.include_folder_name,
                }

                if getattr(tgen, 'SDK', False):
                    tmpl = template_wscript_sdk
                else:
                    tmpl = template_wscript_extlib

                    dct['TARGET'] = Utils.split_path(tgen.target)[-1]
                    dct['PATH']   = self.install_dirs[node][len(remove_prefix):]

                # If a component defines public_defines we will use them,
                # otherwise fall back to export defines
                export_defines = Utils.to_list(getattr(tgen, 'public_defines', [])) +\
                                Utils.to_list(getattr(tgen, 'export_defines', []))

                uselib = Utils.to_list(getattr(tgen, 'uselib', []))

                indent = ' ' * 28
                dct['EXPORT_DEFINES'] = (',\n' + indent).join("'%s'" % x for x in export_defines)
                dct['USELIB']         = (',\n' + indent).join("'%s'" % x for x in uselib)

                fh.write(separator + tmpl.substitute(dct))
                separator = '\n'

class distribute_generate_debug(Task.Task):
    u''' Generate debug information in distribution folder '''
    log_str   = "[DEBUGZIP] $TARGETS"
    color     = 'PINK'
    inst_to   = None
    cmdline   = None

    def run(self):
        import zipfile

        output_node   = self.outputs[0]
        input_nodes   = self.inputs
        install_paths = self.install_paths

        output_node.parent.mkdir()

        with zipfile.ZipFile(output_node.abspath(), mode = 'w', compression=zipfile.ZIP_DEFLATED) as zfile:
            for i in input_nodes:
                zfile.write(i.abspath(), install_paths[i])
