#! /usr/bin/env python
# encoding: utf-8

from waflib import Task, Utils
from waflib.Errors import WafError
from waflib.Configure import conf
from waflib.TaskGen import feature, after_method, before_method, taskgen_method
from waflib.Context import STDOUT, BOTH
from waflib import Logs
import re
import os.path
from netx_image_generator.builder     import NxoBuilder, nxupdate_fn,\
                                             generate_bootheader_checksums,\
                                             generate_commonheader_checksums,\
                                             generate_commonheader_md5_checksum,\
                                             generate_commonheader_headercrc32_checksum, \
                                             generate_bootheader_headerchecksum,\
                                             make_array32

hilscher_waf_dir = os.path.abspath(os.path.dirname(__file__))

# waf buildsystem related hooks to initialize this module
def options(opt):
    global hilscher_waf_dir
    opt.load('hilscher_libsused', tooldir = [ hilscher_waf_dir ] )

def configure(conf):
    global hilscher_waf_dir
    conf.load('hilscher_libsused', tooldir = [ hilscher_waf_dir ] )

def display_findings(bld):
    findings = bld.findings

    separatorline = '{0:=^80}'.format

    if findings:
        Logs.warn(separatorline(' Findings '))

        for node in sorted(findings, key= lambda x : x.nice_path()):
            title = '%s' % (node.nice_path())

            Logs.warn(title)
            Logs.warn('-' * len(title))

            for msg in sorted(findings[node]):
                Logs.warn('- %s' % msg)

            Logs.warn('')

        Logs.warn(separatorline(''))

@taskgen_method
def report_finding(self, node, msg):
  bld = self.bld

  if display_findings not in getattr(bld, 'post_funs', []):
      bld.findings = {}
      bld.add_post_fun(display_findings)

  try:
      bld.findings[node].add(msg)
  except KeyError:
      bld.findings[node] = set([msg])


''' ------------------------------------------
   NXO/Loadable Module
   ------------------------------------------ '''
@feature('remove_librcx')
@after_method('apply_link', 'process_use')
def process_removelibrcx(self):
  # features are also applied to Objects, so we will receive
  # a call for thumb_objs / arm_objs which don't have link task
  if not getattr(self, 'link_task', None):
      return

  tmp_list = list(self.link_task.env['STLIB'])
  for lib_to_remove in tmp_list:
      # find archives the name starts with 'rcx'
      # do not remove 'rcx_module*' and 'rcx_netxNNN_2portswitch'
      m = re.match('rcx(_(vol|bas|mid|midshm|hif_cifx|netx\d+(_physhif|_hif)?))?$', lib_to_remove)
      if m:
          # remove and warn, because there is a wrong use-component in wscript for this target
          Logs.pprint('YELLOW', "Warning: use-component '{0}' removed from build of target '{1}'".format(lib_to_remove, self.name))
          self.link_task.env['STLIB'].remove(lib_to_remove)

@conf
def module(bld, target, fileheader_source, platform = None, toolchain = None,**kw):

  kw['target']    = target
  kw['platform']  = platform
  kw['toolchain'] = toolchain

  bld.handle_toolchain(kw)

  description      = kw.pop('description', '')
  use              = kw.pop('use',        [])
  source           = kw.pop('source',     [])
  source_arm       = kw.pop('source_arm', [])

  kw.pop('target', None)
  name = kw.pop('name', target)

  tempelf_target = bld.path.find_or_declare(target)
  tempelf_target = str(tempelf_target.change_ext(''))
  tempelf_name   = target + '.nxo'

  install_path = kw.pop('install_path', None)

  features_program = Utils.to_list(kw.pop('features', [])) + ['remove_libc', 'remove_librcx', 'buildstamp']
  features_nxo     = []

  if 'libsused' in features_program:
      features_program.remove('libsused')
      features_nxo = ['libsused']

  # programm
  bld.program(
          target      = tempelf_target,
          name        = tempelf_name,
          features    = features_program,
          source      = source,
          source_arm  = source_arm,
          use         = use,
          linkflags   = Utils.to_list(kw.pop('linkflags', [])) + ['-Wl,-r'],
          hidden_from_list = "Internal",
          **kw)

  nxo_sources = Utils.to_list(fileheader_source) + Utils.to_list(kw.get('taglist_source', []))

  bld(features      = features_nxo + ['c', 'nxo'],
      source        = nxo_sources,
      target        = target,
      name          = name,
      moduleelf     = tempelf_name,
      fileheader_source = fileheader_source,
      use           = Utils.to_list(use),
      description   = description,
      install_path  = install_path,
      **kw)

@feature('nxo')
@after_method('apply_link', 'process_source')
def build_nxo(self):
    '''
    Function to build a netX loadable module.
    '''
    if not getattr(self, 'use', None):
      self.bld.fatal("Building a NXO requires 'use' parameter")

    inputs =  [None,None,None]
    outputs = [self.path.find_or_declare(self.target)]

    # Search our elf file to convert
    try:
        tg = self.bld.get_tgen_by_name(self.moduleelf)
        # is already posted
        if not getattr(tg,'posted',None):
          tg.post()
    except self.bld.errors.WafError:
        Logs.pprint('YELLOW',"Skipping nxo-file \'%s\' because no matching tgen found. (Probably the source elf was not build because of missing toolchain)" % (target))
        return

    if getattr(tg, 'link_task', None):
      # Only use .elf files as inputs
      for x in tg.link_task.outputs:
          if x.suffix().lower() == '.elf':
              inputs[0] = x
    else:
        self.bld.fatal('Input tgen has no link task')

    fileheader_node = self.path.find_node(self.fileheader_source)

    if getattr(self, 'taglist_source', None):
        taglist_node = self.path.find_node(self.taglist_source)
    else:
        taglist_node = none

    for x in self.compiled_tasks:
        if (x.inputs[0] == fileheader_node):
            inputs[1] = x.outputs[0]
        elif (x.inputs[0] == taglist_node):
            inputs[2] = x.outputs[0]

    # create task and adapt its env
    self.nxobuilder_task = self.create_task('NxoBuilderTask', inputs,outputs)
    self.nxobuilder_task.env  = tg.env.derive()

    if getattr(self, 'install_path', None):
        self.bld.install_files(getattr(self, 'install_path', None), self.nxobuilder_task.outputs[0])

class NxoBuilderTask(Task.Task):
    color   = 'PINK'
    cmdline = None
    inst_to = None

    def run(self):
        inputfile  = self.inputs[0].abspath()
        outputfile = self.outputs[0].get_bld().abspath()
        fileheader = self.inputs[1]
        taglist    = self.inputs[2]

        if not NxoBuilder(self, outputfile, inputfile, fileheader, taglist):
          self.generator.bld.fatal("NXO building failed")

''' ------------------------------------------
   Firmware
   ------------------------------------------ '''
