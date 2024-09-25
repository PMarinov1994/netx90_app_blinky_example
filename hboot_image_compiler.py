from waflib import Task, Logs, Utils
from waflib.Context import STDOUT, BOTH
from waflib.Configure import conf

from waflib.TaskGen import feature, after_method

import os
import re

MIN_HBOOT_IMAGE_COMPILER_VERSION = (1, 0, 0)

def get_version_numbers(folder_name):
    # Define the regex pattern
    pattern = r'\A(?P<major>\d+)\.(?P<minor>\d+)\.(?P<patch>\d+).*'
    match = re.search(pattern, folder_name)
    if match:
        return tuple(map(int, match.groups()))
    else:
        return (0, 0, 0)  # Default version if regex doesn't match

def get_subfolders_sorted_by_version(folder_path):
    # Get all subfolders in the given folder
    subfolders = [os.path.join(folder_path, f) for f in os.listdir(folder_path) if os.path.isdir(os.path.join(folder_path, f))]

    # Sort subfolders based on version numbers extracted from folder names in descending order
    subfolders.sort(key=lambda x: get_version_numbers(os.path.basename(x).decode('utf-8')), reverse=True)

    return subfolders


def configure(conf):
    # Locate the BuildTools directory and add it to the env list
    conf.find_program("PATH_BUILDTOOLS", var="PATH_BUILDTOOLS")
    
    buildToolsFolder = conf.env['PATH_BUILDTOOLS']
    hboot_compiler_folder = "%shboot_image_compiler" % buildToolsFolder
    
    sorted_comp_versions_dirs = get_subfolders_sorted_by_version(hboot_compiler_folder)
    
    # Check if there is a folder with version 1.0.0 or greater
    if not any(get_version_numbers(os.path.basename(x).decode('utf-8')) >= MIN_HBOOT_IMAGE_COMPILER_VERSION for x in sorted_comp_versions_dirs):
        conf.fatal("HBOOT_IMAGE_COMPILER version v%s.%s.%s or greater is required!\nProcessed folders: %s"
                        % (MIN_HBOOT_IMAGE_COMPILER_VERSION[0], MIN_HBOOT_IMAGE_COMPILER_VERSION[1], MIN_HBOOT_IMAGE_COMPILER_VERSION[2], sorted_comp_versions_dirs))

    conf.msg("Checking for program hboot_image_compiler", sorted_comp_versions_dirs[0])

    conf.env['HBOOT_COMPILER_APP'] = '"%s/hboot_image_compiler_app/hboot_image_compiler_app"' % (sorted_comp_versions_dirs[0])
    conf.env['HBOOT_COMPILER_COM'] = '"%s/hboot_image_compiler_com/hboot_image_compiler_com"' % (sorted_comp_versions_dirs[0])

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
def firmware(bld, *k, **kw):
    target = kw.pop('target', None)
    name   = kw.pop('name', target)

    # generate unique, identifiers for intermediate build product "elf file"

    # the target name (the name of the elf file) will be generate from base name
    # of the firmware to build (everything up to the file extension). The extension
    # '.elf' will be automatically append by bld.program below
    prog_target, fmw_extension = os.path.splitext(target)

    # The name of the elf file generator is just the name of the firmware file generator
    # prefixed with an underscore
    prog_name = '_' + name

    # Build ELF file
    bld.program(
        name   = prog_name,
        target = prog_target,
        **kw
    )
    
    features = Utils.to_list(kw.pop('features', []) + ['hboot_image_compiler_exe'])

    kw_firmware = {}
    kw_firmware['platform']               = kw.pop('platform', None)
    kw_firmware['hboot_xml']              = kw.pop('hboot_xml', None)
    kw_firmware['netx_type']              = kw.pop('netx_type', None)
    kw_firmware['segments_intflash']      = kw.pop('segments_intflash', None)
    kw_firmware['segments_extflash']      = kw.pop('segments_extflash', None)
    kw_firmware['headeraddress_extflash'] = kw.pop('headeraddress_extflash', None)
    kw_firmware['sdram_split_offset']     = kw.pop('sdram_split_offset', None)

    bld(
        target        = target,
        use           = prog_name,
        name          = name,
        features      = features,
        fmw_extension = fmw_extension,
        **kw_firmware
    )


@feature('hboot_image_compiler_exe')
def hboot_compiler_task(self):

    elf_inputs = []
    for dep in self.to_list(getattr(self, 'use', None)):
        dep_target = self.bld.get_tgen_by_name(dep)        
        elf_inputs.append(dep_target.link_task.outputs[0])

    # #######################################
    # Build the command line
    # #######################################
    commandName = None
    commandArgs = []
    if self.fmw_extension == ".nai":
        commandName = "HBOOT_COMPILER_APP"
        commandArgs = generate_application_cmd_params(self, self.name, elf_inputs[0].abspath())
    elif self.fmw_extension == ".nxi":
        commandName = "HBOOT_COMPILER_COM"
        commandArgs = generate_communication_cmd_params(self, self.name, elf_inputs[0].abspath())
    else:
        self.bld.fatal(u"Unexpected firmware extension '%s'. Only .nai and .nxi are supported!" % self.fmw_extension)

    output_nodes = list( x.parent.find_or_declare('%s' % os.path.splitext(x.name)[0] + self.fmw_extension) for x in elf_inputs)

    hboot_task = self.hboot_task = self.create_task(
        'hboot_image_compiler_exe',
        elf_inputs,
        output_nodes,
    )

    hboot_task.commandName = commandName
    hboot_task.commandArgs = commandArgs



