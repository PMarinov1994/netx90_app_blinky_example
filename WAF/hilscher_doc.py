#!/usr/bin/env python
# -*- coding: utf-8 -*-
########################################################################################
# Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
########################################################################################
# $Id:  $:
#
# Description:
# waf support for building documentations
########################################################################################
from waflib.TaskGen import feature, after_method, before_method
from waflib.Configure import conf
from waflib import Utils, Task, Logs
from waflib import Build, Context

import re
import os
import shlex

# Define a flag property to control if documentation shall be build
def build_documentation(self):
    return self.is_install or self.cmd == 'doc'
Context.Context.build_documentation = property(build_documentation)

class DocumentationContext(Build.BuildContext):
  '''Build & Generate documentation'''
  cmd = 'doc'

def configure(conf):
    # change to parent environment object
    conf.setenv('')

    # find tool used for doxygen
    conf.find_program('doxygen', var='DOXYGEN')
    conf.find_program('hhc',     var='HTMLHELPC')

    plantuml_buildtools_node = conf.root.find_dir(os.environ['PATH_BUILDTOOLS'] + os.sep + 'plantuml')

    ret = None
    if plantuml_buildtools_node is not None:
        # find all available versions
        nodes = plantuml_buildtools_node.ant_glob('**/plantuml.jar')

        # make mapping version -> file
        nodes_by_version = dict( (tuple(map(int,x.parent.name.split('.'))), x) for x in nodes)

        # get most recent version
        k = sorted(nodes_by_version.keys())[-1]

        ret = nodes_by_version[k].abspath()

    conf.msg('Checking for plantuml', ret or False)

    if ret:
        conf.env['PLANTUML'] = ret

def get_doxygen_boolean(doxygen_params, key):
    val = doxygen_params.get(key,'NO').lower()
    return val in ('true', 'yes')

def get_doxygen_outputs(doxyfile_node, doxygen_params):
    doxygen_output_nodes = []

    output_dir_node = doxyfile_node.parent.declare_node(doxygen_params['OUTPUT_DIRECTORY'])

    if get_doxygen_boolean(doxygen_params, 'GENERATE_HTMLHELP'):
        # add chm node to outputs
        chm_node = output_dir_node.declare_node(doxygen_params['HTML_OUTPUT']).declare_node(doxygen_params['CHM_FILE'])
        doxygen_output_nodes.append(chm_node)

    if get_doxygen_boolean(doxygen_params, 'GENERATE_XML'):
        # add xml node to outputs
        xml_node = output_dir_node.declare_node(doxygen_params['XML_OUTPUT']).declare_node('index.xml')
        doxygen_output_nodes.append(xml_node)

    return doxygen_output_nodes


re_match_doxysetting = re.compile(r'^\s*(?P<parameter>\S+)\s*(?P<operator>[+]?=)\s+(?P<value>\S.*)$').match

# as long as this is not properly implemented
@Task.always_run
class doxygen(Task.Task):
    color = 'CYAN'

    run_str_doxygen = '${DOXYGEN} ${SRC}'

    (run_doxygen, doxygen_vars) = Task.compile_fun(run_str_doxygen)

    run_str_hhc = '${HTMLHELPC} ${SRC}'

    (run_hhc, hhc_vars) = Task.compile_fun(run_str_hhc)

    vars = doxygen_vars + hhc_vars

    log_str = '[DOXYGEN] ${SOURCES}'

    @property
    def target(self):
        return ''

    path_parameter_names = set('''
        CITE_BIB_FILES
        DIAFILE_DIRS
        DOTFILE_DIRS
        EXCLUDE
        EXAMPLE_PATH
        IMAGE_PATH
        INCLUDE_PATH
        INPUT
        HTML_EXTRA_FILES
        HTML_EXTRA_STYLESHEET
        HTML_FOOTER
        HTML_HEADER
        HTML_STYLESHEET
        LATEX_EXTRA_FILES
        LAYOUT_FILE
        MSCFILE_DIRS
        RTF_EXTENSIONS_FILE
        RTF_STYLESHEET_FILE
        TAGFILES
        WARN_LOGFILE
        USE_MDFILE_AS_MAINPAGE
    '''.split())


    def translate_paths(self, parameter, value):
        doxyfile_node = self.inputs[0]

        for p in shlex.split(value, posix=False):
            node = doxyfile_node.parent.find_node(p)

            if node is None:
                raise self.generator.bld.fatal('Path %r given in parameter %s not found' % (p, parameter))

            yield node.abspath()

    def run(self):
        env     = self.env
        inputs  = self.inputs
        outputs = self.outputs

        doxyfile_node                           = inputs[0]
        mangled_doxyfile_node, output_dir_node  = outputs[0:2]
        doxygen_output_nodes = outputs[2:]

        doxyfile_content = doxyfile_node.read()

        first = set()

        # parse doxyfile and fix paths
        for line in doxyfile_content.splitlines():
            lhs, _, _ = line.partition('#')

            m = re_match_doxysetting(lhs)

            if m:
                parameter, operator, value = m.group('parameter', 'operator', 'value')

                if value.strip():
                    if parameter in self.path_parameter_names:

                        # enforce the first parameter occurence to be an '=' to clear all old settings
                        if parameter not in first:
                            operator = '='
                            first.add(parameter)

                        paths = list(self.translate_paths(parameter, value))
                        doxyfile_content += '\n%s %s %s\n' % (parameter, operator, ' '.join('"%s"' % x for x in paths))

        # enforce output directory
        doxyfile_content += '\nOUTPUT_DIRECTORY = "%s"\n' % output_dir_node.abspath()

        # enforce hhc enabled
        if env['HTMLHELPC']:
            doxyfile_content += '\nHHC_LOCATION = "%s"\n' % env['HTMLHELPC']

        # set plantuml if found
        if env['PLANTUML']:
            doxyfile_content += '\nPLANTUML_JAR_PATH = "%s"\n' % env['PLANTUML']

        mangled_doxyfile_node.parent.mkdir()
        mangled_doxyfile_node.write(doxyfile_content)

        env.stash()
        try:
            for x in doxygen_output_nodes:
                x.parent.mkdir()

            self.inputs = [mangled_doxyfile_node]
            self.run_doxygen()
        finally:
            self.inputs = inputs
            env.revert()


