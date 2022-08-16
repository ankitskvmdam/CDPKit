/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * MassCompositionExport.cpp 
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

#include "CDPL/Chem/MassComposition.hpp"

#include "Util/MapVisitor.hpp"

#include "ClassExports.hpp"


void CDPLPythonChem::exportMassComposition()
{
	using namespace boost;
	using namespace CDPL;

	python::class_<Chem::MassComposition, Chem::MassComposition::SharedPointer>("MassComposition", python::no_init)
		.def(python::init<>(python::arg("self")))
		.def(python::init<const Chem::MassComposition&>((python::arg("self"), python::arg("mass_comp"))))
		.def(CDPLPythonUtil::MapVisitor<Chem::MassComposition, 
			 python::return_value_policy<python::copy_non_const_reference>, 
			 python::default_call_policies, python::default_call_policies, python::default_call_policies, false>())
		.def("__eq__", &Chem::MassComposition::operator==, (python::arg("self"), python::arg("mass_comp")))
		.def("__ne__", &Chem::MassComposition::operator!=, (python::arg("self"), python::arg("mass_comp")))
		.def("__le__", &Chem::MassComposition::operator<=, (python::arg("self"), python::arg("mass_comp")))
		.def("__ge__", &Chem::MassComposition::operator>=, (python::arg("self"), python::arg("mass_comp")))
		.def("__lt__", &Chem::MassComposition::operator<, (python::arg("self"), python::arg("mass_comp")))
		.def("__gt__", &Chem::MassComposition::operator>, (python::arg("self"), python::arg("mass_comp")));
}
