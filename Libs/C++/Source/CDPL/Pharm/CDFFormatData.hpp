/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * CDFFormatData.hpp
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


#ifndef CDPL_PHARM_CDFFORMATDATA_HPP
#define CDPL_PHARM_CDFFORMATDATA_HPP

#include "CDPL/Base/IntTypes.hpp"
#include "CDPL/Internal/CDFFormatData.hpp"


namespace CDPL
{

    namespace Pharm
    {

		namespace CDF
		{
			
			using namespace Internal::CDF;

			typedef Base::uint32 UIntType;
			typedef Base::int32  LongType;
			typedef Base::uint8  BoolType;

			const Base::uint8 PHARMACOPHORE_RECORD_ID  = 3;
			const Base::uint8 CURR_FORMAT_VERSION      = 1;

			namespace FeatureProperty
			{


				const unsigned int COORDINATES_3D           = 13;
		
			}
		
			namespace PharmacophoreProperty
			{
				
				const unsigned int NAME                     = 1; 
			}
		}
    }
}

#endif // CDPL_PHARM_CDFFORMATDATA_HPP