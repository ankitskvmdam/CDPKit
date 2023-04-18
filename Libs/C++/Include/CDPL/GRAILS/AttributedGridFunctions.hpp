/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * AttributedGridFunctions.hpp 
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

/**
 * \file
 * \brief Declaration of functions that operate on Grid::AttributedGrid instances.
 */

#ifndef CDPL_GRAILS_ATTRIBUTEDGRIDFUNCTIONS_HPP
#define CDPL_GRAILS_ATTRIBUTEDGRIDFUNCTIONS_HPP

#include "CDPL/GRAILS/APIPrefix.hpp"


namespace CDPL 
{

    namespace Grid
    {

		class AttributedGrid;
    }

    namespace GRAILS 
    {
	
		CDPL_GRAILS_API unsigned int getFeatureType(const Grid::AttributedGrid& grid);

		CDPL_GRAILS_API void setFeatureType(Grid::AttributedGrid& grid, unsigned int type);

		CDPL_GRAILS_API void clearFeatureType(Grid::AttributedGrid& grid);

		CDPL_GRAILS_API bool hasFeatureType(const Grid::AttributedGrid& grid);


		CDPL_GRAILS_API unsigned int getTargetFeatureType(const Grid::AttributedGrid& grid);

		CDPL_GRAILS_API void setTargetFeatureType(Grid::AttributedGrid& grid, unsigned int type);

		CDPL_GRAILS_API void clearTargetFeatureType(Grid::AttributedGrid& grid);

		CDPL_GRAILS_API bool hasTargetFeatureType(const Grid::AttributedGrid& grid);
    }
}

#endif // CDPL_GRAILS_ATTRIBUTEDGRIDFUNCTIONS_HPP