@conf
def firmware(bld, target, linkerscript, platform, toolchain,**kw):
  """
  Function to build a firmware (nxf/nxo[todo]) from sources and libraries.
  <b>  Mandatory parameters  </b>
  @param target    \b string: file name of the target (e.g. netX.nxf)
  @param platform  \b string: type of platform, that specified compiler parameter set. Values: \n\e netx - common parameters for all netx platforms \n\e netx500 - parameters specific for netX500 \n\e netx100 - parameters specific for netX100 \n\e netx50  - parameters specific for netX50 \n\e netx51  - parameters specific for netX51 \n\e netx10  - parameters specific for netX10
  @param toolchain \b string: identification of toolchain to use in build. \n For example: \e 'hitex' or \e 'codesourcery'. See 'hilscher_toolchains.py' for more toolchains or define therein a new one. \n
  @param linkerscript \b string: linker script
  @param BOOTBLOCKERFLAGS <b> list of strings: </b>parameters for bootblocker
  \n\n\n
  <b> Optional parameters: </b>\n\n
  @param description \b string: description of this target, will be listed in "waf list"
  @param sources       <b> list of strings: </b> list of source files (*.c/*.s) in absolute or relative path, that compiler translates in 'thumb' mode
  @param sources_thumb <b> list of strings: </b> (equivalent to \e sources) list of source files (*.c/*.s) in absolute or relative path, that compiler translates in 'thumb' mode
  @param sources_arm   <b> list of strings: </b> list of source files (*.c/*.s) in absolute or relative path, that compiler translates in 'arm' mode
  @param includes <b> list of strings: </b> list of include directories to include in build of source files
  @param use <b> list of strings: </b> list of libraries to use in compile stage (their 'export_defines' and 'export_includes' are used for build too)
  @param defines <b> list of strings: </b> list of define directives to use in build of source files
  \n\n\n
  <b> Additional parameters for compiler, assembler and linker: </b>\n\n
  @param stlib <b> list of strings: </b> used static libraries
  @param stlibpath <b> list of strings: </b> path to static libraries
  @param linkflags <b> list of strings: </b> options, forwarded to the linker
  @param cflags    <b> list of strings: </b> options, forwarded to the C-Compiler
  @param cxxflags  <b> list of strings: </b> options, forwarded to the C++-Compiler
  \n\n\n
  <b> Installation: </b>\n\n
  @param install_path \b string:  (relative) path to install current component while "waf install"
  \n\n\n
  """
  # mandatory parameters
  kw['target']           = target
  kw['platform']         = platform
  kw['toolchain']        = toolchain
  kw['linkerscript']     = linkerscript

  bld.handle_toolchain(kw)

  install_path     = kw.pop('install_path', None)
  BOOTBLOCKERFLAGS = kw.pop('BOOTBLOCKERFLAGS', None)
  hboot_xml        = kw.pop('hboot_xml', None)
  netx_type        = kw.pop('netx_type', None)

  # nai support
  segments_intflash      = kw.pop('segments_intflash', None)
  segments_extflash      = kw.pop('segments_extflash', None)
  headeraddress_extflash = kw.pop('headeraddress_extflash', None)
  sdram_split_offset     = kw.pop('sdram_split_offset', None)

  tgt = bld.path.find_or_declare(target)

  kw.pop('target', None)
  name = kw.pop('name', target)

  # generate unique, identifiers for intermediate build product "elf file"

  # the target name (the name of the elf file) will be generate from base name
  # of the firmware to build (everything up to the file extension). The extension
  # '.elf' will be automatically append by bld.program below
  prog_target, _ = os.path.splitext(target)

  # The name of the elf file generator is just the name of the firmware file generator
  # prefixed with an underscore
  prog_name = '_' + name

  features = Utils.to_list(kw.pop('features', []))
  features_program  = list(set(features) | set(['buildstamp']))
  features_firmware = []

  # extract firmware kind if defined
  kind = None
  if 'nxi' in features_program:
      kind = 'nxi'
      features_program.remove('nxi')
  if 'mxf' in features_program:
      kind = 'mxf'
      features_program.remove('nxi')
  if 'nxf' in features_program:
      kind = 'nxf'
      features_program.remove('nxf')
  if 'nai' in features_program:
      kind = 'nai'
      features_program.remove('nai')

  if 'libsused' in features_program:
      features_program.remove('libsused')
      features_firmware.append('libsused')

  # generate the elf file
  bld._program_internal(target           = prog_target,
                        name             = prog_name,
                        install_path     = [],
                        hidden_from_list = "Internal",
                        features         = features_program,
                        **kw)

  # check kind of firmware to build
  if kind is None:
      _, ext = os.path.splitext(target)

      kind = {
          '.nxi' : 'nxi',
          '.mxf' : 'mxf',
          '.nai' : 'nai',
      }.get(ext.lower(), 'nxf')

  kw_fw = {}
  kw_fw['description']  = kw.get('description', u' ')
  kw_fw['displaygroup'] = kw.get('displaygroup', u'default')
  kw_fw['version']      = kw.get('version', None)
  kw_fw['install_path'] = install_path

  if kind == 'nxf':
      if BOOTBLOCKERFLAGS is None:
          bld.fatal(u'Parameter "BOOTBLOCKERFLAGS" not defined for target %r' % name)

      # generate .nxf from elf file
      buildnxf(bld,
               target           = target,
               name             = name,
               use              = prog_name,
               features         = features_firmware,
               BOOTBLOCKERFLAGS = BOOTBLOCKERFLAGS,
               **kw_fw)
  elif kind in ('nxi', 'mxf'):
      features_firmware.append(kind)

      if hboot_xml is None:
          bld.fatal(u'Parameter "hboot_xml" not defined for target %r' % name)

      if netx_type is None:
          bld.fatal(u'Parameter "netx_type" not defined for target %r' % name)

      # generate .nxi / .nxe from elf file
      bld.generate_hboot_image(
               target           = target,
               name             = name,
               use              = prog_name,
               netx_type        = netx_type,
               hboot_xml        = hboot_xml,
               features         = features_firmware,
               **kw_fw)
  elif kind == 'nai':
      if netx_type is None:
          bld.fatal(u'Parameter "netx_type" not defined for target %r' % name)

      # generate .nai from elf file
      bld.generate_netx90_app_image(
               target           = target,
               name             = name,
               use              = prog_name,
               netx_type        = netx_type,
               features         = features_firmware,
               segments_intflash      = segments_intflash,
               segments_extflash      = segments_extflash,
               headeraddress_extflash = headeraddress_extflash,
               sdram_split_offset     = sdram_split_offset,
               **kw_fw)

hboot_python_version = None

@conf
def check_python_version_for_hboot(bld):
    global hboot_python_version

    if hboot_python_version is None:
        #check python version
        hboot_python_version = bld.cmd_and_log([bld.env.get_flat('PYTHON'), '-c', 'import sys; sys.stdout.write(str(tuple(sys.version_info)))'], quiet=BOTH)
        hboot_python_version = eval(hboot_python_version, {})

        if hboot_python_version[0:3] < (2,7,9):
            Logs.pprint('YELLOW', "Warning: hboot tools might not work with python version %d.%d.%d" % (hboot_python_version[0],hboot_python_version[1], hboot_python_version[2]))

@conf
def generate_hboot_image(bld, target, netx_type, hboot_xml, use, **kw):
    """
    """
    bld.check_python_version_for_hboot()

    features = Utils.to_list(kw.pop('features', [])) + ['hboot']
    bld(target = target,
        features = features,
        netx_type = netx_type,
        hboot_xml = hboot_xml, use=use, **kw)

