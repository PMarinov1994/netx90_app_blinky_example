# -*- coding: utf-8 -*-

# ***************************************************************************
# *   Copyright (C) 2019 by Hilscher GmbH                                   *
# *   netXsupport@hilscher.com                                              *
# *                                                                         *
# *   This program is free software; you can redistribute it and/or modify  *
# *   it under the terms of the GNU General Public License as published by  *
# *   the Free Software Foundation; either version 2 of the License, or     *
# *   (at your option) any later version.                                   *
# *                                                                         *
# *   This program is distributed in the hope that it will be useful,       *
# *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
# *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
# *   GNU General Public License for more details.                          *
# *                                                                         *
# *   You should have received a copy of the GNU General Public License     *
# *   along with this program; if not, write to the                         *
# *   Free Software Foundation, Inc.,                                       *
# *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
# ***************************************************************************

import argparse
import re
from hbi_settings import *
import sys

from com.hboot_image  import HbootImage
from nxt_version      import get_version_strings

__version__, __revision__, version_clean = get_version_strings()

executed_file = os.path.split(sys.argv[0])[-1]
hboot_image_compiler_com_epilog = u'''

Example for creating a hwc HBoot image
======================================
    $ hboot_image_compiler_com.exe hwc_hboot.hwc -t hwc -nt netx90 -A hw_config="hwc_hboot.xml"

    * -A hw_config="hwc_hboot.xml": Specifies path to a file containing the hardware configuration.

Example for creating a mwc HBoot image
======================================
    $ hboot_image_compiler_com.exe hwc_hboot.hwc -t mwc -nt netx90 -A hw_config="hwc_hboot.xml"

    * -A hw_config="hwc_hboot.xml": Specifies path to a file containing the hardware configuration.

'''


def print_args(args):
    print("Run hboot image compiler app with arguments:")
    for key, value in args.__dict__.items():
        print("    %s: %s" % (key, value))
    print("")


tParser = argparse.ArgumentParser(
    usage='hboot_image [options]',
    epilog=hboot_image_compiler_com_epilog,
    formatter_class=argparse.RawTextHelpFormatter,
    add_help=False
)
tParser.add_argument(
    '-h', '--help',
    action='help',
    default=argparse.SUPPRESS,
    help='Show this help message and exit'
)
tParser.add_argument(
    '-v',
    '--version',
    action='version',
    version=__version__,
    help="Show program's version number and exit"
)

tGroup = tParser.add_mutually_exclusive_group(required=False)
tGroup.add_argument('-nt', '--netx-type-public',
                    dest='strNetxType',
                    choices=[
                         'netx90',
                         # 'netx90_rev0',
                         'netx90_rev1',
                         # 'netx90_rev2',
                         # 'netx90_mpw',
                         # 'NETX56',
                         # 'NETX4000_RELAXED',
                         # 'NETX4000',
                         # 'NETX4100'
                     ],
                    default='netx90',
                    metavar='NETX',
                    help='Build the image for netX type public NETX. By default the newest netx90 type is selected.'
                         ' Possible values are: %s' % ['netx90', 'netx90_rev1'])
tGroup.add_argument('-n', '--netx-type',
                    dest='strNetxType',
                    choices=[
                         'NETX56',
                         'NETX90',
                         'NETX90B',
                         'NETX90C',
                         'NETX90D',
                         'NETX90_MPW',
                         'NETX4000_RELAXED',
                         'NETX4000',
                         'NETX4100',
                         'NETXXL_MPW'
                     ],
                    metavar='NETX',
                    help=argparse.SUPPRESS,
                    # help='Build the image for netx type NETX.'
                    )

tParser.add_argument('-c', '--objcopy',
                     dest='strObjCopy',
                     required=False,
                     default=OBJCPY,
                     metavar='FILE',
                     # help='Use FILE as the objcopy tool.',
                     help=argparse.SUPPRESS
                     )
tParser.add_argument('-d', '--objdump',
                     dest='strObjDump',
                     required=False,
                     default=OBJDUMP,
                     metavar='FILE',
                     # help='Use FILE as the objdump tool.',
                     help=argparse.SUPPRESS)
tParser.add_argument('-r', '--readelf',
                     dest='strReadElf',
                     required=False,
                     default=READELF,
                     metavar='FILE',
                     # help='Use FILE as the readelf tool.',
                     help=argparse.SUPPRESS)
tParser.add_argument('-k', '--keyrom',
                     dest='strKeyRomPath',
                     required=False,
                     default=None,
                     metavar='FILE',
                     # help='Read the keyrom data from FILE.',
                     help=argparse.SUPPRESS)
