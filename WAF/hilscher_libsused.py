#!/usr/bin/env python
# -*- coding: utf-8 -*-
########################################################################################
# Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
########################################################################################
# $Id: hilscher_libsused.py 624 2022-02-22 08:02:15Z BMeyer $:
#
# Description:
#
# Waf module to generate libsused files
########################################################################################
from waflib import Logs, Task, Utils
from waflib.TaskGen import taskgen_method, feature, after_method
from waflib.Configure import conf
from collections import namedtuple
from waflib.Context import STDOUT, BOTH
import os
import re

@taskgen_method
def get_generators_recursive(self, tg):
    bld = self.bld

    result = set()
    stack  = set(Utils.to_list(getattr(tg, 'use', [])))

    while stack:
        x = bld.get_tgen_by_name(stack.pop())

        if x not in result:
            result.add(x)
            stack.update(set(Utils.to_list(getattr(x, 'use', []))))

    return result


def build_libsused_common(self, output, generators, referenced_node, install_name):
    inputs       = []
    input_tgens  = []

    for tg in generators:
        if 'cprogram' in tg.features:
            # never include an already linked elf in usedl ibs.txt
            hide_from_usedlibs = True
        elif getattr(tg, 'hidden_from_list', False):
            if 'cstlib' in tg.features:
                hide_from_usedlibs = True
            elif 'cxxstlib' in tg.features:
                hide_from_usedlibs = True
            else:
                # Do hide external components and sdk's (they're marked with 'hidden_from_list' too)
                hide_from_usedlibs = False
        else:
            hide_from_usedlibs = False

        if not hide_from_usedlibs:
            if not getattr(tg, 'posted', False):
                tg.post()

            link_task = getattr(tg,'link_task',None)

            if link_task:
                inputs.append(link_task.outputs[0])
                input_tgens.append((tg, link_task.outputs[0]))
            elif getattr(tg,'SDK', False) and getattr(self,'include_SDK', False):
                input_tgens.append((tg, None))

    task = self.libsused_task = self.create_task('LibsusedTask', inputs, [output])
    task.input_tgens = input_tgens
    task.referenced_node   = referenced_node

    if getattr(self, 'install_path', None):
        self.bld.install_as( "/".join(Utils.split_path(self.install_path) + [install_name]),\
                           output)

@feature('libsused')
@after_method('apply_link','build_nxo','build_nxf', 'build_nxi')
def build_libsused(self):
    bld = self.bld

    referenced_node = None

    use = self.to_list(getattr(self,'use',[]))

    output = self.path.find_or_declare(self.target + '_usedlibs.txt')

    if set(('cprogram','cstlib', 'stlib', 'cshlib', 'shlib')) & set(self.features) :
        # The 'libsused' features was enabled on this component
        tg = self
        referenced_node = self.link_task.outputs[0]
    elif 'nxo' in self.features:
        tg = self
        referenced_node = self.nxobuilder_task.outputs[0]
    elif 'nxf' in self.features:
        tg     = bld.get_tgen_by_name(use[0])
        referenced_node = self.nxf_task.outputs[0]
    elif ('nxi' in self.features) or ('mxf' in self.features):
        tg     = bld.get_tgen_by_name(use[0])
        referenced_node = self.nxi_task.outputs[0]
    else:
        bld.fatal(u'Failed to generate usedlibs for %s using features %s' % (self.target, self.features))

    generators = self.get_generators_recursive(tg)

    install_name = output.name
    build_libsused_common(self, output, generators, referenced_node, install_name)

@feature('libsused_global')
@after_method('apply_link','build_nxo','build_nxf', 'build_nxi')
def build_libsused_global(self):
    output     = self.path.find_or_declare(self.target)
    install_name = output.name

    generators = set()

    for g in self.bld.groups:
        for tg in g:
            features = self.to_list(getattr(tg, 'features', ''))

            # Only add version information of libraries referenced in programs, or other libraries
            if 'cprogram' in features or 'cstlib' in features:
                generators |= self.get_generators_recursive(tg)

            if 'cstlib' in features:
                generators.add(tg)

    build_libsused_common(self, output, generators, None, install_name)