allowed_sdram_split_offset_values = (
    0, # No split
    0x00400000, # Enable Split for 8 MB SDRAM
    0x00800000, # Enable Split for 16 MB SDRAM
    0x01000000, # Enable Split for 32 MB SDRAM
    0x02000000, # Enable Split for 64 MB SDRAM
    0x04000000, # Enable Split for 128 MB SDRAM
    0x08000000, # Enable Split for 256 MB SDRAM
)

@conf
def generate_netx90_app_image(bld, target, netx_type, use,
                              segments_intflash = None, segments_extflash = None,
                              headeraddress_extflash = None,
                              sdram_split_offset = None, **kw):
    u""" build an nai/nae flash image to contain the application
         firmware """

    global allowed_sdram_split_offset_values

    bld.check_python_version_for_hboot()

    name = target

    features = Utils.to_list(kw.pop('features', [])) + ['netx90_app_image']

    if segments_intflash is not None:
        segments_intflash = Utils.to_list(segments_intflash)[:]

        if not segments_intflash:
            bld.fatal(u'Empty argument segments_intflash specified for target %r' % name)

    if segments_extflash is not None:
        segments_extflash = Utils.to_list(segments_extflash)[:]

        if not segments_extflash:
            bld.fatal(u'Empty argument segments_extflash specified for target %r' % name)

        if not segments_intflash:
            bld.fatal(u'Empty argument segments_intflash while using extflash specified for target %r' % name)

    if sdram_split_offset is not None:
        if not isinstance(sdram_split_offset,int):
            bld.fatal(u'Argument sdram_split_offset for target %r must be a number' % (name))

        if sdram_split_offset not in allowed_sdram_split_offset_values:
            bld.fatal(u'Argument sdram_split_offset for target %r set to unsupported value 0x%08x' % (name,sdram_split_offset))

    if headeraddress_extflash is not None:
        if not isinstance(headeraddress_extflash,int):
            bld.fatal(u'Argument headeraddress_extflash for target %r must be a number' % (name))

    if ((segments_extflash is not None) != (sdram_split_offset is not None)) or\
       ((segments_extflash is not None) != (headeraddress_extflash is not None)):
        bld.fatal(u'Either all or none of arguments segments_extflash,sdram_split_offset and headeraddress_extflash must be set for %r' % name)

    bld(target = target,
        features = features,
        netx_type = netx_type,
        segments_intflash      = segments_intflash,
        segments_extflash      = segments_extflash,
        headeraddress_extflash = headeraddress_extflash,
        sdram_split_offset     = sdram_split_offset,
        use=use, **kw)


@conf
def generate_netx90_intflash2_image(bld, target, use, **kw):
  u""" build an application image for application flash 2 for netx90.
       The image must be compiled with proper linkerscript in order to be usefull
  """

  features = Utils.to_list(kw.pop('features', [])) + ['nx90_intflash2_image']
  bld(target = target,
      features = features,
      use=use, **kw)

''' ------------------------------------------
   NXF Update support
   ------------------------------------------ '''
@conf
def buildnxf(bld, target, *k, **kw):
    """
    Function to build a firmware (nxf) from executable (elf).
    <b>  Mandatory parameters  </b>
    @param target    \b string: file name of firmware
    @param use <b> list of strings: </b> target, from binary will be constructed
    @param BOOTBLOCKERFLAGS <b> list of strings: </b>parameters for bootblocker
    \n\n\n
    <b> Optional parameters: </b>\n\n
    @param description \b string: description of this target, will be listed in "waf list"
    \n\n\n
    <b> Installation: </b>\n\n
    @param install_path \b string:  (relative) path to install current component while "waf install"
    \n\n\n
    """
    if (not 'BOOTBLOCKERFLAGS' in kw) and (not 'BOOTBLOCKERDATA' in kw):
        bld.fatal("Bootblocker flags are missing")

    kw['target']    = target
    kw['name_patch']= '~'+target+'.bin'
    if not 'name' in kw:
      kw['name']    = target

    features = Utils.to_list(kw.pop('features', [])) + ['bootimage', 'nxf']

    bld(features = features, **kw)

class nxupdate(Task.Task):
    ''' Run objcopy on the target'''
    color     = 'PINK'
    inst_to   = None
    cmdline   = None

    def run(self):
      inputfile   = self.inputs[0].get_bld().abspath()
      outputfile  = self.outputs[0].get_bld().abspath()
      nxupdate_fn(inputfile, outputfile)

@feature('nxf')
@after_method('build_bootimage')
def build_nxf(self):
    '''
    Function to build a netX bootable image by performing an OBJCOPY and
    prepending a netX bootheader (64 byte).
    '''
    target = self.path.find_or_declare(self.target)
    #target = self.path.make_node(self.name)

    input = self.to_list(getattr(self, 'use', None))

    self.nxf_task = self.create_task('nxupdate')

    #target = self.path.find_or_declare(self.name_real)

    self.nxf_task.outputs     = [target]

    self.nxf_task.inputs.extend(self.bootblocker_task.outputs)
    self.nxf_task.set_run_after(self.bootblocker_task)

    if getattr(self, 'install_path', None):
      self.bld.install_files(getattr(self, 'install_path', None), self.nxf_task.outputs)
""" HELPER functions """

class hboot(Task.Task):
    ''' Run objcopy on the target'''
    color     = 'PINK'
    inst_to   = None
    cmdline   = None
    log_str   = '[HBOOT] $TARGETS'

    def run(self):
        tgen = self.generator
        bld = tgen.bld

        env = self.env

        cmd = [env.get_flat('PYTHON'), env.get_flat('HBOOT_IMAGE_COMPILER'), '--verbose']

        if not all(bool(x) for x in cmd):
            bld.fatal('Either Python or HBOOT image compiler not available')

        hboot_xml, patch_table_node = self.inputs[0:2]
        elf_inputs  = self.inputs[2:]

        # build hboot compiler commandline
        cmd.append('--include=%s'   % hboot_xml.parent.abspath())
        cmd.append('--netx-type=%s' % tgen.netx_type)
        cmd.append('--objdump=%s'   % env.get_flat('OBJDUMP'))
        cmd.append('--objcopy=%s'   % env.get_flat('OBJCOPY'))
        cmd.append('--readelf=%s'   % env.get_flat('READELF'))


        cmd.append('--patch-table=%s' % patch_table_node.abspath())

        sniplib_node = getattr(self,'sniplib_node', None)
        if sniplib_node is not None:
            cmd.append('--sniplib=%s'   % sniplib_node.abspath())

        for i,x in enumerate(elf_inputs):
            cmd.append('--alias=tElf%d=%s' % (i, x.abspath()))

        cmd.append(hboot_xml.abspath())
        cmd.append(self.outputs[0].abspath())

        # run boot image creator
        dct = dict(os.environ)
        dct['LANG']='C'

        out,err = bld.cmd_and_log(cmd, env = dct, output=BOTH, quiet=STDOUT)

        # hboot_image_compiler -v --netx-type 4000 --objcopy %GCC_ARM_PATH%/bin/arm-none-eabi-objcopy --objdump %GCC_ARM_PATH%/bin/arm-none-eabi-objdump --readelf %GCC_ARM_PATH%/bin/arm-none-eabi-readelf --alias tElfCR7=netx4000.elf CR7_DDR600.xml CR7_DDR600.bin

