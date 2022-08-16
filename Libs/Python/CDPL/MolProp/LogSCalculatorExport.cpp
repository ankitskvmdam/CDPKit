/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * LogSCalculatorExport.cpp 
 *
 * This file is part of the Chemical Data Processing Toolkit
 *
 * Copyright (C) 2003-2020 Thomas A. Seidel <thomas.seidel@univie.ac.at>
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


#include <boost/python.hpp>

#include "CDPL/Chem/LogSCalculator.hpp"
#include "CDPL/Chem/MolecularGraph.hpp"

#include "Base/ObjectIdentityCheckVisitor.hpp"
#include "Base/CopyAssOp.hpp"

#include "ClassExports.hpp"


void CDPLPythonChem::exportLogSCalculator()
{
	using namespace boost;
	using namespace CDPL;

	python::class_<Chem::LogSCalculator, boost::noncopyable>("LogSCalculator", python::no_init)
		.def(python::init<>(python::arg("self")))
		.def(python::init<const Chem::LogSCalculator&>((python::arg("self"), python::arg("calculator"))))
		.def(python::init<const Chem::MolecularGraph&>((python::arg("self"), python::arg("molgraph"))))
		.def(CDPLPythonBase::ObjectIdentityCheckVisitor<Chem::LogSCalculator>())
		.def("assign", CDPLPythonBase::copyAssOp(&Chem::LogSCalculator::operator=), 
			 (python::arg("self"), python::arg("calculator")), python::return_self<>())
		.def("calculate", &Chem::LogSCalculator::calculate, (python::arg("self"), python::arg("molgraph")))
		.def("getResult", &Chem::LogSCalculator::getResult, python::arg("self"))
		.def("getFeatureVector", &Chem::LogSCalculator::getFeatureVector, python::arg("self"),
			 python::return_internal_reference<>())
		.add_property("result", &Chem::LogSCalculator::getResult)
		.def_readonly("FEATURE_VECTOR_SIZE", &Chem::LogSCalculator::FEATURE_VECTOR_SIZE);
}