tParser.add_argument('-p', '--patch-table',
                     dest='strPatchTablePath',
                     required=False,
                     default=None,
                     metavar='FILE',
                     # help='Read the patch table from FILE.',
                     help=argparse.SUPPRESS)

tParser.add_argument('-V', '--verbose',
                     dest='fVerbose',
                     required=False,
                     default=False,
                     action='store_const', const=True,
                     # help='Be more verbose.',
                     help=argparse.SUPPRESS)
tParser.add_argument('-A', '--alias',
                     dest='astrAliases',
                     required=False,
                     action='append',
                     metavar='ALIAS=VALUE',
                     help='Provide a value for an alias in the form of ALIAS=VALUE')
tParser.add_argument('-D', '--define',
                     dest='astrDefines',
                     required=False,
                     action='append',
                     metavar='NAME=VALUE',
                     # help='Add a define in the form NAME=VALUE.',
                     help=argparse.SUPPRESS)
tParser.add_argument('-I', '--include',
                     dest='astrIncludePaths',
                     required=False,
                     action='append',
                     metavar='PATH',
                     # help='Add PATH to the list of include paths.',
                     help=argparse.SUPPRESS)
tParser.add_argument('-S', '--sniplib',
                     dest='astrSnipLib',
                     required=False,
                     action='append',
                     metavar='PATH',
                     # help='Add PATH to the list of sniplib paths.',
                     help=argparse.SUPPRESS)
tParser.add_argument('--openssl-options',
                     dest='astrOpensslOptions',
                     required=False,
                     action='append',
                     metavar='SSLOPT',
                     # help='Add SSLOPT to the arguments for OpenSSL.',
                     help=argparse.SUPPRESS
                     )
tParser.add_argument('--openssl-exe',
                     dest='strOpensslExe',
                     required=False,
                     default='openssl',
                     metavar='PATH',
                     # help='Add individual OpenSSL Path.',
                     help=argparse.SUPPRESS
                     )
tParser.add_argument('--openssl-rand-off',
                     dest='fOpensslRandOff',
                     required=False,
                     default=False,
                     action='store_const', const=True,
                     metavar='SSLRAND',
                     # help='Set openssl randomization true or false.',
                     help=argparse.SUPPRESS
                     )
# tParser.add_argument('strInputFile',
#                      metavar='FILE',
#                      help='Read the HBoot definition from FILE.')
# tParser.add_argument('strOutputFile',
#                      metavar='FILE',
#                      help='Write the HBoot image to FILE.')
tParser.add_argument(
    '-t', '--template-layout',
    dest='strHbootImageLayout',
    required=False,
    metavar="LAYOUT",
    choices=['hwc', 'mwc'],
    help='Use hwc or mwc HBoot image template-layout. Possible values are: %s' % ['hwc', 'mwc']
)
tParser.add_argument(
    'astrFiles',
    nargs='+',
    metavar='FILES',
    help="List of files. If argument '--template-layout' is not used the first file of the list will be used as input file"
)
tParser.add_argument(
    '-a', '--append-file',
    dest='strFileToAppend',
    required=False,
    metavar='FILE',
    help="A binary file to be appended to the output file."
)


tArgs = tParser.parse_args(args=['--help'] if len(sys.argv) < 2 else None)
print("HBoot image compiler COM")
print(__version__)
print_args(tArgs)

# Set the default for the patch table here.
atDefaultPatchTables = {
    'NETX56': 'hboot_netx56_patch_table.xml',
    'NETX90': 'hboot_netx90_patch_table.xml',
    'NETX90B': 'hboot_netx90b_patch_table.xml',
    'NETX90C': 'hboot_netx90b_patch_table.xml',  # c also uses patch table b
    'NETX90D': 'hboot_netx90d_patch_table.xml',
    'NETX90_MPW': 'hboot_netx90_mpw_patch_table.xml',
    'NETX4000_RELAXED': 'hboot_netx4000_relaxed_patch_table.xml',
    'NETX4000': 'hboot_netx4000_patch_table.xml',
    'NETX4100': 'hboot_netx4000_patch_table.xml'
}

# change netx_type to internal namings
if tArgs.strNetxType == 'netx90':  # netx90 is always mapped to newest netx90_revx
    strNetxType = 'NETX90B'
elif tArgs.strNetxType == 'netx90_rev0':
    strNetxType = 'NETX90'
elif tArgs.strNetxType == 'netx90_rev1':
    strNetxType = 'NETX90B'  # NETX90C is included in this case (same functionality)
elif tArgs.strNetxType == 'netx90_rev2':
    strNetxType = 'NETX90D'
elif tArgs.strNetxType == 'netx90_mpw':
    strNetxType = 'NETX90_MPW'
