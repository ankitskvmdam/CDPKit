Molecular Input/Output
======================

Installation
------------

The package can be installed via pip:

.. code:: ipython3

    ! pip install cdpkit


.. parsed-literal::

    Collecting cdpkit
      Downloading CDPKit-0.9.0.tar.gz (69.0 MB)
    [2K     [90m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━[0m [32m69.0/69.0 MB[0m [31m7.3 MB/s[0m eta [36m0:00:00[0m00:01[0m00:01[0m
    [?25h  Installing build dependencies ... [?25ldone
    [?25h  Getting requirements to build wheel ... [?25ldone
    [?25h  Preparing metadata (pyproject.toml) ... [?25ldone
    [?25hBuilding wheels for collected packages: cdpkit
      Building wheel for cdpkit (pyproject.toml) ... [?25ldone
    [?25h  Created wheel for cdpkit: filename=CDPKit-0.9.0-cp39-cp39-linux_x86_64.whl size=76790417 sha256=a414ac07ea08b876c0c5f71f8484f2fa7ca89db6f323d490e03d6cfb26302f76
      Stored in directory: /home/oliver/.cache/pip/wheels/45/40/b1/d967717e72f447e185612340ce4a35f0d0584802bcfb4397e0
    Successfully built cdpkit
    Installing collected packages: cdpkit
    Successfully installed cdpkit-0.9.0


Import the
`CDPL.Chem <https://cdpkit.org/v1.0.0/cdpl_api_doc/python_api_doc/namespaceCDPL_1_1Chem.html>`__
module - it offers functionality for the processing of chemical data and
is one of the most frequently used modules of the CDPL

.. code:: ipython3

    import CDPL.Chem as Chem

Reading molecules from an input file
------------------------------------

You’ll frequently need to read or write molecular data from a variety of
file formats. Using CDPKit, you can easily read and write molecules
saved in various file formats, including *SDF*, *SMILES*, *MOL*, *MOL2*,
*CDF*, and others.

.. note:: The CDF format is a binary format and CDPKit’s native file
format that can be used to store molecules/pharmacophores and their
associated metadata in a space and processing time efficient manner.

The class
\`\ `Chem.MoleculeReader <https://cdpkit.org/v1.0.0/cdpl_api_doc/python_api_doc/classCDPL_1_1Chem_1_1MoleculeReader.html>`__
is rather versatile and can read molecules stored in different formats
(SDF, SMILES, MOL, MOL2, CDF, etc.) thus eliminating the need to call a
specific reader for each format. Here is a simple example of how to read
molecules from an input file:

When loaded, the CDPL.Chem module provides a number of classes and
functions that can be used to process chemical data.

.. note:: The CDPL is based on C++ and therefore object oriented
(`Object oriented
programming <https://en.wikipedia.org/wiki/Object-oriented_programming>`__).
When using any class, it first needs to be initialized and then it can
be used to perform certain actions (e.g. read molecules from an input
file).

.. code:: ipython3

    reader = Chem.MoleculeReader("../data/test_file.sdf")
    
    # create an instance of the default implementation of the Chem.Molecule interface
    mol = Chem.BasicMolecule()
    mols = list()
    # Iterate over each molecule and print atom and bond count
    
    while reader.read(mol):
      print("molecule object: ", mol)
      mols.append(mol.clone())


.. parsed-literal::

    molecule object:  <CDPL.Chem._chem.BasicMolecule object at 0x7f501ceeaea0>