default_hboot_patch_tables = {
  'NETX56'          : 'hboot_netx56_patch_table.xml',
  'NETX90'          : 'hboot_netx90_patch_table.xml',
  'NETX90B'         : 'hboot_netx90b_patch_table.xml',
  'NETX90_MPW'      : 'hboot_netx90_mpw_patch_table.xml',
  'NETX4000_RELAXED': 'hboot_netx4000_relaxed_patch_table.xml',
  'NETX4000'        : 'hboot_netx4000_patch_table.xml',
  'NETX4100'        : 'hboot_netx4000_patch_table.xml',
}

@feature('hboot')
@after_method('check_tgen_availability')
def build_hboot(self):
    '''
    Function to build a netX bootable image by performing an OBJCOPY and
    prepending a netX bootheader (64 byte).
    '''
    bld    = self.bld
    target = self.path.find_or_declare(self.target)

    hboot_xmls      = self.to_list(self.hboot_xml)

    if len(hboot_xmls) not in (1,2):
        bld.fatal('Unexpected number of HBoot xml description files defined (expected one or two xml files)')

    hboot_xml_nodes = list(self.path.find_resource(x) for x in hboot_xmls)

    for x,y in zip(hboot_xml_nodes, hboot_xmls):
        if not x:
            bld.fatal('HBoot xml description file "%s" not found' % (self.path.nice_path() + os.path.sep + y))

    elf_inputs = []
    platform   = ''
    toolchain  = getattr(self,'toolchain','')

    for x in self.to_list(getattr(self, 'use', None)):
        t = bld.get_tgen_by_name(x)

        platform  = platform or  t.platform.lower()
        toolchain = toolchain or t.toolchain.lower()

        if toolchain != t.toolchain:
            bld.fatal('HBoot toolchain of all source elfs must be identical')

        if platform != t.platform:
            bld.fatal('HBoot platforms of all source elfs must be identical')

        if not getattr(t, 'posted', None):
            t.post()

        elf_inputs.append(t.link_task.outputs[0])

    if self.netx_type not in default_hboot_patch_tables:
        bld.fatal('Unsupported netx type %s when building hboot image' % self.netx_type)

    self.platform  = platform
    self.toolchain = toolchain

    # setup environment according to toolchain of use references
    self.env = self.bld.all_envs['toolchain_%s' % toolchain].derive()

    patch_table_path = self.env.get_flat('HBOOT_IMAGE_COMPILER') +\
                           '/../patch_tables/%s' % default_hboot_patch_tables[self.netx_type]

    patch_table_node = bld.root.find_node(patch_table_path)

    if not patch_table_node:
        bld.fatal('Patch table %r not found' % patch_table_path)

    # build the nxi file
    hboot_task_nxi = self.hboot_task_nxi = self.create_task('hboot',
        [hboot_xml_nodes[0], patch_table_node] + elf_inputs, [target])

    # register nxi for distribution
    self.dist_nodes = hboot_task_nxi.outputs[:]

    # build nxe file if required
    if len(hboot_xml_nodes) > 1:
        hboot_task_nxe = self.hboot_task_nxe = self.create_task('hboot',
            [hboot_xml_nodes[1], patch_table_node] + elf_inputs, [target.change_ext('.nxe')])

        # register nxe for distribution
        self.dist_nodes.extend(hboot_task_nxe.outputs)
    else:
        hboot_task_nxe = None

    sniplib_node = None
    sniplib = getattr(self,'sniplib', None)

    if sniplib is not None:
        if isinstance(sniplib, bld.node_class):
            sniplib_node = sniplib
        else:
            sniplib_node = self.path.find_dir(sniplib)

        if sniplib_node is None:
            bld.fatal('Sniplib not found in %r' % sniplib)

        if not os.path.isdir(sniplib_node.abspath()):
            bld.fatal('Sniplib not found in %r' % sniplib)

        hboot_task_nxi.sniplib_node = sniplib_node

        if hboot_task_nxe is not None:
            hboot_task_nxe.sniplib_node = sniplib_node

    if getattr(self, 'install_path', None):
        self.bld.install_files(getattr(self, 'install_path', None), self.dist_nodes)

class HilscherTask(Task.Task):
    def unlink_if_exists(self, node_or_path):
        if not isinstance(node_or_path, str):
            node_or_path = node_or_path.abspath()

        if os.path.exists(node_or_path):
            os.unlink(node_or_path)

    def generate_commoncrc(self, filedata_iflash, filedata_eflash, offset_header_iflash = 0, offset_header_eflash = 0):
        import zlib

        offset_commonheader_md5       = (64 + 20) / 4
        offset_commonheader_commoncrc = (64 + 48) / 4

        offset_header_iflash_words = offset_header_iflash / 4
        offset_header_eflash_words = offset_header_eflash / 4

        concat_md5 = filedata_iflash[offset_header_iflash_words+offset_commonheader_md5:offset_header_iflash_words+offset_commonheader_md5+4] +\
                     filedata_eflash[offset_header_eflash_words+offset_commonheader_md5:offset_header_eflash_words+offset_commonheader_md5+4]

        # Calculate common header common CRC32
        commoncrc = zlib.crc32(concat_md5) & 0xffffffff

        filedata_iflash[offset_header_iflash_words + offset_commonheader_commoncrc] = commoncrc
        filedata_eflash[offset_header_eflash_words + offset_commonheader_commoncrc] = commoncrc