@feature('libsused_explicit')
def build_libsused_explicit(self):
    bld = self.bld

    #generate a unique name for generated libsused file
    unique_name = "_generated_" + ("_".join(Utils.split_path(self.name) + Utils.split_path(self.target)))

    output = self.path.find_or_declare(unique_name)
    install_name = Utils.split_path(self.target)[-1]

    use = self.to_list(getattr(self,'use',[]))
    tg  = bld.get_tgen_by_name(use[0])

    referenced_node = None

    if len(use) == 1:
        if not tg.posted:
            tg.post()

        self.version = tg.version

        link_task = getattr(tg,'link_task',None)

        if link_task:
            referenced_node = link_task.outputs[0]

    generators = self.get_generators_recursive(tg)

    for x in use[1:]:
        generators |= self.get_generators_recursive(bld.get_tgen_by_name(x))

    build_libsused_common(self, output, generators, referenced_node, install_name)

@conf
def generate_libsused(bld, name, target, use = [], **kw):
    use = Utils.to_list(use)

    if len(use) > 1:
        bld.fatal("Libused generation only works for a single target, and multiple targets (%u)were given via use" % len(use))

    if use:
        tg = bld.get_tgen_by_name(use[0])
        if not 'cprogram' in getattr(tg, 'features', []):
            # This is not a cprogram. So we try to check the used components
            # e.g. a firmware target will have the cprogram target in use
            for x in Utils.to_list(getattr(tg, 'use', [])):
                tg = bld.get_tgen_by_name(x)
                if 'cprogram' in getattr(tg, 'features', []):
                    # We've found the possible target, so override use parameter from function call
                    use = [tg.name]
                    break
            else:
                # No cprogram found in given use component
                bld.fatal("Libsused generation did not find any useable program for generation in use parameters (target=%r, use=%r)" % (name, use))
        features = 'libsused_explicit'
    else:
        features = 'libsused_global'

    bld(name             = name,
        target           = target,
        features         = features,
        use              = use,
        hidden_from_list = "Internal",
        **kw)