class hboot_image_compiler_exe(Task.Task):
    u''' Run the hboot_image_compiler for the application or communication, based on the target extension '''

    color     = 'PINK'
    inst_to   = None
    cmdline   = None
    log_str   = '[HBOOT_COMPILER] $TARGETS'
    
    def run(self):
        env = self.env

        arrCmd = [env.get_flat(self.commandName)] + self.commandArgs
        strCmd = ' '.join(arrCmd)

        null_output = open(os.devnull, 'w')
        return self.exec_command(
            strCmd,
            stdout = null_output,
            stderr = STDOUT,
        )

def generate_application_cmd_params(self, targetName, elf_path):

    args = []
    args.append('--alias=tElf="%s"' % elf_path)
    
    netx_type = getattr(self, 'netx_type', None)
    
    if netx_type is None:
        self.bld.fatal(u'Parameter "netx_type" not defined for target %r' % targetName)
        
    args.append("-nt")
    args.append(netx_type)
    
    # nai support
    segments_intflash      = getattr(self, 'segments_intflash', None)
    segments_extflash      = getattr(self, 'segments_extflash', None)
    headeraddress_extflash = getattr(self, 'headeraddress_extflash', None)
    sdram_split_offset     = getattr(self, 'sdram_split_offset', None)
    
    if segments_intflash is not None:
        segments_intflash = Utils.to_list(segments_intflash)[:]

        if not segments_intflash:
            self.bld.fatal(u'Empty argument segments_intflash specified for target %r' % targetName)

    if segments_extflash is not None:
        segments_extflash = Utils.to_list(segments_extflash)[:]

        if not segments_extflash:
            self.bld.fatal(u'Empty argument segments_extflash specified for target %r' % targetName)

        if not segments_intflash:
            self.bld.fatal(u'Empty argument segments_intflash while using extflash specified for target %r' % targetName)

    if sdram_split_offset is not None:
        if not isinstance(sdram_split_offset,int):
            self.bld.fatal(u'Argument sdram_split_offset for target %r must be a number' % targetName)

        if sdram_split_offset not in allowed_sdram_split_offset_values:
            self.bld.fatal(u'Argument sdram_split_offset for target %r set to unsupported value 0x%08x' % (targetName,sdram_split_offset))

    if headeraddress_extflash is not None:
        if not isinstance(headeraddress_extflash,int):
            self.bld.fatal(u'Argument headeraddress_extflash for target %r must be a number' % targetName)

    if ((segments_extflash is not None) != (sdram_split_offset is not None)) or ((segments_extflash is not None) != (headeraddress_extflash is not None)):
        self.bld.fatal(u'Either all or none of arguments segments_extflash,sdram_split_offset and headeraddress_extflash must be set for %r' % targetName)

    if segments_intflash is not None:
        args.append('--alias=segments_intflash=%s' % ','.join(segments_intflash))
    else:
        args.append('--alias=segments_intflash=""')

    if segments_extflash is not None:
        args.append('--alias=segments_extflash=%s' % ','.join(segments_extflash))
        
    if sdram_split_offset is not None:
        args.append('--sdram_split_offset=0x%x' % sdram_split_offset)
        
    if headeraddress_extflash is not None:
        args.append('--alias=headeraddress_extflash=0x%x' % headeraddress_extflash)
        
        
    binaryPath, elfExtension = os.path.splitext(elf_path)
    
    # If we do not want to override the original ELF file
    # args.append("--output-elf-file")
    # args.append('"%s_patched%s"' % (binaryPath, elfExtension))
    
    if segments_extflash is not None:
        args.append("-t")
        args.append("nae")
        args.append('"%s.nai"' % binaryPath)
        args.append('"%s.nae"' % binaryPath)
    else:
        args.append("-t")
        args.append("nai")
        args.append('"%s.nai"' % binaryPath)

    return args


def generate_communication_cmd_params(self, targetName, elf_path):
    args = []
    
    # add ELF file alias
    args.append('--alias=tElf0="%s"' % elf_path)
    
    # handle netX type
    netx_type_platform = getattr(self, 'platform', None)    
    if netx_type_platform is None:
        self.bld.fatal(u'Parameter "platform" not defined for target %r' % targetName)

    args.append("--netx-type-public=%s" % netx_type_platform)
    
    # add patched ELF file output    
    binaryPath, elfExtension = os.path.splitext(elf_path)
    
    # If we do not want to override the original ELF file
    # args.append("--output-elf-file")
    # args.append('"%s_patched%s"' % (binaryPath, elfExtension))
    
    # handle TOP LEVEL XML files
    hboot_xmls = self.to_list(self.hboot_xml)
    if len(hboot_xmls) not in (1,2):
        self.bld.fatal('Unexpected number of HBoot xml description files defined (expected one or two xml files) for target "%s"' % targetName)
    
    hboot_xml_nodes = list(self.path.find_resource(resource) for resource in hboot_xmls)

    for x, y in zip(hboot_xml_nodes, hboot_xmls):
        if not x:
            self.bld.fatal('HBoot xml description file "%s" not found for target "%s"' % (self.path.nice_path() + os.path.sep + y, targetName))

    # add --include
    args.append('--include="%s"' % hboot_xml_nodes[0].parent.abspath())

    # add first top level XML
    args.append('"%s"' % hboot_xml_nodes[0].abspath())
    
    # check for second top level XML (split image)
    if len(hboot_xml_nodes) == 2:
        args.append('"%s"' % hboot_xml_nodes[1].abspath())
    
    # add primary output
    args.append('"%s.nxi"' % binaryPath)
    
    # add secondary output if available
    if len(hboot_xml_nodes) == 2:
        args.append('"%s.nxe"' % binaryPath)
        
    return args



import Build
Build.BuildContext.hboot_img_compiler = firmware