class generate_nxi(HilscherTask):
    u''' Generate NXI file from hboot image'''
    color     = 'PINK'
    inst_to   = None
    cmdline   = None

    def get_nxi_hboot_headers(self, firmware_data):
        import struct

        boot_header = struct.unpack('<16L', firmware_data[0:64])

        # validate hboot content in header area
        if boot_header[0]  != 0x50494b53:
            raise ValueError(u'First chunk of hboot image for nxi file must be a skip chunk')

        if boot_header[1]  == 0x0000000B:
            # we expect a data chunk
            if boot_header[13] != 0x41544144:
                raise ValueError(u'Second chunk of hboot image for nxi file must be a data or XIP chunk')

            #extract max header data length from hboot chunk
            max_header_data_length = 64 + (boot_header[14]-1) * 4
        elif boot_header[1]  == 0x0000000C:
            # we expect a text chunk
            if boot_header[14] != 0x54584554:
                raise ValueError(u'Second chunk of hboot image for nxi file must be a data or XIP chunk')

            #extract max header data length from hboot chunk
            max_header_data_length = 64 + (boot_header[15]) * 4
        else:
            raise ValueError(u'Bad length of first chunk')

        common_header = struct.unpack('<%dL' % ((max_header_data_length - 64)/4),
                                      firmware_data[64:max_header_data_length])

        if common_header[0] != 0x00030000:
            raise ValueError(u'Unexpected header version of common header')

        if common_header[1] >= max_header_data_length:
            raise ValueError(u'Unexpected header length of common header')

        return boot_header, common_header

    def patch_nxi_header(self, boot_header, common_header, length_nxi):
        import struct

        header_length = (len(boot_header) + len(common_header)) * 4

        HIL_FILE_HEADER_NXI_COOKIE, = struct.unpack('<L', ".NXI")
        HIL_FILE_HEADER_MXF_COOKIE, = struct.unpack('<L', ".MXF")

        if "mxf" in self.generator.features:
            boot_header[0]    = HIL_FILE_HEADER_MXF_COOKIE
        else:
            boot_header[0]    = HIL_FILE_HEADER_NXI_COOKIE

        boot_header[1:16] = [0] * 15
        boot_header[4]    = (length_nxi - 64) / 4
        boot_header[6]    = struct.unpack('<L', "NETX")[0]

        common_header[2]  = length_nxi - header_length
        common_header[3]  = header_length

    def dwords_to_bytes(self, dwords):
        import struct
        return struct.pack('<%dL' % len(dwords), *(dwords))

    def run(self):
        import struct
        tgen = self.generator
        netx_type = tgen.netx_type

        inputfile   = self.inputs[0].get_bld().abspath()
        outputfile  = self.outputs[0].get_bld().abspath()

        self.unlink_if_exists(outputfile)

        with open(inputfile, 'rb') as fh:
            firmware_data = fh.read()

        boot_header, common_header = self.get_nxi_hboot_headers(firmware_data)

        # patch binary hboot image to contain valid header structures
        boot_header = list(boot_header)
        common_header = list(common_header)

        self.patch_nxi_header(boot_header, common_header, len(firmware_data))

        header = self.dwords_to_bytes(boot_header + common_header)
        filedata = make_array32(header + firmware_data[len(header):])

        generate_commonheader_checksums(filedata)
        generate_bootheader_checksums(filedata)

        with open(outputfile, 'wb') as fh:
            fh.write(filedata.tostring())

class generate_nxi_nxe(generate_nxi):
    u'''Generate NXI/NXE file from hboot image'''
    color     = 'PINK'
    inst_to   = None
    cmdline   = None

    def patch_nxe_header(self, boot_header, common_header, length_nxe):
        import struct

        self.patch_nxi_header(boot_header, common_header, length_nxe)

        HIL_FILE_HEADER_NXE_COOKIE, = struct.unpack('<L', ".NXE")

        boot_header[0]    = HIL_FILE_HEADER_NXE_COOKIE

        # clear taglist information
        common_header[36 / 4] = 0
        common_header[40 / 4] = 0
        common_header[44 / 4] = 0

    header_length_nxe = 384

    def check_hboot_nxe(self, hboot_data_nxe):
        import struct

        hboot_header      = struct.unpack_from('<8L', hboot_data_nxe)

        # print list("0x{:08x}".format(x) for x in hboot_header)

        ulFlashOffsetBytes = hboot_header[2]
        ulFlashSelection   = hboot_header[5]

        if (ulFlashSelection & 0xFFFFFF00 ) != 0x00000100:
            raise ValueError( (u'Hboot image for nxe does not look like external SQI flash hboot image:\n'
                               u'Bad value 0x{:08x} of field ulFlashSelection.\n'
                               u'Please check NXE hboot xml to have \'<HBootImage ...  >\n'
                               u'                                       <Header set_flasher_parameters="true" />\n'
                               u'                                       <Chunks>\n'
                               u'                                       ...\'\n'
                              ).format(ulFlashSelection))

        if ulFlashOffsetBytes != self.header_length_nxe:
            raise ValueError( (u'Invalid hboot offset 0x{:x} found.\n'
                               u'Please check NXE hboot xml to have \'<HBootImage ... offset="0x{:x}" >\''
                              ).format(ulFlashOffsetBytes, self.header_length_nxe))


    def run(self):
        import struct
        tgen = self.generator
        netx_type = tgen.netx_type

        inputfile_nxi   = self.inputs[0].get_bld().abspath()
        outputfile_nxi  = self.outputs[0].get_bld().abspath()

        inputfile_nxe   = self.inputs[1].get_bld().abspath()
        outputfile_nxe  = self.outputs[1].get_bld().abspath()

        self.unlink_if_exists(outputfile_nxi)
        self.unlink_if_exists(outputfile_nxe)

        with open(inputfile_nxi, 'rb') as fh:
            firmware_data_nxi = fh.read()

        with open(inputfile_nxe, 'rb') as fh:
            hboot_data_nxe    = fh.read()

        boot_header, common_header = self.get_nxi_hboot_headers(firmware_data_nxi)

        # patch binary hboot image to contain valid header structures
        boot_header   = list(boot_header)
        common_header = list(common_header)

        self.patch_nxi_header(boot_header, common_header, len(firmware_data_nxi))

        header_nxi   = self.dwords_to_bytes(boot_header + common_header)
        filedata_nxi = make_array32(header_nxi + firmware_data_nxi[len(header_nxi):])

        header_nxe   = self.dwords_to_bytes(boot_header + common_header)

        self.check_hboot_nxe(hboot_data_nxe)

        # according to definition, header length is fixed
        common_header = common_header[0:(self.header_length_nxe-64) / 4]

        self.patch_nxe_header(boot_header, common_header, self.header_length_nxe + len(hboot_data_nxe))

        header_nxe   = self.dwords_to_bytes(boot_header + common_header)
        filedata_nxe = make_array32(header_nxe + hboot_data_nxe)

        generate_commonheader_md5_checksum(filedata_nxi)
        generate_commonheader_md5_checksum(filedata_nxe)

        self.generate_commoncrc(filedata_nxi, filedata_nxe)

        generate_commonheader_headercrc32_checksum(filedata_nxi)
        generate_commonheader_headercrc32_checksum(filedata_nxe)

        generate_bootheader_checksums(filedata_nxi)
        generate_bootheader_checksums(filedata_nxe)

        with open(outputfile_nxi, 'wb') as fh_nxi:
            with open(outputfile_nxe, 'wb') as fh_nxe:
                fh_nxi.write(filedata_nxi.tostring())
                fh_nxe.write(filedata_nxe.tostring())


@feature('nxi', 'mxf')
@after_method('build_hboot')
def build_nxi_mxf(self):
    u''' Inject a new task which will patch the hboot image to become a
         nxi/nxe/mxf file. '''
    hboot_task_nxi = self.hboot_task_nxi
    hboot_task_nxe = getattr(self, "hboot_task_nxe", None)

    # inject new name for intermediate hboot name
    target_nxi     = hboot_task_nxi.outputs[0]
    hboot_node_nxi = target_nxi.parent.find_or_declare('_%s.hboot' % target_nxi.name)
    hboot_task_nxi.outputs = [hboot_node_nxi]

    if hboot_task_nxe is not None:
        target_nxe     = hboot_task_nxe.outputs[0]
        hboot_node_nxe = target_nxe.parent.find_or_declare('_%s.hboot' % target_nxe.name)
        hboot_task_nxe.outputs = [hboot_node_nxe]

        self.nxi_task = self.create_task('generate_nxi_nxe',
            [hboot_node_nxi, hboot_node_nxe], [target_nxi, target_nxe])
    else:
        self.nxi_task = self.create_task('generate_nxi',
            [hboot_node_nxi], [target_nxi])


