/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * BuriednessScoreExport.cpp 
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

#include "CDPL/GRAILS/BuriednessScore.hpp"
#include "CDPL/Chem/AtomContainer.hpp"

#include "Base/ObjectIdentityCheckVisitor.hpp"
#include "Base/CopyAssOp.hpp"

#include "ClassExports.hpp"


namespace
{

    double callOperator(CDPL::GRAILS::BuriednessScore& func, const CDPL::Math::Vector3D& pos, 
						CDPL::Chem::AtomContainer& atoms)
    {
		return func(pos, atoms);
    }
}


void CDPLPythonGRAILS::exportBuriednessScore()
{
    using namespace boost;
    using namespace CDPL;

    python::class_<GRAILS::BuriednessScore, boost::noncopyable>("BuriednessScore", python::no_init)
		.def(python::init<const GRAILS::BuriednessScore&>((python::arg("self"), python::arg("score"))))
		.def(python::init<double, double, double>((python::arg("self"), python::arg("probe_radius") = GRAILS::BuriednessScore::DEF_PROBE_RADIUS,
												   python::arg("min_vdw_surf_dist") = GRAILS::BuriednessScore::DEF_MIN_VDW_SURFACE_DISTANCE,
												   python::arg("num_test_rays") = GRAILS::BuriednessScore::DEF_NUM_TEST_RAYS)))
		.def(CDPLPythonBase::ObjectIdentityCheckVisitor<GRAILS::BuriednessScore>())
		.def("setMinVdWSurfaceDistance", &GRAILS::BuriednessScore::setMinVdWSurfaceDistance, (python::arg("self"), python::arg("dist")))
		.def("getMinVdWSurfaceDistance", &GRAILS::BuriednessScore::getMinVdWSurfaceDistance, python::arg("self"))
		.def("setProbeRadius", &GRAILS::BuriednessScore::setProbeRadius, (python::arg("self"), python::arg("radius")))
		.def("getProbeRadius", &GRAILS::BuriednessScore::getProbeRadius, python::arg("self"))
		.def("setNumTestRays", &GRAILS::BuriednessScore::setNumTestRays, (python::arg("self"), python::arg("num_rays")))
		.def("getNumTestRays", &GRAILS::BuriednessScore::getNumTestRays, python::arg("self"))
		.def("setAtom3DCoordinatesFunction", &GRAILS::BuriednessScore::setAtom3DCoordinatesFunction,
			 (python::arg("self"), python::arg("func")))
		.def("getAtom3DCoordinatesFunction", &GRAILS::BuriednessScore::getAtom3DCoordinatesFunction,
			 python::arg("self"), python::return_internal_reference<>())
		.def("assign", CDPLPythonBase::copyAssOp(&GRAILS::BuriednessScore::operator=), 
			 (python::arg("self"), python::arg("score")), python::return_self<>())
		.def("__call__", &callOperator, (python::arg("self"), python::arg("pos"), python::arg("atoms")))
		.add_property("probeRadius", &GRAILS::BuriednessScore::getProbeRadius, &GRAILS::BuriednessScore::setProbeRadius)
		.add_property("minVdWSurfaceDistance", &GRAILS::BuriednessScore::getMinVdWSurfaceDistance, 
					  &GRAILS::BuriednessScore::setMinVdWSurfaceDistance)
		.add_property("numTestRays", &GRAILS::BuriednessScore::getNumTestRays, &GRAILS::BuriednessScore::setNumTestRays)
		.add_property("atomCoordinatesFunction", 
					  python::make_function(&GRAILS::BuriednessScore::getAtom3DCoordinatesFunction, python::return_internal_reference<>()),
					  &GRAILS::BuriednessScore::setAtom3DCoordinatesFunction)
		.def_readonly("DEF_NUM_TEST_RAYS", GRAILS::BuriednessScore::DEF_NUM_TEST_RAYS)
		.def_readonly("DEF_PROBE_RADIUS", GRAILS::BuriednessScore::DEF_PROBE_RADIUS);
}