pattern_doxygen_input = """
   *.c *.cc *.cxx *.cpp *.c++ *.h *.hh *.hxx *.hpp *.h++
   *.java *.ii *.ixx *.ipp *.i++ *.inl
   *.idl *.ddl *.odl
   *.cs *.d *.php *.php4 *.php5 *.phtml *.inc
   *.m *.markdown *.md *.mm *.dox *.py *.pyw
   *.f90 *.f95 *.f03 *.f08
   *.f *.for *.tcl *.vhd *.vhdl
   *.ucf *.qsf""".split()


@conf
def parse_doxyfile(bld, doxyfile_node, base_path):
    doxyfile_content = doxyfile_node.read()

    doxygen_params = {
        'OUTPUT_DIRECTORY' : base_path.path_from(doxyfile_node)
    }

    for line in doxyfile_content.splitlines():
        lhs, _, _ = line.partition('#')

        m = re_match_doxysetting(lhs)

        if m:
            parameter, operator, value = m.group('parameter', 'operator', 'value')
            doxygen_params[parameter] = value

    return doxygen_params

@feature('doxygen')
def process_source_doxygen(self):
    bld = self.bld

    doxyfile_nodes = [self.find_resource(x) for x in self.source_doxygen]

    if not self.env['DOXYGEN']:
        bld.fatal(u'Doxygen not available')

    targets_doxygen = self.targets_doxygen = []

    for doxyfile_node in doxyfile_nodes:
        # Dont create a new task if we already have a generator
        if hasattr(doxyfile_node, '_doxygen_output_nodes'):
            targets_doxygen.extend(doxyfile_node._doxygen_output_nodes)
            continue

        doxygen_input_nodes  = []

        # parse doxyfile
        doxygen_params = bld.parse_doxyfile(doxyfile_node, base_path = self.path)

        input = doxygen_params.pop('INPUT')
        for x in shlex.split(input, posix=False):
            n = doxyfile_node.parent.find_node(x)

            if n is None:
                self.file_error(u'Doxygen include path %r not found' % x, doxyfile_node)

            doxygen_input_nodes.append(n)

        # build-dir must be declared before output_dir_node (Don't ask me why)
        build_dir_node = bld.root.make_node(bld.out_dir).make_node('Documentation')

        output_dir_node = doxyfile_node.parent.make_node(doxygen_params['OUTPUT_DIRECTORY'])

        doxygen_output_nodes = get_doxygen_outputs(doxyfile_node, doxygen_params)

        # Lets check if another documentation command was issued with same
        # output directory
        doxygen_output_dirs = bld._doxygen_output_dirs = getattr(bld,'_doxygen_output_dirs', {})

        for x in doxygen_output_nodes:
            if x in doxygen_output_dirs:
                self.file_error(u'doxygen output directory %r already defined in %r' %
                        (x.nice_path(), doxygen_output_dirs[x].nice_path()), doxyfile_node)

            doxygen_output_dirs[x] = doxyfile_node

        mangled_doxyfile_node = doxyfile_node.get_bld()

        if not output_dir_node.is_child_of(build_dir_node):
            self.warn(u'Doxygen output directory not below build/Documentation', doxyfile_node)

        # make a list of files which might regarded as input by doxygen
        patterns = list('**/%s' % x for x in pattern_doxygen_input)

        def get_file_list(x):
            if os.path.isdir(x.abspath()):
                return x.ant_glob(patterns)
            else:
                return [x]

        potential_source_nodes = sum((get_file_list(n) for n in doxygen_input_nodes),[])

        self.create_task('doxygen',
          [doxyfile_node] + potential_source_nodes,
          [mangled_doxyfile_node, output_dir_node] + doxygen_output_nodes,
        )

        doxyfile_node._doxygen_output_nodes = doxygen_output_nodes
        targets_doxygen.extend(doxygen_output_nodes)

@conf
def generate_doxygen_documentation(bld, doxyfile, **kw):
    doxyfile_node = bld.path.find_node(doxyfile)

    if not doxyfile_node:
        bld.fatal('Doxyfile %r not found' % doxyfile)

    if not bld.env['DOXYGEN']:
        return

    bld(features='doxygen',
        source_doxygen = [doxyfile_node],
        **kw
    )

    doxygen_params = bld.parse_doxyfile(doxyfile_node, base_path = bld.path)
    doxygen_output_nodes = get_doxygen_outputs(doxyfile_node, doxygen_params)

    if bld.is_install and ('install_path' in kw):
        bld.install_files(kw['install_path'], doxygen_output_nodes)