class netx90_app_image(Task.Task):
    u''' Build application image for netX90'''
    color     = 'PINK'
    inst_to   = None
    cmdline   = None
    log_str   = '[APPIMG] $TARGETS'

    def run(self):
        tgen = self.generator
        bld = tgen.bld

        env = self.env

        cmd = [env.get_flat('PYTHON'), env.get_flat('HBOOT_APP_IMAGE'), '--verbose']

        if not all(bool(x) for x in cmd):
            bld.fatal('Either Python or app image compiler not available')

        app_image_xml = self.inputs[0]
        elf_inputs    = self.inputs[1:]

        def append_segment_alias(alias, value):
            arg = '--alias=%s=' % alias

            if value is not None:
                if len(value) > 0:
                    cmd.append(arg + ','.join(value))
                else:
                    cmd.append(arg + ',')
            else:
                cmd.append(arg)

        # build app image compiler commandline
        cmd.append('--netx-type=%s' % tgen.netx_type)
        cmd.append('--objdump=%s'   % env.get_flat('OBJDUMP'))
        cmd.append('--objcopy=%s'   % env.get_flat('OBJCOPY'))
        cmd.append('--readelf=%s'   % env.get_flat('READELF'))

        if tgen.sdram_split_offset is not None:
            cmd.append('--sdram_split_offset=0x%x' % tgen.sdram_split_offset)

        append_segment_alias('segments_intflash', tgen.segments_intflash)
        append_segment_alias('segments_extflash', tgen.segments_extflash)

        if tgen.headeraddress_extflash is not None:
            cmd.append('--alias=headeraddress_extflash=0x%x' % tgen.headeraddress_extflash)

        for i,x in enumerate(elf_inputs):
            cmd.append('--alias=tElf%d=%s' % (i, x.abspath()))

        cmd.append(app_image_xml.abspath())

        for x in self.outputs:
            cmd.append(x.abspath())

        # run app image creator
        dct = dict(os.environ)
        dct['LANG']='C'

        out,err = bld.cmd_and_log(cmd, env = dct, output=BOTH, quiet=STDOUT)

def generate_netx90_bootheader_checksums(filedata_iflash, filedata_eflash = None):
    u''' Update the checksum in the netx90 app side bootheader of nai image'''
    import hashlib

    offset_boot_header       = 448
    offset_boot_header_words = offset_boot_header / 4

    h = hashlib.sha384()

    h.update(filedata_iflash[0:112])
    h.update(filedata_iflash[128:])

    if filedata_eflash is not None:
        h.update(filedata_eflash)

    hash_value = make_array32(h.digest())

    # Write the first 7 DWORDs of the hash to the HBOOT header.
    filedata_iflash[offset_boot_header_words + 8: offset_boot_header_words + 15] = hash_value[0:7]

    generate_bootheader_headerchecksum(filedata_iflash, offset_boot_header)

class generate_nai(HilscherTask):
    u''' Generate NAI file from app image'''
    color     = 'PINK'
    inst_to   = None
    cmdline   = None

    @property
    def targets_pretty(self):
        return ", ".join(x.name for x in self.outputs)

    nai_offset_fh3_boot_header   = 512
    nai_offset_fh3_common_header = nai_offset_fh3_boot_header + 64

    def get_nai_file_headers(self, firmware_data):
        import struct

        default_header   = make_array32(firmware_data[self.nai_offset_fh3_boot_header:self.nai_offset_fh3_boot_header+64])

        HIL_FILE_HEADER_NAI_COOKIE, = struct.unpack('<L', ".NAI")
        HIL_FILE_HEADER_NETX_SIGNATURE, = struct.unpack('<L', "NETX")

        if default_header[0] != HIL_FILE_HEADER_NAI_COOKIE:
            raise ValueError(u'Unexpected cookie in default header for NAI image when building %s' % self.targets_pretty)

        if default_header[6] != HIL_FILE_HEADER_NETX_SIGNATURE:
            raise ValueError(u'Unexpected signature in default header for NAI image when building %s' % self.targets_pretty)

        common_header = make_array32( firmware_data[self.nai_offset_fh3_common_header:self.nai_offset_fh3_common_header+64])

        if common_header[0] != 0x00030000:
            raise ValueError(u'Unexpected header version of common header for NAI when building %s' % self.targets_pretty)

        if common_header[3] != 704:
            raise ValueError(u'Unexpected value %d in field ulDataStartOffset of common file header for NAE when building %s. (Should be 704)' % (common_header[3], self.targets_pretty))

        return default_header, common_header

    def patch_nai_header(self, default_header, common_header, length_nai):
        default_header[4]  = (length_nai - self.nai_offset_fh3_common_header) / 4
        # Set FHv3 Common Header ulDataSize field according file size & ulDataStartOffset
        common_header[2]   = (length_nai - common_header[3])

    def run(self):
        import struct
        tgen = self.generator

        inputfile   = self.inputs[0].get_bld().abspath()
        outputfile  = self.outputs[0].get_bld().abspath()

        self.unlink_if_exists(outputfile)

        with open(inputfile, 'rb') as fh:
            firmware_data = fh.read()

        default_header, common_header = self.get_nai_file_headers(firmware_data)

        # patch binary hboot image to contain valid header structures
        self.patch_nai_header(default_header, common_header, len(firmware_data))

        header = make_array32(firmware_data[0:512]) + default_header + common_header

        filedata = header + make_array32(firmware_data[(len(header) * header.itemsize):])

        generate_commonheader_checksums(filedata, header_offset = 512)
        generate_bootheader_checksums(filedata  , header_offset = 512)
        generate_netx90_bootheader_checksums(filedata)

        with open(outputfile, 'wb') as fh:
            fh.write(filedata.tostring())

