/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * FunctionWrapperExport.cpp 
 *
 * This file is part of the Chemical Data Processing Toolkit
 *
 * Copyright (C) 2003 Thomas Seidel <thomas.seidel@univie.ac.at>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; see the file COPYING. If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#include "CDPL/ForceField/InteractionFilterFunctions.hpp"
#include "CDPL/ForceField/TopologicalAtomDistanceFunction.hpp"
#include "CDPL/ForceField/MMFF94PropertyFunctions.hpp"
#include "CDPL/Chem/Atom.hpp"
#include "CDPL/Chem/Bond.hpp"
#include "CDPL/Chem/MolecularGraph.hpp"

#include "Base/FunctionWrapperExport.hpp"

#include "ClassExports.hpp"


void CDPLPythonForceField::exportFunctionWrappers()
{
	using namespace boost;
    using namespace CDPL;
    using namespace Chem;
    using namespace ForceField;

	CDPLPythonBase::Function1Export<MMFF94NumericAtomTypeFunction, Atom&>("MMFF94NumericAtomTypeFunction");
	CDPLPythonBase::Function1Export<MMFF94SymbolicAtomTypeFunction, Atom&,
									python::return_internal_reference<> >("MMFF94SymbolicAtomTypeFunction");
	CDPLPythonBase::Function1Export<MMFF94AtomChargeFunction, Atom&>("MMFF94AtomChargeFunction");
	CDPLPythonBase::Function1Export<MMFF94BondTypeIndexFunction, Bond&>("MMFF94BondTypeIndexFunction");
	CDPLPythonBase::Function1Export<MMFF94RingSetFunction, MolecularGraph&, 
									python::return_value_policy<python::copy_const_reference> >("MMFF94RingSetFunction");

	CDPLPythonBase::Function2Export<InteractionFilterFunction2, Atom&, Atom&>("InteractionFilterFunction2");
	CDPLPythonBase::Function3Export<InteractionFilterFunction3, Atom&, Atom&, Atom&>("InteractionFilterFunction3");
	CDPLPythonBase::Function4Export<InteractionFilterFunction4, Atom&, Atom&, Atom&, Atom&>("InteractionFilterFunction4");

	CDPLPythonBase::Function3Export<TopologicalAtomDistanceFunction, Atom&, Atom&, MolecularGraph&>("TopologicalAtomDistanceFunction");
}
