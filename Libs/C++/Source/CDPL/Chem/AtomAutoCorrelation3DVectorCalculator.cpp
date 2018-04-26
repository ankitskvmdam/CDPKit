/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * AtomAutoCorrelation3DVectorCalculator.cpp 
 *
 * This file is part of the Chemical Data Processing Toolkit
 *
 * Copyright (C) 2003-2010 Thomas A. Seidel <thomas.seidel@univie.ac.at>
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


#include "StaticInit.hpp"

#include "CDPL/Chem/AtomAutoCorrelation3DVectorCalculator.hpp"
#include "CDPL/Chem/Entity3DFunctions.hpp"
#include "CDPL/Chem/AtomContainer.hpp"
#include "CDPL/Chem/Atom.hpp"


using namespace CDPL;


CDPL::Chem::AtomAutoCorrelation3DVectorCalculator::AtomAutoCorrelation3DVectorCalculator()
{
    setEntity3DCoordinatesFunction(&get3DCoordinates);
} 

CDPL::Chem::AtomAutoCorrelation3DVectorCalculator::AtomAutoCorrelation3DVectorCalculator(const AtomContainer& cntnr, Math::DVector& vec)
{
    setEntity3DCoordinatesFunction(&get3DCoordinates);
    calculate(cntnr, vec);
}

void CDPL::Chem::AtomAutoCorrelation3DVectorCalculator::calculate(const AtomContainer& cntnr, Math::DVector& vec)
{
    vec.resize(getNumSteps(), false);

    AutoCorrelation3DVectorCalculator::calculate(cntnr.getAtomsBegin(), cntnr.getAtomsEnd(), vec);
}