class generate_nai_nae(generate_nai):
    u''' Generate NAI/NAE file from app image'''
    color     = 'PINK'
    inst_to   = None
    cmdline   = None

    nae_offset_fh3_boot_header   = 64
    nae_offset_fh3_common_header = nae_offset_fh3_boot_header + 64

    def get_nae_file_headers(self, firmware_data):
        import struct

        default_header   = make_array32( firmware_data[self.nae_offset_fh3_boot_header:self.nae_offset_fh3_boot_header+64])

        HIL_FILE_HEADER_NAE_COOKIE,     = struct.unpack('<L', ".NAE")
        HIL_FILE_HEADER_NETX_SIGNATURE, = struct.unpack('<L', "NETX")

        if default_header[0] != HIL_FILE_HEADER_NAE_COOKIE:
            raise ValueError(u'Unexpected cookie in default header for NAE image when building %s' % self.targets_pretty)

        if default_header[6] != HIL_FILE_HEADER_NETX_SIGNATURE:
            raise ValueError(u'Unexpected signature in default header for NAE image when building %s' % self.targets_pretty)

        common_header = make_array32(firmware_data[self.nae_offset_fh3_common_header:self.nae_offset_fh3_common_header+64])

        if common_header[0] != 0x00030000:
            raise ValueError(u'Unexpected header version of common header for NAE image when building %s' % self.targets_pretty)

        if common_header[3] != 256:
            raise ValueError(u'Unexpected value %d in field ulDataStartOffset of common file header for NAE image when building %s. (Should be 256)' % (common_header[3], self.targets_pretty))

        return default_header, common_header

    def patch_nae_header(self, default_header, common_header, length_nae):
        default_header[4]  = (length_nae - self.nae_offset_fh3_common_header) / 4
        # Set FHv3 Common Header ulDataSize field according file size & ulDataStartOffset
        common_header[2]   = (length_nae - common_header[3])

    def run(self):
        import struct
        tgen = self.generator

        inputfile_nai_image  = self.inputs[0].get_bld().abspath()
        outputfile_nai       = self.outputs[0].get_bld().abspath()

        inputfile_nae_image  = self.inputs[1].get_bld().abspath()
        outputfile_nae       = self.outputs[1].get_bld().abspath()

        self.unlink_if_exists(outputfile_nai)
        self.unlink_if_exists(outputfile_nae)

        with open(inputfile_nai_image, 'rb') as fh:
            nai_data = fh.read()

        with open(inputfile_nae_image, 'rb') as fh:
            nae_data = fh.read()

        default_header_nai, common_header_nai = self.get_nai_file_headers(nai_data)
        default_header_nae, common_header_nae = self.get_nae_file_headers(nae_data)

        # patch binary hboot image to contain valid header structures
        self.patch_nai_header(default_header_nai, common_header_nai, len(nai_data))
        self.patch_nae_header(default_header_nae, common_header_nae, len(nae_data))

        header_nai   = make_array32(nai_data[0:512]) + default_header_nai + common_header_nai
        filedata_nai = header_nai + make_array32(nai_data[(len(header_nai) * header_nai.itemsize):])

        header_nae   = make_array32(nae_data[0:64])  + default_header_nae + common_header_nae
        filedata_nae = header_nae + make_array32(nae_data[(len(header_nae) * header_nae.itemsize):])

        generate_commonheader_md5_checksum(filedata_nai, header_offset = 512)
        generate_commonheader_md5_checksum(filedata_nae, header_offset =  64)

        self.generate_commoncrc(filedata_nai, filedata_nae, 512, 64)

        generate_commonheader_headercrc32_checksum(filedata_nai, header_offset = 512)
        generate_commonheader_headercrc32_checksum(filedata_nae, header_offset =  64)

        generate_bootheader_checksums(filedata_nai, header_offset = 512)
        generate_bootheader_checksums(filedata_nae, header_offset =  64)

        generate_netx90_bootheader_checksums(filedata_nai, filedata_nae)

        with open(outputfile_nai, 'wb') as fh:
            fh.write(filedata_nai.tostring())

        with open(outputfile_nae, 'wb') as fh:
            fh.write(filedata_nae.tostring())

module_path = os.path.dirname(os.path.abspath(__file__))

@feature('netx90_app_image')
@after_method('check_tgen_availability')
def build_netx90_app_image(self):
    bld    = self.bld

    # build list of target nodes (output files)
    target_nai_node = self.path.find_or_declare(self.target)
    target_nodes = [target_nai_node]

    if self.segments_extflash:
        target_nodes.append(target_nai_node.change_ext('.nae'))

    # locate pre-defined xml file
    app_image_xml_node = bld.root.find_resource(module_path + os.sep + 'netx90_app_image.xml')

    if app_image_xml_node is None:
        bld.fatal(u'APP image xml file %r not found in %r' %('netx90_app_image.xml', module_path) )

    elf_inputs = []
    platform   = ''
    toolchain  = getattr(self,'toolchain','')

    for x in self.to_list(getattr(self, 'use', None)):
        t = bld.get_tgen_by_name(x)

        platform  = platform or  t.platform.lower()
        toolchain = toolchain or t.toolchain.lower()

        if toolchain != t.toolchain:
            bld.fatal('Toolchain of all source elfs must be identical')

        if platform != t.platform:
            bld.fatal('Platforms of all source elfs must be identical')

        if not getattr(t, 'posted', None):
            tgen.post()

        elf_inputs.append(t.link_task.outputs[0])

    if self.netx_type not in ['netx90_rev0', 'netx90_rev1']:
        bld.fatal('Unsupported netx type %s when building app image' % self.netx_type)

    self.platform  = platform
    self.toolchain = toolchain

    # setup environment according to toolchain of use references
    self.env = self.bld.all_envs['toolchain_%s' % toolchain].derive()

    app_image_nodes = list( x.parent.find_or_declare('%s.unpatched' % x.name) for x in target_nodes)

    # build the app image file
    app_image_task = self.app_image_task = self.create_task('netx90_app_image',
        [app_image_xml_node] + elf_inputs, app_image_nodes)

    # patch & update the headers
    if len(target_nodes) == 1:
        nai_task = self.nai_task = self.create_task('generate_nai',
            app_image_nodes, target_nodes)

        # register app image files for distribution
        self.dist_nodes = nai_task.outputs[:]
    else:
        nai_nae_task = self.nai_nae_task = self.create_task('generate_nai_nae',
            app_image_nodes, target_nodes)

        # register app image files for distribution
        self.dist_nodes = nai_nae_task.outputs[:]

    if getattr(self, 'install_path', None):
        self.bld.install_files(getattr(self, 'install_path', None), self.dist_nodes)


class objcopy(Task.Task):
    u''' Run objcopy on a file'''
    color   = 'PINK'
    log_str = '[OBJCOPY] $SOURCES $TARGETS'
    run_str = '${OBJCOPY} -O binary ${SRC} ${TGT}'

class appflash_update(Task.Task):
    u''' Update application binary flash file'''
    color     = 'PINK'
    inst_to   = None
    cmdline   = None
    log_str   = '[APPFLASH] $TARGETS'


    def run(self):
        tgen = self.generator
        bld = tgen.bld

        env = self.env
        cmd = [env.get_flat('PYTHON'), env.get_flat('HBOOT_APPFLASH_IMAGE'), '--verbose']

        if not all(bool(x) for x in cmd):
            bld.fatal('Either Python or HBOOT image compiler not available')

        cmd.append(self.inputs[0].abspath())
        cmd.append(self.outputs[0].abspath())

        out,err = bld.cmd_and_log(cmd, output=BOTH, quiet=STDOUT)

@feature('nx90_intflash2_image')
@after_method('check_tgen_availability')
def build_nx90_intflash2_image(self):
    '''
    Function to build a netX 90 APP bootable image for flash 2.
    '''
    bld = self.bld
    target     = self.path.find_or_declare(self.target)

    target_tmp = target.parent.find_or_declare(target.name + '.tmp')

    elf_inputs = []
    platform   = ''
    toolchain  = ''

    for x in self.to_list(getattr(self, 'use', None)):
        t = bld.get_tgen_by_name(x)

        platform  = platform or  t.platform.lower()
        toolchain = toolchain or t.toolchain.lower()

        if toolchain != t.toolchain:
            bld.fatal('Toolchain of all source elfs must be identical')

        if platform != t.platform:
            bld.fatal('Platforms of all source elfs must be identical')

        if not getattr(t, 'posted', None):
            tgen.post()

        elf_inputs.append(t.link_task.outputs[0])

    self.objcopy_task = self.create_task('objcopy', elf_inputs ,[target_tmp])
    self.image_task   = self.create_task('appflash_update', [target_tmp], [target])

