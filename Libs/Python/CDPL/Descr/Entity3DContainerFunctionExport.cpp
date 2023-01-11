/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * Entity3DContainerFunctionExport.cpp 
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

#include "CDPL/Descr/Entity3DContainerFunctions.hpp"
#include "CDPL/Chem/Entity3DContainer.hpp"

#include "FunctionExports.hpp"
#include "FunctionWrapper.hpp"


namespace
{

	MAKE_FUNCTION_WRAPPER1(double, calcGeometricalRadius, CDPL::Chem::Entity3DContainer&);
	MAKE_FUNCTION_WRAPPER1(double, calcGeometricalDiameter, CDPL::Chem::Entity3DContainer&);
}


void CDPLPythonDescr::exportEntity3DContainerFunctions()
{
	using namespace boost;

	python::def("calcGeometricalRadius", &calcGeometricalRadiusWrapper1, python::arg("cntnr"));
	python::def("calcGeometricalDiameter", &calcGeometricalDiameterWrapper1, python::arg("cntnr"));
}