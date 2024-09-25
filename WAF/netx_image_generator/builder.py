#! /usr/bin/env python
# encoding: utf-8
# Copyright (c) Hilscher Gesellschaft fuer Systemautomation mbH. All Rights Reserved.
# ***************************************************************************************
# $Id:  $:
#
# Description:
#
import io
from struct import unpack_from, pack
from netx_image_generator.elf import Elffile
from waflib.Context import STDOUT, BOTH
from waflib import Logs

from hilscher_netx import aboot_header_elements, aboot_magiccookie, aboot_signature

def make_array32(*args):
    u''' Make an array of 32 bit unsigned integers '''

    import array

    # build mapping from bytesize to typecode
    array_typecode_by_size = dict((array.array(t).itemsize,t) for t in 'BHIL')

    return array.array(array_typecode_by_size[4], *args)

def generate_commonheader_md5_checksum(filedata, header_offset = 0):
    import hashlib

    header_offset_words = header_offset / 4

    offset_aboot_header_checksum = aboot_header_elements['BootChksm']
    offset_aboot_appl_checksum   = aboot_header_elements['AppChksm']
    offset_common_header_md5     = 21
    offset_common_header_crc32   = 31

    # Set default header checksum to zero
    filedata[header_offset_words + offset_aboot_header_checksum] = 0
    filedata[header_offset_words + offset_aboot_appl_checksum]   = 0

    # Set md5 checksum to zero
    filedata[header_offset_words + offset_common_header_md5]     = 0
    filedata[header_offset_words + offset_common_header_md5 + 1] = 0
    filedata[header_offset_words + offset_common_header_md5 + 2] = 0
    filedata[header_offset_words + offset_common_header_md5 + 3] = 0

    # set common header checkusm to zero
    filedata[header_offset_words + offset_common_header_crc32]   = 0

    # Calculate file MD5
    m = hashlib.md5()
    m.update(filedata[header_offset_words:])
    file_md5_string = m.digest()

    file_md5 = make_array32()
    file_md5.fromstring(file_md5_string)

    # patch in the md5 sum
    filedata[header_offset_words + offset_common_header_md5]     = file_md5[0]
    filedata[header_offset_words + offset_common_header_md5 + 1] = file_md5[1]
    filedata[header_offset_words + offset_common_header_md5 + 2] = file_md5[2]
    filedata[header_offset_words + offset_common_header_md5 + 3] = file_md5[3]

def generate_commonheader_headercrc32_checksum(filedata, header_offset = 0):
    import zlib

    header_offset_words = header_offset / 4

    offset_common_header_crc32   = 31

    # Calculate common header CRC32B
    header_crc32 = zlib.crc32(filedata[header_offset_words:header_offset_words+32]) & 0xffffffff

    filedata[header_offset_words + offset_common_header_crc32]   = header_crc32

def generate_commonheader_checksums(filedata, header_offset = 0):
    generate_commonheader_md5_checksum(filedata, header_offset)
    generate_commonheader_headercrc32_checksum(filedata, header_offset)

def generate_bootheader_headerchecksum(filedata, header_offset = 0):
    offset_aboot_header_checksum = aboot_header_elements['BootChksm']

    header_offset_words = header_offset / 4

    boot_chksum = 0
    for value in filedata[header_offset_words:header_offset_words+15]:
      boot_chksum += value
      boot_chksum &= 0xffffffff

    filedata[header_offset_words + offset_aboot_header_checksum] = (boot_chksum - 1) ^ 0xFFFFFFFF

def generate_bootheader_checksums(filedata, header_offset = 0):
    offset_aboot_appl_checksum   = aboot_header_elements['AppChksm']

    header_offset_words = header_offset / 4

    # Update application and bootheader checksum
    appl_chksum = 0
    for value in filedata[header_offset_words + 16:]:
      appl_chksum += value
      appl_chksum &= 0xffffffff

    filedata[header_offset_words + offset_aboot_appl_checksum] = appl_chksum
    generate_bootheader_headerchecksum(filedata, header_offset)