@conf
def SpecFWFileName(self, DeviceFamily, DeviceForm, netXType,
                   PrimaryProtocol, SecondaryProtocol, HWCompInd):
    """
    Function constructs the name of firmware according to document "Specification Firmware File Names" (revision 3, 2013-04-03) [H:\Manual netX Architecture\System\Firmware Names]

    @param DeviceFamily \b string: device family
    @param DeviceForm \b string: device form
    @param netXType \b string: netX type
    @param PrimaryProtocol \b string: primary protocol on stack
    @param SecondaryProtocol \b string: secondary protocol on stack
    @param HWCompInd \b string: hardware compatibility index
    @return  \b string: Firmware file name
    """
    #Table 3:
    device_family = {'netbrick'          :{None :'B0', '' :'B0',},
                     'cifx'              :{None :'C0', '' :'C0',},
                     'netdimm'           :{None :'D0', '' :'D0',},
                     'eu5c'              :{None :'E0', '' :'E0',},
                     'nethost'           :{'t100' :'FT'},
                     'netsmart'          :{None :'G0', '' :'G0',},
                     'nethmi'            :{'j500' :'HJ', 'b500' :'HB',},
                     'netic'             :{None :'I0', '' :'I0',},
                     'netjack'           :{None :'J0', '' :'J0',},
                     'netlink'           :{'usb':'LU', 'ethernet':'LN'},
                     'comx'              :{None :'M0', '' :'M0',},
                     'netpac'            :{None :'P0', '' :'P0',},
                     'netrapid'          :{None :'R0', '' :'R0',},
                     'netplc'            :{'c100':'SC', 'd100':'SD', 'j100':'SJ', 'j500':'SJ', 'm100':'SM', 't100':'ST'},
                     'nettap'            :{None :'T0', '' :'T0',},
                     'netx'              :{None :'X0', '' :'X0',},
                     'rcx'               :{None :'X0', '' :'X0',},
                     'rcx base firmware' :{None :'X0', '' :'X0',},
                    }
    #Table 3, remark:
    file_extention = ".nxf"
    if DeviceFamily.lower() in ['rcx', 'rcx base firmware']:
        file_extention = ".nxo"
    # Table 4:
    netx_type    =  {'netx5'   : '4',
                     'netx6'   : '8',
                     'netx10'  : '5',
                     'netx50'  : '3',
                     'netx51'  : '6',
                     'netx52'  : '7',
                     'netx100' : '2',
                     'netx500' : '1',
                    }
    #Table 5:
    protocol_table = { None                                   : '00',
                ''                                      : '00',
                'rcx'                                   : '00',
                'profibus-dp master'                    : '01',
                'profibus dp master'                    : '01',
                'profibus-dp slave'                     : '02',
                'profibus dp slave'                     : '02',
                'profibus-mpi'                          : '03',
                'profibus mpi'                          : '03',
                'canopen master'                        : '04',
                'canopen slave'                         : '05',
                'devicenet master'                      : '06',
                'devicenet slave'                       : '07',
                'as-interface master'                   : '08',
                'cc-link slave'                         : '09',
                'componet slave'                        : '0A',
                'io-link master'                        : '0B',
                'profinet io controller'                : '0C',
                'pnm'                                   : '0C',
                'profinet io device'                    : '0D',
                'pns'                                   : '0D',
                'ethercat master'                       : '0E',
                'ecm'                                   : '0E',
                'ethercat slave'                        : '0F',
                'ecs'                                   : '0F',
                'ethernet/ip scanner/master'            : '0G',
                'ethernet/ip adapter/slave'             : '0H',
                'sercos iii master'                     : '0I',
                's3m'                                   : '0I',
                'sercos iii slave'                      : '0J',
                's3s'                                   : '0J',
                'powerlink controlled node'             : '0K',
                'open modbus/tcp'                       : '0L',
                'rfc 1006'                              : '0M',
                'df1'                                   : '0N',
                '3964r'                                 : '0P',
                'ascii'                                 : '0Q',
                'modbus rtu (master/slave)'             : '0R',
                'modbus rtu'                            : '0R',
                'netscript (programmable serial)'       : '0S',
                'netscript'                             : '0S',
                'varan client (server)'                 : '0T',
                'varan client'                          : '0T',
                'varan server'                          : '0T',
                'varan'                                 : '0T',
                'smartwire-dt master'                   : '0U',
                'marshaller'                            : '0V',
                'atvise (ethernet)'                     : '10',
                'atvise'                                : '10',
                'profibus-dp master and codesys'        : '11',
                'profibus dp master and codesys'        : '11',
                'devicenet master and codesys'          : '16',
                'profinet io controller and codesys'    : '1C',
                'pnm and codesys'                       : '1C',
                'ethernet/ip scanner/master and codesys': '1G',
                'eip and codesys'                       : '1G',
                'codesys and local i/o'                 : '1Z',
                'profibus-dp master and proconos eclr'  : '21',
                'profibus dp master and proconos eclr'  : '21',
                'canopen master and proconos eclr'      : '24',
                'devicenet master and proconos eclr'    : '26',
                'proconos eclr and local i/o'           : '2Z',
                'profibus-dp master and ibh s7'         : '31',
                'profibus dp master and ibh s7'         : '31',
                'canopen master and ibh s7'             : '34',
                'devicenet master and ibh s7'           : '36',
                'ibh s7 and local i/o'                  : '3Z',
                }

    def get_protocol_id(protocol):
        ltd = False

        if isinstance(protocol, str):
            protocol = protocol.lower()

            if protocol.endswith(" limited"):
                protocol = protocol[:-8]
                ltd = True

            id = protocol_table[protocol]
        else:
            id = protocol_table[protocol]

        if ltd:
            if id[0] == '0':
                id = 'Z' + id[1:]
            else:
                self.fatal("Can not generate limited firmware name for protocol {protocol}".format(**locals()))

        return id

    error_msg = "error: wrong parameter specified in \"SpecFWFileName\" on argument "
    out = ''
    # 1st letter
    try:
        loc_device_form = device_family[DeviceFamily.lower()]
    except KeyError:
        self.fatal(error_msg + "\"DeviceFamily = %s\"" % DeviceFamily)
    # 2nd letter
    try:
        if DeviceForm:
            DeviceForm = DeviceForm.lower()
        out = loc_device_form[ DeviceForm ]
    except KeyError:
        self.fatal(error_msg + "\"DeviceForm = %s\". Available \"DeviceForm\": %s" % (DeviceForm, ', '.join([str(var) for var,value in loc_device_form.iteritems()]) ) )
    #3rd letter
    try:
        out += netx_type[ netXType.replace(' ','').lower() ]
    except KeyError:
        self.fatal(error_msg + "\"netXType = %s\"" % netXType)
    #4th and 5th letters
    try:
        out += get_protocol_id (PrimaryProtocol)
    except KeyError:
        self.fatal(error_msg + "\"PrimaryProtocol = %s\"" % PrimaryProtocol)
    #6th and 7th letters
    try:
        out += get_protocol_id (SecondaryProtocol)
    except KeyError:
        self.fatal(error_msg + "\"SecondaryProtocol = %s\"" % SecondaryProtocol)
    #8th letter and firmware extention
    out += str(HWCompInd) + file_extention

    return out