else:
    strNetxType = tArgs.strNetxType


if tArgs.strPatchTablePath is None:

    path_patch_tables = os.path.join(hbi_sources, "patch_tables")

    tArgs.strPatchTablePath = os.path.join(
        path_patch_tables,
        atDefaultPatchTables[strNetxType]
    )

# Parse all alias definitions.
atKnownFiles = {}
if tArgs.astrAliases is not None:
    tPattern = re.compile('([a-zA-Z0-9_]+)=(.+)$')
    for strAliasDefinition in tArgs.astrAliases:
        tMatch = re.match(tPattern, strAliasDefinition)
        if tMatch is None:
            raise Exception(
                'Invalid alias definition: "%s". '
                'It must be "ALIAS=VALUE" instead.' % strAliasDefinition
            )
        strAlias = tMatch.group(1)
        strFile = tMatch.group(2)
        if strAlias in atKnownFiles:
            raise Exception(
                'Double defined alias "%s". The old value "%s" should be '
                'overwritten with "%s".' % (
                    strAlias,
                    atKnownFiles[strAlias],
                    strFile
                )
            )
        atKnownFiles[strAlias] = strFile

# Parse all defines.
atDefinitions = {}
if tArgs.astrDefines is not None:
    tPattern = re.compile('([a-zA-Z0-9_]+)=(.+)$')
    for strDefine in tArgs.astrDefines:
        tMatch = re.match(tPattern, strDefine)
        if tMatch is None:
            raise Exception('Invalid define: "%s". '
                            'It must be "NAME=VALUE" instead.' % strDefine)
        strName = tMatch.group(1)
        strValue = tMatch.group(2)
        if strName in atDefinitions:
            raise Exception(
                'Double defined name "%s". '
                'The old value "%s" should be overwritten with "%s".' % (
                    strName,
                    atKnownFiles[strName],
                    strValue
                )
            )
        atDefinitions[strName] = strValue

# Set an empty list of include paths if nothing was specified.
if tArgs.astrIncludePaths is None:
    tArgs.astrIncludePaths = []

# Set an empty list of sniplib paths if nothing was specified.
if tArgs.astrSnipLib is None:
    tArgs.astrSnipLib = []

tEnv = {'OBJCOPY': tArgs.strObjCopy,
        'OBJDUMP': tArgs.strObjDump,
        'READELF': tArgs.strReadElf,
        'HBOOT_INCLUDE': tArgs.astrIncludePaths}

tCompiler = HbootImage(
    tEnv,
    strNetxType,
    defines=atDefinitions,
    includes=tArgs.astrIncludePaths,
    known_files=atKnownFiles,
    patch_definition=tArgs.strPatchTablePath,
    verbose=tArgs.fVerbose,
    sniplibs=tArgs.astrSnipLib,
    keyrom=tArgs.strKeyRomPath,
    openssloptions=tArgs.astrOpensslOptions,
    opensslexe=tArgs.strOpensslExe,
    opensslrandoff=tArgs.fOpensslRandOff
)

astrOutputFiles = None
strInputFile = None
if getattr(tArgs, 'strHbootImageLayout') is not None:
    # use one of the template files
    strHbootImageLayout = getattr(tArgs, 'strHbootImageLayout')
    strInputFile = os.path.join(hbi_sources, 'templates', 'com',  'top_hboot_image_%s.xml' % strHbootImageLayout.lower())
    if not os.path.exists(strInputFile):
        raise FileNotFoundError("could not find template '%s'" % strInputFile)
    # all the files are output files
    if len(tArgs.astrFiles) in [1]:
        astrOutputFiles = tArgs.astrFiles[0]
    else:
        raise argparse.ArgumentError(
            "Too few/many files were passed for this mode. (should be 1 but is %s)" % len(tArgs.astrFiles)
        )

else:
    print("Info: you are using an advanced mode. Consider using the parameter '--template-layout'.")
    strHbootImageLayout = getattr(tArgs, 'strHbootImageLayout')
    strInputFile = tArgs.astrFiles[0]
    if not (strInputFile.endswith(".xml") or strInputFile.endswith(".XML")):
        raise argparse.ArgumentError("For the advanced mode the first parameter must be a HBoot image XMl file.")
    if len(tArgs.astrFiles) in [2]:
        astrOutputFiles = tArgs.astrFiles[1]
    else:
        raise argparse.ArgumentError(
            "Too few/many files were passed for this mode. (should be 2 but is %s)" % len(tArgs.astrFiles)
        )

tCompiler.parse_image(strInputFile)
tCompiler.write(astrOutputFiles, strFileToAppend=tArgs.strFileToAppend)
