/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * IsOrdinaryHydrogenTest.cpp 
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

#include <boost/test/auto_unit_test.hpp>

#include "CDPL/Chem/Molecule.hpp"
#include "CDPL/Chem/Atom.hpp"
#include "CDPL/Chem/IsOrdinaryHydrogen.hpp"
#include "CDPL/Chem/AtomProperties.hpp"
#include "CDPL/Chem/BondProperties.hpp"
#include "CDPL/Chem/AtomPropertyFlags.hpp"
#include "CDPL/Chem/AtomTypes.hpp"


BOOST_AUTO_TEST_CASE(IsOrdinaryHydrogenTest)
{
	using namespace CDPL;
	using namespace Chem;

	Molecule mol;

	Atom& atom1 = mol.addAtom();
	Atom& atom2 = mol.addAtom();
	Bond& bond = mol.addBond(0, 1);

	bond.setProperty(BondProperty::ORDER, std::size_t(1));

//------

	atom1.setProperty(AtomProperty::SYMBOL, std::string("H"));

	BOOST_CHECK(IsOrdinaryHydrogen(0)(atom1));

	atom1.setProperty(AtomProperty::SYMBOL, std::string("T"));

	BOOST_CHECK(!IsOrdinaryHydrogen(AtomPropertyFlag::ISOTOPE)(atom1));
	BOOST_CHECK(IsOrdinaryHydrogen(0)(atom1));

	atom1.setProperty(AtomProperty::SYMBOL, std::string("X"));

	BOOST_CHECK(!IsOrdinaryHydrogen(0)(atom1));

	atom2.setProperty(AtomProperty::TYPE, AtomType::UNKNOWN);

	BOOST_CHECK(!IsOrdinaryHydrogen(AtomPropertyFlag::ISOTOPE | AtomPropertyFlag::H_COUNT | AtomPropertyFlag::FORMAL_CHARGE)(atom2));

	atom2.setProperty(AtomProperty::TYPE, AtomType::H);

	BOOST_CHECK(IsOrdinaryHydrogen(AtomPropertyFlag::ISOTOPE | AtomPropertyFlag::H_COUNT | AtomPropertyFlag::FORMAL_CHARGE)(atom2));

	atom2.setProperty(AtomProperty::TYPE, AtomType::Cl);

	BOOST_CHECK(!IsOrdinaryHydrogen(AtomPropertyFlag::H_COUNT | AtomPropertyFlag::FORMAL_CHARGE)(atom2));

	atom2.setProperty(AtomProperty::TYPE, AtomType::H);
	atom2.setProperty(AtomProperty::FORMAL_CHARGE, long(-1));

	BOOST_CHECK(!IsOrdinaryHydrogen(AtomPropertyFlag::ISOTOPE | AtomPropertyFlag::H_COUNT | AtomPropertyFlag::FORMAL_CHARGE)(atom2));
	BOOST_CHECK(IsOrdinaryHydrogen(AtomPropertyFlag::ISOTOPE | AtomPropertyFlag::H_COUNT)(atom2));

	atom2.setProperty(AtomProperty::FORMAL_CHARGE, long(1));

	BOOST_CHECK(!IsOrdinaryHydrogen(AtomPropertyFlag::ISOTOPE | AtomPropertyFlag::H_COUNT | AtomPropertyFlag::FORMAL_CHARGE)(atom2));
	BOOST_CHECK(IsOrdinaryHydrogen(0)(atom2));

	atom2.setProperty(AtomProperty::FORMAL_CHARGE, long(0));

	BOOST_CHECK(IsOrdinaryHydrogen(AtomPropertyFlag::ISOTOPE | AtomPropertyFlag::H_COUNT | AtomPropertyFlag::FORMAL_CHARGE)(atom2));
	BOOST_CHECK(IsOrdinaryHydrogen(0)(atom2));
}

