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

class Elffile:
  ELF_MAGIC           = "\x7FELF"

  FILE_OFFS_IDENT      = 0

  EI_CLASS             = 4
  ELFCLASSNONE         = 0
  ELFCLASS32           = 1
  ELFCLASS64           = 2

  EI_DATA              = 5
  ELFDATANONE          = 0
  ELFDATA2LSB          = 1  # Little-Endian
  ELFDATA2MSB          = 2  # Big-Endian

  EI_VERSION           = 6
  EV_NONE              = 0
  EV_CURRENT           = 1

  FILE_OFFS_TYPE      = 16
  ET_NONE             = 0
  ET_REL              = 1
  ET_EXEC             = 2
  ET_DYN              = 3

  FILE_OFFS_MACHINE   = 18
  EM_ARM              = 40

  FILE_OFFS_VERSION   = 20
  FILE_OFFS_ENTRY     = 24
  FILE_OFFS_PHOFF     = 28
  FILE_OFFS_SHOFF     = 32
  FILE_OFFS_FLAGS     = 36
  FILE_OFFS_EHSIZE    = 40
  FILE_OFFS_PHENTSIZE = 42
  FILE_OFFS_PHNUM     = 44
  FILE_OFFS_SHENTSIZE = 46
  FILE_OFFS_SHNUM     = 48
  FILE_OFFS_SHSTRNDX  = 50

  class Elf32Rel:
    def __init__(self):
      pass

  class Elf32Section:
    OFFS_SH_NAME      = 0
    OFFS_SH_TYPE      = 4
    OFFS_SH_FLAGS     = 8
    OFFS_SH_ADDR      = 12
    OFFS_SH_OFFSET    = 16
    OFFS_SH_SIZE      = 20
    OFFS_SH_LINK      = 24
    OFFS_SH_INFO      = 28
    OFFS_SH_ADDRALIGN = 32
    OFFS_SH_ENTSIZE   = 36

    SHT_NULL          = 0
    SHT_PROGBITS      = 1
    SHT_SYMTAB        = 2
    SHT_STRTAB        = 3
    SHT_RELA          = 4
    SHT_HASH          = 5
    SHT_DYNAMIC       = 6
    SHT_NOTE          = 7
    SHT_NOBITS        = 8
    SHT_REL           = 9
    SHT_SHLIB         = 10
    SHT_DYNSYM        = 11

    SHF_WRITE         = 1
    SHF_ALLOC         = 2
    SHF_EXECINSTR     = 4

    SHN_UNDEF         = 0
    SHN_LORESERVE     = 0xff00
    SHN_LOPROC        = 0xff00
    SHN_HIPROC        = 0xff1f
    SHN_ABS           = 0xfff1
    SHN_COMMON        = 0xfff2
    SHN_HIRESERVE     = 0xffff

    def __init__(self):
      pass

    def parse_rel_section(self):
      ret = []

      if self.sh_type == self.SHT_REL:
        for _relidx in range(0, self.sh_size, self.sh_entsize):
          rel = Elffile.Elf32Rel()
          rel.r_offset = unpack_from("<L", self.data, _relidx)[0]
          rel.r_info   = unpack_from("<L", self.data, _relidx + 4)[0]
          rel.r_sym    = rel.r_info >> 8
          rel.r_type   = rel.r_info & 0xFF
          ret.append(rel)

      return ret


  class Elf32Sym:
    OFFS_ST_NAME    = 0
    OFFS_ST_VALUE   = 4
    OFFS_ST_SIZE    = 8
    OFFS_ST_INFO    = 12
    OFFS_ST_OTHER   = 13
    OFFS_ST_SHNDX   = 14

    ST_SIZE         = 16

    STT_NOTYPE      = 0
    STT_OBJECT      = 1
    STT_FUNC        = 2
    STT_SECTION     = 3
    STT_FILE        = 4
    STT_LOPROC      = 13
    STT_HIPROC      = 15

    STB_LOCAL       = 0
    STB_GLOBAL      = 2
    STB_WEAK        = 3
    STB_LOPROC      = 13
    STB_HIPROC      = 15

    def __init__(self):
      pass

    def get_binding(self):
      return self.st_info & 0xF0 >> 4

    def get_type(self):
      return self.st_info & 0xF

  class ARM32Relocations:
    R_ARM_NONE          =   0
    R_ARM_PC24          =   1
    R_ARM_ABS32         =   2
    R_ARM_REL32         =   3
    R_ARM_PC13          =   4
    R_ARM_ABS16         =   5
    R_ARM_ABS12         =   6
    R_ARM_THM_ABS5      =   7
    R_ARM_ABS8          =   8
    R_ARM_SBREL32       =   9
    R_ARM_THM_CALL      =  10
    R_ARM_THM_PC8       =  11
    R_ARM_AMP_VCALL9    =  12
    R_ARM_SWI24         =  13
    R_ARM_THM_SWI8      =  14
    R_ARM_XPC25         =  15
    R_ARM_THM_XPC22     =  16
    R_ARM_COPY          =  20
    R_ARM_GLOB_DAT      =  21
    R_ARM_JUMP_SLOT     =  22
    R_ARM_RELATIVE      =  23
    R_ARM_GOTOFF        =  24
    R_ARM_GOTPC         =  25
    R_ARM_GOT32         =  26
    R_ARM_PLT32         =  27
    R_ARM_CALL          =  28
    R_ARM_JUMP24        =  29
    R_ARM_THM_JUMP24    =  30
    R_ARM_V4BX          =  40
    R_ARM_PREL31        =  42
    R_ARM_GNU_VTENTRY   = 100
    R_ARM_GNU_VTINHERIT = 101
    R_ARM_THM_PC11      = 102
    R_ARM_THM_PC9       = 103
    R_ARM_RXPC25        = 249
    R_ARM_RSBREL32      = 250
    R_ARM_THM_RPC22     = 251
    R_ARM_RREL32        = 252
    R_ARM_RABS22        = 253
    R_ARM_RPC24         = 254
    R_ARM_RBASE         = 255

    @staticmethod
    def get_name(r_type):
      _reloc_names = { Elffile.ARM32Relocations.R_ARM_NONE          :  "R_ARM_NONE",
                       Elffile.ARM32Relocations.R_ARM_PC24          :  "R_ARM_PC24",
                       Elffile.ARM32Relocations.R_ARM_ABS32         :  "R_ARM_ABS32",
                       Elffile.ARM32Relocations.R_ARM_REL32         :  "R_ARM_REL32",
                       Elffile.ARM32Relocations.R_ARM_PC13          :  "R_ARM_PC13",
                       Elffile.ARM32Relocations.R_ARM_ABS16         :  "R_ARM_ABS16",
                       Elffile.ARM32Relocations.R_ARM_ABS12         :  "R_ARM_ABS12",
                       Elffile.ARM32Relocations.R_ARM_THM_ABS5      :  "R_ARM_THM_ABS5",
                       Elffile.ARM32Relocations.R_ARM_ABS8          :  "R_ARM_ABS8",
                       Elffile.ARM32Relocations.R_ARM_SBREL32       :  "R_ARM_SBREL32",
                       Elffile.ARM32Relocations.R_ARM_THM_CALL      :  "R_ARM_THM_CALL",
                       Elffile.ARM32Relocations.R_ARM_THM_PC8       :  "R_ARM_THM_PC8",
                       Elffile.ARM32Relocations.R_ARM_AMP_VCALL9    :  "R_ARM_AMP_VCALL9",
                       Elffile.ARM32Relocations.R_ARM_SWI24         :  "R_ARM_SWI24",
                       Elffile.ARM32Relocations.R_ARM_THM_SWI8      :  "R_ARM_THM_SWI8",
                       Elffile.ARM32Relocations.R_ARM_XPC25         :  "R_ARM_XPC25",
                       Elffile.ARM32Relocations.R_ARM_THM_XPC22     :  "R_ARM_THM_XPC22",
                       Elffile.ARM32Relocations.R_ARM_COPY          :  "R_ARM_COPY",
                       Elffile.ARM32Relocations.R_ARM_GLOB_DAT      :  "R_ARM_GLOB_DAT",
                       Elffile.ARM32Relocations.R_ARM_JUMP_SLOT     :  "R_ARM_JUMP_SLOT",
                       Elffile.ARM32Relocations.R_ARM_RELATIVE      :  "R_ARM_RELATIVE",
                       Elffile.ARM32Relocations.R_ARM_GOTOFF        :  "R_ARM_GOTOFF",
                       Elffile.ARM32Relocations.R_ARM_GOTPC         :  "R_ARM_GOTPC",
                       Elffile.ARM32Relocations.R_ARM_GOT32         :  "R_ARM_GOT32",
                       Elffile.ARM32Relocations.R_ARM_PLT32         :  "R_ARM_PLT32",
                       Elffile.ARM32Relocations.R_ARM_CALL          :  "R_ARM_CALL",
                       Elffile.ARM32Relocations.R_ARM_JUMP24        :  "R_ARM_JUMP24",
                       Elffile.ARM32Relocations.R_ARM_V4BX          :  "R_ARM_V4BX",
                       Elffile.ARM32Relocations.R_ARM_THM_JUMP24    :  "R_ARM_THM_JUMP24",
                       Elffile.ARM32Relocations.R_ARM_PREL31        :  "R_ARM_PREL31",
                       Elffile.ARM32Relocations.R_ARM_GNU_VTENTRY   :  "R_ARM_GNU_VTENTRY",
                       Elffile.ARM32Relocations.R_ARM_GNU_VTINHERIT :  "R_ARM_GNU_VTINHERIT",
                       Elffile.ARM32Relocations.R_ARM_THM_PC11      :  "R_ARM_THM_PC11",
                       Elffile.ARM32Relocations.R_ARM_THM_PC9       :  "R_ARM_THM_PC9",
                       Elffile.ARM32Relocations.R_ARM_RXPC25        :  "R_ARM_RXPC25",
                       Elffile.ARM32Relocations.R_ARM_RSBREL32      :  "R_ARM_RSBREL32",
                       Elffile.ARM32Relocations.R_ARM_THM_RPC22     :  "R_ARM_THM_RPC22",
                       Elffile.ARM32Relocations.R_ARM_RREL32        :  "R_ARM_RREL32",
                       Elffile.ARM32Relocations.R_ARM_RABS22        :  "R_ARM_RABS22",
                       Elffile.ARM32Relocations.R_ARM_RPC24         :  "R_ARM_RPC24",
                       Elffile.ARM32Relocations.R_ARM_RBASE         :  "R_ARM_RBASE",
                      }

      if r_type in _reloc_names:
        ret = _reloc_names[r_type]
      else:
        ret = "(%d)" % r_type

      return ret


  def __init__(self, elffilename=None):
    self._elffiledata = None

    if(elffilename):
      self.load(elffilename)

  def load(self, file):
    elffile = io.open(file, "rb")
    _elffiledata = elffile.read()
    elffile.close()

    # Check ELF file for being a ELF program for ARM Little Endian
    if _elffiledata[0:len(self.ELF_MAGIC)] != self.ELF_MAGIC:
        raise Exception("Input file '%s' is not an ELF file" % (file))

    if _elffiledata[self.EI_VERSION] != chr(self.EV_CURRENT):
        raise Exception("Input file '%s' has unknown ELF file version" % (file))

    if _elffiledata[self.EI_CLASS] != chr(self.ELFCLASS32):
        raise Exception("Input file '%s' is not an ELF32 file" % (file))

    if _elffiledata[self.EI_DATA] != chr(self.ELFDATA2LSB):
        raise Exception("Input file '%s' is not an ELF32 LSB file" % (file))

    e_type = unpack_from("<H", _elffiledata, self.FILE_OFFS_TYPE)[0]
    if e_type != self.ET_REL:
        raise Exception("Input file '%s' is not a relocatable (e_type=%r)" % (file, e_type))

    e_machine = unpack_from("<H", _elffiledata, self.FILE_OFFS_MACHINE)[0]

    if e_machine != self.EM_ARM:
        raise Exception("Input file '%s' is not an ARM target ELF (e_machine=%r)" % (file, e_machine))

    e_version = unpack_from("<H", _elffiledata, self.FILE_OFFS_VERSION)[0]

    if e_version != self.EV_CURRENT:
        raise Exception("File '%s' has unknown ELF file version (e_version=%r)" % (file, e_version))

    self._elffiledata = _elffiledata
    self.e_shoff     = unpack_from("<L", _elffiledata, self.FILE_OFFS_SHOFF)[0]
    self.e_shnum     = unpack_from("<H", _elffiledata, self.FILE_OFFS_SHNUM)[0]
    self.e_shentsize = unpack_from("<H", _elffiledata, self.FILE_OFFS_SHENTSIZE)[0]
    # Get index of section name table
    self.e_shstrnidx = unpack_from("<H", _elffiledata, self.FILE_OFFS_SHSTRNDX)[0]

    self.stringtable_section = None

    if self.e_shstrnidx != 0:
      self.stringtable_section = self.parse_single_section(self.e_shstrnidx)

  def _get_symbol_name(self, section, name_offset):
    ret = ""

    if section:
      # Parse name of section
      for ch in section.data[name_offset:]:
        if(ch == chr(0)):
          break
        ret += ch

    return ret

  def parse_symbol_table(self, symtab_section, strtab_section=None):
    symbol_count = len(symtab_section.data) / self.Elf32Sym.ST_SIZE

    ret = []

    for sym in range(0, symbol_count):
      symbol = self.Elf32Sym()
      offset = sym * self.Elf32Sym.ST_SIZE

      symbol.st_name  = unpack_from("<L", symtab_section.data, offset + symbol.OFFS_ST_NAME)[0]
      symbol.st_value = unpack_from("<L", symtab_section.data, offset + symbol.OFFS_ST_VALUE)[0]
      symbol.st_size  = unpack_from("<L", symtab_section.data, offset + symbol.OFFS_ST_SIZE)[0]
      symbol.st_info  = unpack_from("<B", symtab_section.data, offset + symbol.OFFS_ST_INFO)[0]
      symbol.st_other = unpack_from("<B", symtab_section.data, offset + symbol.OFFS_ST_OTHER)[0]
      symbol.st_shndx = unpack_from("<H", symtab_section.data, offset + symbol.OFFS_ST_SHNDX)[0]

      symbol.name = self._get_symbol_name(strtab_section, symbol.st_name)

      ret.append(symbol)

    return ret

  def parse_single_section(self, section_number, get_data=True):
    if section_number > self.e_shnum:
      raise Exception("Invalid section (%r) requested. shnum=%r" % (section_number, self.e_shnum))

    ret = self.Elf32Section()
    section_header_start = self.e_shoff + section_number * self.e_shentsize

    ret.sh_name = unpack_from("<L", self._elffiledata, section_header_start + self.Elf32Section.OFFS_SH_NAME)[0]
    ret.name = self._get_symbol_name(self.stringtable_section, ret.sh_name)

    ret.idx           = section_number
    ret.sh_type       = unpack_from("<L", self._elffiledata, section_header_start + self.Elf32Section.OFFS_SH_TYPE)[0]
    ret.sh_flags      = unpack_from("<L", self._elffiledata, section_header_start + self.Elf32Section.OFFS_SH_FLAGS)[0]
    ret.sh_addr       = unpack_from("<L", self._elffiledata, section_header_start + self.Elf32Section.OFFS_SH_ADDR)[0]
    ret.sh_offset     = unpack_from("<L", self._elffiledata, section_header_start + self.Elf32Section.OFFS_SH_OFFSET)[0]
    ret.sh_size       = unpack_from("<L", self._elffiledata, section_header_start + self.Elf32Section.OFFS_SH_SIZE)[0]
    ret.sh_link       = unpack_from("<L", self._elffiledata, section_header_start + self.Elf32Section.OFFS_SH_LINK)[0]
    ret.sh_info       = unpack_from("<L", self._elffiledata, section_header_start + self.Elf32Section.OFFS_SH_INFO)[0]
    ret.sh_addralign  = unpack_from("<L", self._elffiledata, section_header_start + self.Elf32Section.OFFS_SH_ADDRALIGN)[0]
    ret.sh_entsize    = unpack_from("<L", self._elffiledata, section_header_start + self.Elf32Section.OFFS_SH_ENTSIZE)[0]

    if get_data:
      ret.data = self._elffiledata[ret.sh_offset : ret.sh_offset + ret.sh_size]

    return ret


  def parse_sections(self, include_sections = None):
    ret = {}

    for shidx in range(0, self.e_shnum):
      section = self.parse_single_section(shidx)
      ret[section.name] = section

    return ret