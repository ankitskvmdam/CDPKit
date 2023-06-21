# About

CDPKit is an open-source cheminformatics software toolkit implemented in C++. In addition to the C++ API a Python-interfacing layer is provided that allows to use all of CDPKit's functionality
from Python scripts. CDPKit features a high-quality and well-tested modular implementation of basic functionality typically required by any higher-level software application in the field of cheminformatics. 
This includes data structures for the representation and analysis of chemical structures, routines for the I/O of small molecule and macromolecular data in different file formats (MDL Mol and SDF, Mol2, PDB, MMTF, SMILES, etc.), ring and aromaticity perception, pharmacophore generation, substructure searching, molecular fingerprinting, molecule fragment generation (RECAP, BRICS), 2D structure layout and visualization, 3D structure and conformer generation ([CONFORT](https://www.researchsquare.com/article/rs-1597257/v1)), physicochemical property prediction, and so on.

At its core, CDPKit delivers a set of command line tools and software libraries (CDPL) that enable researchers to work with molecular data in a systematic and efficient manner, allowing seamless integration with other software and databases.

Furthermore, CDPKit integrates with various machine learning and data mining libraries, enabling scientists to build predictive models for molecular 
properties. This makes it a valuable tool in the field of computational drug discovery, where machine learning is employed to predict the biological activity, toxicity, 
and other properties of potential drug candidates. An example of the integration can be found in the source code of this [publication](https://www.mdpi.com/1420-3049/26/20/6185).

## Getting Started with CDPKit

This short guide will help you get started with CDPKit and introduce you to some of its key features.

### Installation

For an installation of CDPKit from source please follow the steps below:

1. **Build Requirements and Dependencies**
- C++11 compliant compiler (mandatory)
- cmake (V >= 3.17, mandatory)
- boost-devel C++ libraries (V >= 1.63, mandatory)
- python-devel 3.x (optional) and Python interpreter (mandatory)
- Qt5-devel (optional)
- cairo-devel (V >= 1.14, optional)
- sqlite-devel V3 (optional)
- sphinx (V >= 4.5, optional)
- sphinx-rtd-theme (optional)
- sphinxcontrib-bibtex (optional)
- doxygen (V >= 1.8.5, optional)

**Python Environment**: Ensure you have a working Python environment. CDPKit is primarily used with Python, so make sure you have Python 3.x installed on your system.

2. **Build and Install CDPKit**

The makefiles are generated using cmake as follows (assuming a build on a Linux host):

```
> mkdir <BUILD-DIR>
> cd <BUILD-DIR>
> cmake <CDPKIT-SOURCE-DIR>
```

If the makefiles have been generated without errors, invoking
'make' from within `<BUILD-DIR>` starts the actual build process: 

```
> make
```

Building CDPKit should proceed without any issues on current Linux systems.
If the build finished without errors

```
> make install
```

will install CDPKit in the `/opt` directory of your system (a different install
location can be specified by a `-DCMAKE_INSTALL_PREFIX=<INSTALL-DIR>` argument on the `cmake` command line).


### Generating CDPKit Documentation

For a successful build of the CDPKit documentation pages, sphinx, the sphinx-rtd-theme and sphinxcontrib-bibtex
need to be available on the build host. Furthermore, for the generation of the CDPL C++ and Python API-documentation,
doxygen has to be installed.

If all prerequisites are fulfilled

```
> make doc
```

should successfully build the CDPKit documentation pages which can then be found in `<BUILD-DIR>/Doc/html`.

### CDPKit Website 
A dedicated CDPKit website with more elaborate documentation and tutorials will be available soon (end of September).
In the meantime you can access it via `<BUILD-DIR>/Doc/html`.
There, under the link `CDPL Python-API` you can find an overview of the currently provided classes and functions.
You can also access the `CDPL Python Cookbook` there, which is a collection of stand alone scripts of common use cases, including

- Processing of Chemical Data
    - Input and Output
    - Fragmentation and Extraction of Substructures
    - Molecule Standardization and Curation

- Pharmacophore Generation and Processing
    - Plain Molecule Pharmacophores
    - Ligand-Receptor Interaction Pharmacophores
    - Retrieving Feature Properties
    - Molecule to Reference Pharmacophore Alignment

- Calculation of Atom and Bond Properties
    - Connectivity Properties
    - Chemical Element Properties
    - Classification Properties
    - Partial Charges and other Electronic Properties
    - Physicochemical Properties

- Calculation of Molecule and Pharmacophore Descriptors
    - Extended Connectivity Fingerprints (ECFPs)
    - FAME Atom Environment Fingerprints

- Force Field Calculations
    - MMFF94 Atom Charges

### Basic Usage

Once CDPKit is installed, you can start using it in your Python code (note: `PYTHONPATH` has to include the `<INSTALL-DIR>/Python` directory).
Here's an example to get you started with basic ligand-based pharmacophore generation starting from a SMILES string:

```python
# Import the necessary CDPKit modules
from CDPL import Chem
from CDPL import Pharm

# read molecule in SMILES-format
mol = Chem.parseSMILES('Cc1ccccc1')

# print the number of atoms and bonds for the molecule
print('Processing molecule with {!s} atoms and {!s} bonds'.format(mol.numAtoms, mol.numBonds))

# create an instance of the pharmacophore data structure
ph4 = Pharm.BasicPharmacophore()

# prepare molecule for pharmacophore generation
Pharm.prepareForPharmacophoreGeneration(mol)

# generate the ligand based pharmacophore model for the molecule
Pharm.DefaultPharmacophoreGenerator(mol, ph4)

# print the number of features and feature composition
print(' -> Generated %s features: %s' % (str(ph4.numFeatures), Pharm.buildFeatureTypeHistogramString(ph4)))
```

### Further Exploration

CDPKit offers a vast range of functionality beyond the basic usage example shown above. Some areas to explore include:

- **Substructure Searching**: CDPKit provides powerful methods to search for substructures within molecules.

- **Descriptor Calculation**: CDPKit allows you to calculate various molecular descriptors, such as Lipinski's Rule-of-Five properties, topological fingerprints, and much more. These descriptors can be used to model molecular properties and predict biological activities.

- **Chemical Reactions**: CDPKit fully supports chemical reactions with dedicated data structures and functionality for I/O, reaction substructure search, 2D visualization, reaction transformations, and so on.

- **Machine Learning Integration**: CDPKit integrates well with machine learning libraries like scikit-learn, PyTorch, and TensorFlow. You can use CDPKit to preprocess molecular data, extract features, and build predictive models for various chemical properties.

### Documentation and Resources

To learn more about CDPKit and explore its features in detail, refer to the official documentation and additional resources:

- **CDPKit Documentation**: Visit the [CDPKit documentation](http://a7srv2.pch.univie.ac.at/cdpkit/getting_started/index.html#getting-started) for comprehensive information, tutorials, and examples (currently for UniVie staff only).

- **CDPKit GitHub Repository**: Check out the [CDPKit GitHub repository](https://github.com/molinfo-vienna/CDPKit) for source code, issue tracking, and community support.

- **CDPKit Cookbook**: Explore the [CDPKit Cookbook](http://a7srv2.pch.univie.ac.at/cdpkit/cdpl_python_cookbook/index.html) for a collection of code snippets and examples showcasing various CDPKit functionalities. The documentation page will be available for external usage soon.

- **CDPKit Conformer Generator**: Have a look at the [CONFORT](https://www.researchsquare.com/article/rs-1597257/v1) paper preprint for detailed information about the integrated high-quality conformer generator.

- **CDPKit ML integration example**: Check out the [github](https://github.com/spudlig/graph_networks) page of the "Improved Lipophilicity and Aqueous Solubility Prediction with Composite Graph Neural Networks" publication for exploring the ML integration possibilities of CDPKit.