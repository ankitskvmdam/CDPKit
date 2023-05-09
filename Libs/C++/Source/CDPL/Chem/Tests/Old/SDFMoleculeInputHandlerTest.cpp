/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * SDFMoleculeInputHandlerTest.cpp 
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

#include "CDPL/Chem/SDFMoleculeInputHandler.hpp"
#include "CDPL/Chem/DataFormats.hpp"
#include "CDPL/Chem/JMEMoleculeReader.hpp"
#include "CDPL/Chem/SDFMolecularGraphWriter.hpp"
#include "CDPL/Chem/Molecule.hpp"
#include "CDPL/Chem/MolecularGraphProperties.hpp"
#include "CDPL/Base/DataIOManager.hpp"
#include "CDPL/Base/DataReader.hpp"
#include "CDPL/Base/IntTypes.hpp"


BOOST_AUTO_TEST_CASE(SDFMoleculeInputHandlerTest)
{
	using namespace CDPL;
	using namespace Chem;
	using namespace Base;

	Molecule mol1;
	Molecule mol2;

	const DataInputHandler<Molecule>* handler = DataIOManager<Molecule>::getInputHandlerByFormat(Chem::DataFormat::SDF);

	BOOST_CHECK(handler);

	BOOST_CHECK(handler->getDataFormat() == Chem::DataFormat::SDF);

	BOOST_CHECK(DataIOManager<Molecule>::getInputHandlerByName("sdf") == handler);
	BOOST_CHECK(DataIOManager<Molecule>::getInputHandlerByFileExtension("sdf") == handler);
	BOOST_CHECK(DataIOManager<Molecule>::getInputHandlerByFileExtension("sd") == handler);
	BOOST_CHECK(DataIOManager<Molecule>::getInputHandlerByMimeType("chemical/x-mdl-sdfile") == handler);

	std::ifstream ifs(std::string(std::string(std::getenv("CDPKIT_TEST_DATA_DIR")) + "/Morphine.jme").c_str());

	BOOST_CHECK(ifs);

	BOOST_CHECK(JMEMoleculeReader(ifs).read(mol1));

	std::ostringstream oss;

	BOOST_CHECK(oss);

	BOOST_CHECK(SDFMolecularGraphWriter(oss).write(mol1));

	std::istringstream iss(oss.str());

	BOOST_CHECK(iss);

	DataReader<Molecule>::SharedPointer reader_ptr(handler->createReader(iss));

	BOOST_CHECK(reader_ptr);
	BOOST_CHECK(reader_ptr->read(mol2));

	BOOST_CHECK(mol1.getNumAtoms() == mol2.getNumAtoms());
	BOOST_CHECK(mol1.getNumBonds() == mol2.getNumBonds());

	BOOST_CHECK(mol1.getProperty<Base::uint64>(MolecularGraphProperty::HASH_CODE) == 
				mol2.getProperty<Base::uint64>(MolecularGraphProperty::HASH_CODE));
}

