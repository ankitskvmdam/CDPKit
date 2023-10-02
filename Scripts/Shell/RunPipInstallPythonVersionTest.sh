#!/bin/bash

##
# RunPipInstallPythonVersionTest.sh 
#
# This file is part of the Chemical Data Processing Toolkit
#
# Copyright (C) 2023 Oliver Wieder <oliver.wieder@univie.ac.at>
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

logfile="./Examples/Python/Tests/pip_install_python_version_test.log"
tempfile="./Scripts/Shell/Tests/temp_pip_install_python_version_test.log"

# Prompt user for deleting the log file
read -p "Do you want to delete the previous log file (y/n)? " choice
if [[ $choice == "y" || $choice == "Y" ]]; then
    rm -f $logfile
    rm -f $tempfile
fi

exec > >(tee -a $logfile) 2>&1

python_versions=("3.6" "3.7" "3.8" "3.9" "3.10" "3.11")

success_versions=()
failure_versions=()

for version in "${python_versions[@]}"; do
    env_name="test_python${version//.}"

    echo "Testing Python $version"

    # Create conda environment and log the output
    conda create -y -n $env_name python=$version

    # Activate the environment
    source activate $env_name

    # Install numpy and log the output#
    pip install numpy

    # Install CDPKit and log the output
    pip install CDPKit

    # Test the import
    python -c "import CDPL.Chem as Chem"
    return_code=$?
    if [ $return_code -eq 0 ]; then
        echo "*** SUCCESS ***: Python $version installed and module imported successfully."
        success_versions+=($version)
    elif [ $return_code -eq 139 ]; then
        echo "*** SEGFAULT ***: Python $version segmentation fault encountered. Running GDB for diagnostics..."
        gdb --batch --command=./Scripts/Shell/gdb_commands.txt python$version
        failure_versions+=($version)
    else
        echo "*** FAILURE ***: Python $version failed to install or import module."
        failure_versions+=($version)
    fi

    # Deactivate the environment
    conda deactivate

    # Optionally remove the environment after testing
    conda env remove -n $env_name
done

# Prepend the summary to the log file
{
    echo "------ SUMMARY ------"
    echo "SUCCESS for versions: ${success_versions[@]}"
    echo "FAILURE for versions: ${failure_versions[@]}"
    echo "----------------------"
    echo ""
    cat $logfile
} > $tempfile

mv $tempfile $logfile