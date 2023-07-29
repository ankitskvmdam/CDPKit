##
# setup.py  
#
# This file is part of the Chemical Data Processing Toolkit
#
# Copyright (C) 2003 Thomas Seidel <thomas.seidel@univie.ac.at>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program; see the file COPYING. If not, write to
# the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
# Boston, MA 02111-1307, USA.
##


from os import path
from os import listdir

from skbuild import setup


def postproc_manifest(cmake_manifest):
    if len(cmake_manifest) == 0:
        return cmake_manifest
    
    proc_manifest = []
    inst_dir = path.dirname(cmake_manifest[0])
    extra_files = [path.join(inst_dir, f) for f in listdir(inst_dir) if path.isfile(path.join(inst_dir, f))]

    for extra_file in extra_files:
        if extra_file not in cmake_manifest:
            proc_manifest.append(extra_file)

    for entry in cmake_manifest:
        idx = entry.find('cdpl-')
        
        if idx >= 0 and entry.count('.', idx) != 3:
            continue
        
        proc_manifest.append(entry)

    return proc_manifest


setup(
    name='CDPKit',
    version='1.0.0',
    description='CDPKit CDPL Python-Bindings',
    author='Thomas Seidel',
    author_email='thomas.seidel@univie.ac.at',
    url='https://github.com/molinfo-vienna/CDPKit',
    license='LGPLv2',
    packages=['CDPL'],
    package_dir={'': 'Libs/Python'},
    python_requires='>=3.6',
    cmake_args=['-DCDPL_PYPI_PACKAGE_BUILD:BOOL=ON', '-Wno-dev'],
    cmake_process_manifest_hook=postproc_manifest,
)