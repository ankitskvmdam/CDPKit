/* 
 * SMILESMoleculeInputHandlerTest.cpp 
 *
 * This file is part of the Chemical Data Processing Toolkit
 *
 * Copyright (C) 2003 Thomas Seidel <thomas.seidel@univie.ac.at>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; see the file COPYING. If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

#include <boost/test/auto_unit_test.hpp>

#include "CDPL/Chem/SMILESMoleculeInputHandler.hpp"
#include "CDPL/Chem/DataFormats.hpp"
#include "CDPL/Chem/JMEMoleculeReader.hpp"
#include "CDPL/Chem/SMILESMolecularGraphWriter.hpp"
#include "CDPL/Chem/Molecule.hpp"
#include "CDPL/Chem/MolecularGraphProperties.hpp"
#include "CDPL/Chem/ControlParameters.hpp"
#include "CDPL/Chem/AtomPropertyFlags.hpp"
#include "CDPL/Chem/BondPropertyFlags.hpp"
#include "CDPL/Base/DataIOManager.hpp"
#include "CDPL/Base/DataReader.hpp"
#include "CDPL/Base/ControlParameterList.hpp"
#include "CDPL/Base/IntTypes.hpp"


BOOST_AUTO_TEST_CASE(SMILESMoleculeInputHandlerTest)
{
	using namespace CDPL;
	using namespace Chem;
	using namespace Base;

	Molecule mol1;
	Molecule mol2;

	const DataInputHandler<Molecule>* handler = DataIOManager<Molecule>::getInputHandlerByFormat(Chem::DataFormat::SMILES);

	BOOST_CHECK(handler);

	BOOST_CHECK(handler->getDataFormat() == Chem::DataFormat::SMILES);

	BOOST_CHECK(DataIOManager<Molecule>::getInputHandlerByName("smiles") == handler);
	BOOST_CHECK(DataIOManager<Molecule>::getInputHandlerByFileExtension("smi") == handler);
	BOOST_CHECK(DataIOManager<Molecule>::getInputHandlerByMimeType("chemical/x-daylight-smiles") == handler);

	std::ifstream ifs(std::string(std::string(std::getenv("CDPKIT_TEST_DATA_DIR")) + "/Morphine.jme").c_str());

	BOOST_CHECK(ifs);

	BOOST_CHECK(JMEMoleculeReader(ifs).read(mol1));

	std::ostringstream oss;

	BOOST_CHECK(oss);

	SMILESMolecularGraphWriter writer(oss);

	writer.setParameter(ControlParameter::SMILES_WRITE_ATOM_STEREO, true);
	writer.setParameter(ControlParameter::SMILES_WRITE_BOND_STEREO, true);
	writer.setParameter(ControlParameter::SMILES_WRITE_RING_BOND_STEREO, true);
	writer.setParameter(ControlParameter::SMILES_MIN_STEREO_BOND_RING_SIZE, std::size_t(3));

	BOOST_CHECK(writer.write(mol1));

	std::istringstream iss(oss.str());

	BOOST_CHECK(iss);

	DataReader<Molecule>::SharedPointer reader_ptr(handler->createReader(iss));

	BOOST_CHECK(reader_ptr);
	BOOST_CHECK(reader_ptr->read(mol2));

	ControlParameterList::SharedPointer cpl(new ControlParameterList());

	unsigned int atom_flags = AtomPropertyFlag::TYPE | AtomPropertyFlag::ISOTOPE | AtomPropertyFlag::H_COUNT
		| AtomPropertyFlag::FORMAL_CHARGE | AtomPropertyFlag::AROMATICITY;

	unsigned int bond_flags = BondPropertyFlag::ORDER | BondPropertyFlag::TOPOLOGY | BondPropertyFlag::AROMATICITY 
		| BondPropertyFlag::CONFIGURATION;

	cpl->setParameter(ControlParameter::ATOM_PROPERTY_FLAGS, atom_flags);
	cpl->setParameter(ControlParameter::BOND_PROPERTY_FLAGS, bond_flags);

	mol1.setProperty(MolecularGraphProperty::HASH_CODE_PARAMETERS, cpl);
	mol2.setProperty(MolecularGraphProperty::HASH_CODE_PARAMETERS, cpl);

	BOOST_CHECK(mol1.getProperty<Base::uint64>(MolecularGraphProperty::HASH_CODE) == 
				mol2.getProperty<Base::uint64>(MolecularGraphProperty::HASH_CODE));
}