class LibsusedTask(Task.Task):
    color   = 'PINK'
    log_str = '[LIBSUSED] $TARGETS'

    def extractVersionSection(self, tg, node):
        bld = self.generator.bld

        env = tg.env

        if not env.get_flat('OBJDUMP'):
            toolchain = getattr(tg,'toolchain', None)

            if toolchain:
                env = bld.all_envs[toolchain]
            else:
                target_triple, sep, dummy = tg.name.partition('/')

                toolchains = {
                  'arm-eabi'          : ['ecoscentric'],
                  'arm-none-eabi'     : ['codesourcery'],
                  'armv7r-none-eabi'  : ['gccarmemb'],
                  'armv7em-none-eabi' : ['gccarmemb'],
                  'arm-hitex-elf'     : ['hitex'],
                }.get(target_triple,['codesourcery', 'ecoscentric'])

                for x in toolchains:
                    try:
                        env = bld.all_envs['toolchain_%s' % x]
                    except KeyError:
                        pass
                    else:
                        if env.get_flat('OBJDUMP'):
                            break

        objdump = env.get_flat('OBJDUMP')

        if not objdump:
            msg = 'Suitable objdump not found for %s' % node.abspath()
            Logs.debug('libsused: ' + msg)
            raise ValueError(msg)

        cmd = [objdump, '-sj', '.hilscher_version', node.abspath()]
        try:
            out,err = bld.cmd_and_log(cmd, output=BOTH, quiet=BOTH)
        except bld.errors.WafError, e:
            Logs.debug('libsused: Failed to run "%s"' % (' '.join(cmd)))
            err = 'Failed to run objdump'

        if len(err) > 0:
            msg = 'Failed to dump hilscher_version section from %s' % node.abspath()
            Logs.debug('libsused: ' + msg)
            raise ValueError(msg)
        else:
            dummy, sep, dump = out.partition("Contents of section .hilscher_version:")

            hexversion = ''
            match = re.compile(r'[0-9a-fA-F]+\s[0-9a-fA-F]+').match

            for line in dump.splitlines():
                line = line.strip()
                if line:
                    if match(line):
                        hex,sep,dummy = line.partition('  ')
                        hexnumbers  = hex.split()[1:]
                        hexversion += ''.join(hexnumbers)
                    else:
                        break

            if len(hexversion) % 2:
                Logs.error('unexpected version string length %d for target %s' % (len(hexversion), tg.name))
                hexversion = hexversion[:-1]

            version_string = hexversion.decode('hex').partition('\x00')[0].strip()

        return version_string

    def run(self):
        # define a nmed tuple to hold information used later when formating the file
        used_info = namedtuple('used_info', ['name', 'version', 'description'])

        bld = self.generator.bld
        cwd = bld.variant_dir

        usedlibs   = {}

        lengths = { "max_name_len" : 0, "max_version_len" : 0}

        # iterate over all input files and generate a version entry for them
        for tg, x in self.input_tgens:
            prefix, sep, name = tg.name.rpartition('/')

            version     = getattr(tg, 'version', None)

            if version:
                version = u'V%s' % version
            else:
                version = u'<Undefined version>'

            description = unicode(getattr(tg, 'description', None) or u'<No description>')

            if x is not None:
                name = x.name

                try:
                    version_string = self.extractVersionSection(tg, x)
                    Logs.debug(u'libsused: extracted version information from library %s' % (x.name))
                except ValueError:
                    self.generator.report_finding(x, u'no version information compiled into library')
                    Logs.debug(u'libsused: extracted version information from task generator %s' % (x.name))
                else:
                    if version and (version not in version_string.split()):
                        self.generator.report_finding(x,u'mismatch in version information extracted from library and task generator "%s" <> "%s"' % (version_string, version))

                    description = re.sub(r'\s?[Vv][0-9]+[.][0-9]+[.][0-9]+[.][0-9]+\s?', u' ', version_string)

            lengths['max_name_len']    = max(len(name), lengths['max_name_len'])
            lengths['max_version_len'] = max(len(version), lengths['max_version_len'])

            try:
                usedlibs[prefix].add(used_info(name,version,description))
            except KeyError:
                usedlibs[prefix] = set((used_info(name,version,description),))

        fmt_use = (u'{name:<%(max_name_len)u} {version:<%(max_version_len)u} {description}' % lengths).format
        output  = u''

        if self.referenced_node:
            target_node    = self.referenced_node
            target_version = getattr(self.generator,'version', None)

            if target_version:
                target_version = u'V%s' % target_version
            else:
                target_version = u'<Undefined version>'

            output += u'Target:  {0}\n'.format(target_node.name)
            output += u'Version: {0}\n'.format(target_version)
            output += u'\n'

            output += u'Used Libraries\n'
            output += u'==============\n'
        else:
            output += u'Used Libraries summary\n'
            output += u'======================\n'

        for prefix in sorted(usedlibs.keys()):
            output += u'\n%s\n' % prefix
            output += (u'-' * len(prefix)) + u'\n'

            output += u'\n'.join(fmt_use(**y._asdict()) for y in sorted(usedlibs[prefix],key = lambda x : x.name)) + u'\n'

        # Get values of certain environment variables
        vars = Utils.to_list('SPC_BUILDTOOLS_REV')
        vars = list((x, os.environ.get(x, None)) for x in vars)

        # filter out unset values
        vars = list(x for x in vars if x[1])

        if vars:
            output += u'\n'
            output += u'Selected Environment variables\n'
            output += u'==============================\n'

            lengths = { 'max_var_len' : max(len(var) for var,_ in vars)}

            fmt_vars = (u'{var:<%(max_var_len)u}={value}\n' % lengths).format

            for var,value in sorted(vars, key = lambda x : x[0]):
                output += fmt_vars(var=var, value=str(value))


        self.outputs[0].write(output)