def nxupdate_fn(inputfilename, outputfilename):
    import hashlib, zlib

    # Get the application data.
    with open(inputfilename, 'rb') as fh:
        filedata = make_array32(fh.read())

    generate_commonheader_checksums(filedata)

   # Only update header checksum on .NXF files, which can be detected via
    # cookie and signature
    offset_cookie    = aboot_header_elements['MagCok']
    offset_signature = aboot_header_elements['Signt']

    if (filedata[offset_cookie] & 0xFFFFFF00) == aboot_magiccookie and filedata[offset_signature] == aboot_signature:
        generate_bootheader_checksums(filedata)
    else:
        Logs.debug('Skipping generation of bootheader checksums for %r' % outputfilename)

    with open(outputfilename, 'wb') as fh:
        filedata.tofile(fh)



def NxoBuilder(self, outputfile, firmware_elfname, header_elfname, taglist_elfname):

    cmd = [self.env.get_flat('STRIP'), firmware_elfname, '-g', '--strip-unneeded', '-o', firmware_elfname + '.stripped']
    result = self.generator.bld.cmd_and_log(cmd, output=STDOUT, quiet=STDOUT)

    fw_elf       = Elffile(firmware_elfname + '.stripped')
    fw_sections  = fw_elf.parse_sections()
    symbol_table = fw_sections['.symtab']
    success      = True

    # Check symbol table for undefined / common symbols which are not allowed in NXO's
    fw_symbols = fw_elf.parse_symbol_table(symbol_table, fw_sections['.strtab'] or None)

    # Sort sections by idx, so we can index them via st_shndx
    sections_byidx = [fw_sections[x] for x in sorted(fw_sections, key=lambda x : fw_sections[x].idx)]

    Logs.debug('nxo: Checking %u symbols for undefined references' % (len(fw_symbols) - 1))

    # First symbol is always undefined and can safely be ignored
    for symbol in fw_symbols[1:]:
      if symbol.st_shndx == Elffile.Elf32Section.SHN_UNDEF:
        # Found undefined symbol which is not allowed in NXO
        Logs.pprint('RED', 'ERROR: Found undefined symbol %r' % symbol.name)
        success = False
      elif symbol.st_shndx == Elffile.Elf32Section.SHN_COMMON:
        # Found COMMON symbol which is not allowed in NXO
        Logs.pprint('RED', 'ERROR: Found COMMON symbol %r' % symbol.name)
        success = False

    if success:
      # Check for unsupported relocation types
      Logs.debug('nxo: Checking for unsupported relocation types')
      log_relocationtypes = {}

      supported_relocations = [ Elffile.ARM32Relocations.R_ARM_NONE,
                                Elffile.ARM32Relocations.R_ARM_ABS32,
                                Elffile.ARM32Relocations.R_ARM_REL32,
                                Elffile.ARM32Relocations.R_ARM_CALL,
                                Elffile.ARM32Relocations.R_ARM_JUMP24,
                                Elffile.ARM32Relocations.R_ARM_V4BX,
                                Elffile.ARM32Relocations.R_ARM_PLT32,
                                Elffile.ARM32Relocations.R_ARM_PC24,
                                Elffile.ARM32Relocations.R_ARM_XPC25,
                                Elffile.ARM32Relocations.R_ARM_PREL31,
                                Elffile.ARM32Relocations.R_ARM_THM_CALL,
                                Elffile.ARM32Relocations.R_ARM_THM_JUMP24,
                                Elffile.ARM32Relocations.R_ARM_THM_XPC22,
                                Elffile.ARM32Relocations.R_ARM_THM_PC11,
                              ]

      for section_name in fw_sections:
        section = fw_sections[section_name]
        if section.sh_type == section.SHT_RELA:
          # Found COMMON symbol which is not allowed in NXO
          Logs.pprint('RED', 'ERROR: Found unsupported RELA relocation section %r' % section_name)
          success = False
        elif section.sh_type == section.SHT_REL:
          # Check REL section for supported relocation types
          relocs = section.parse_rel_section()
          for _reloc in relocs:
            ref_symbol = fw_symbols[_reloc.r_sym]

            _log_reloc_name = _reloc_name = Elffile.ARM32Relocations.get_name(_reloc.r_type)

            if (ref_symbol.st_info & 0xf) == ref_symbol.STT_SECTION:
              ref_symbol_name = sections_byidx[ref_symbol.st_shndx].name
            else:
              ref_symbol_name = ref_symbol.name

            if _reloc.r_sym > len(fw_symbols):
              # Invalid symbol reference in relocation
              Logs.pprint('RED', 'ERROR: Found relocation with invalid symbol reference %d in section %s at r_offset %#010x' % (_reloc.r_sym, section_name, _reloc.r_offset ))
              success = False
            elif _reloc.r_type not in supported_relocations:
              # Unsupported relocation
              Logs.pprint('RED', 'ERROR: Found unsupported relocation type %s in section %s for symbol %s' %
                          (_reloc_name,
                          section_name,
                          ref_symbol_name) )
              success = False
            else:
              # Check relocations for other unsupported stuff (e.g. unallowed ARM<-->Thumb transitions, which would need veneers)
              if _reloc.r_type in [ Elffile.ARM32Relocations.R_ARM_CALL,
                                    Elffile.ARM32Relocations.R_ARM_JUMP24,
                                    Elffile.ARM32Relocations.R_ARM_PLT32,
                                    Elffile.ARM32Relocations.R_ARM_PC24,
                                    Elffile.ARM32Relocations.R_ARM_XPC25,
                                  ]:
                # Check for unallowed transitions from ARM-->Thumb
                if ref_symbol.st_value & 1:
                  # Mark this as a ARM-->Thumb transition for the log
                  _log_reloc_name = _log_reloc_name + " (ARM->Thumb)"
              elif _reloc.r_type in [ Elffile.ARM32Relocations.R_ARM_THM_CALL,
                                      Elffile.ARM32Relocations.R_ARM_THM_JUMP24,
                                      Elffile.ARM32Relocations.R_ARM_THM_XPC22,
                                    ]:
                if (ref_symbol.st_value & 1) == 0:
                  # Mark this as a Thumb-->ARM transition for the log
                  _log_reloc_name = _log_reloc_name + " (Thumb-->ARM)"

            if not _log_reloc_name in log_relocationtypes:
              log_relocationtypes[_log_reloc_name] = 1
            else:
              log_relocationtypes[_log_reloc_name] = log_relocationtypes[_log_reloc_name] + 1

      Logs.debug('nxo: Following relocations have been checked:')
      for _tmp in log_relocationtypes:
          Logs.debug('nxo:   * %s (Count=%u)' % (_tmp, log_relocationtypes[_tmp]))

    if success:
      fileheader_data = ".NXO" + ('\0' * 60)

      # Create NXO file
      header_binname = header_elfname.change_ext('.bin')

      # Use Objcopy to generate binary file
      cmd = [self.env.get_flat('OBJCOPY'), '-O', 'binary', header_elfname.abspath(), header_binname.abspath()]
      result = self.generator.bld.cmd_and_log(cmd, output=STDOUT, quiet=STDOUT)

      tmp = io.open(header_binname.abspath(), "rb")
      fileheader_data += tmp.read()
      tmp.close()

      tmp = io.open(firmware_elfname + '.stripped', "rb")
      elf_data = tmp.read()
      tmp.close()

      taglist_data = None
      if taglist_elfname:
        # Check Taglist object file
        # It must not contain multiple data sections starting all at offset 0, which results in an unusable file produced by OBJCOPY
        taglist_elf       = Elffile(taglist_elfname.abspath())
        taglist_sections  = taglist_elf.parse_sections()

        # Dict offset -> section name, with sections being included in bin built by OBJCOPY
        _tagsections_in_image = {}

        for _section_name, _tag_section in taglist_sections.items():
          if (_tag_section.sh_size != 0) and (_tag_section.sh_flags & _tag_section.SHF_ALLOC):
            Logs.debug('nxo: Checking section %r at memory offset %#010x' % (_section_name, _tag_section.sh_addr))
            if _tag_section.sh_addr in _tagsections_in_image:
              Logs.pprint('RED', 'ERROR: Taglist contains overlapping sections %r and %r at offset %#010x. Make sure to only provide a single instance for the taglist structure!' % (_section_name, _tagsections_in_image[_tag_section.sh_addr],  _tag_section.sh_addr))
              return False
            else:
              _tagsections_in_image[_tag_section.sh_addr] = _section_name

        taglist_binname = taglist_elfname.change_ext('.bin')
        cmd = [self.env.get_flat('OBJCOPY'), '-O', 'binary', taglist_elfname.abspath(), taglist_binname.abspath()]
        result = self.generator.bld.cmd_and_log(cmd, output=STDOUT, quiet=STDOUT)

        tmp = io.open(taglist_binname.abspath(), "rb")
        taglist_data = tmp.read()
        tmp.close()

        # Append EndOfList Marker, if it does not exist yet. Some firmwares rely on the linker (taglist.ld)
        # to add the missing 64 Bit zeros, but as we extract the taglist from an object the EOL is missing
        # in this case
        _offset   = 0
        _eolfound = False

        while _offset < len(taglist_data):
          _tagtype   = unpack_from("<L", taglist_data, _offset)[0]
          _taglength = unpack_from("<L", taglist_data, _offset + 4)[0]

          _eolfound = False
          if (_tagtype is 0) and (_taglength is 0):
            _eolfound = True

          _offset += 8 + _taglength

          # new tags always start at DWORD aligned offsets
          if (_taglength % 4) != 0:
            _offset += 4 - _taglength % 4

        if not _eolfound:
          Logs.pprint('YELLOW', "[NXO] '%s': Adding missing END_OF_LIST marker to taglist" % outputfile)
          taglist_data += pack("<Q", 0)

      offset_common_header_data_size    = 72
      offset_common_header_data_offs    = 76
      offset_common_header_taglist_size = 100
      offset_common_header_taglist_offs = 104
      offset_common_header_taglist_size_max = 108

      # Modify Common Header to include correct data and tag list size / offset
      fileheader_data = fileheader_data[:offset_common_header_data_size] + pack("<L", len(elf_data)) + fileheader_data[offset_common_header_data_size+4:]
      fileheader_data = fileheader_data[:offset_common_header_data_offs] + pack("<L", len(fileheader_data)) + fileheader_data[offset_common_header_data_offs+4:]
      if taglist_data:
        fileheader_data = fileheader_data[:offset_common_header_taglist_size] + pack("<L", len(taglist_data)) + fileheader_data[offset_common_header_taglist_size+4:]
        fileheader_data = fileheader_data[:offset_common_header_taglist_size_max] + pack("<L", len(taglist_data)) + fileheader_data[offset_common_header_taglist_size_max+4:]
        fileheader_data = fileheader_data[:offset_common_header_taglist_offs] + pack("<L", len(fileheader_data) + len(elf_data)) + fileheader_data[offset_common_header_taglist_offs+4:]

      nxo_file = io.open(outputfile, "wb")
      nxo_file.write(fileheader_data + elf_data)
      if taglist_data:
        nxo_file.write(taglist_data)
      size = nxo_file.tell()

      if size % 4:
        success = False
        Logs.pprint('RED', "ERROR: [NXO] '%s': Resulting filesize is not a multiple of UINT32 (size=%r)" % (outputfile, size))

      nxo_file.close()

      if success:
        # Update NXO checksums
        nxupdate_fn(outputfile, outputfile)

    return success
