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
import os
import sys
import platform


file_path = os.path.realpath(__file__)
hbi_sources = os.path.dirname(os.path.dirname(file_path))

sys.path.append(hbi_sources)

path_patch_tables = os.path.join(hbi_sources, "patch_tables")

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

cwd_ = os.path.dirname(hbi_sources)

plat = platform.system()
OBJCPY  = 'arm-none-eabi-objcopy'
OBJDUMP = 'arm-none-eabi-objdump'
READELF = 'arm-none-eabi-readelf'

hbi_path = cwd_
