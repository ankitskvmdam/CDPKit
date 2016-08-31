/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * CDFDataReader.hpp 
 *
 * This file is part of the Pharmical Data Processing Toolkit
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


#ifndef CDPL_PHARM_CDFDATAREADER_HPP
#define CDPL_PHARM_CDFDATAREADER_HPP

#include <cstddef>
#include <iosfwd>

#include "CDPL/Pharm/CDFFormatData.hpp"

#include "CDPL/Internal/CDFDataReaderBase.hpp"
#include "CDPL/Internal/ByteBuffer.hpp"


namespace CDPL 
{

	namespace Base
	{

		class DataIOBase;
	}

	namespace Pharm
	{

		class Pharmacophore;
		class Feature;

		class CDFDataReader : private Internal::CDFDataReaderBase
		{

		public:
			CDFDataReader(const Base::DataIOBase& io_base): ioBase(io_base) {}

			virtual ~CDFDataReader() {}

			bool readPharmacophore(std::istream& is, Pharmacophore& pharm);

			bool skipPharmacophore(std::istream& is);

			bool hasMoreData(std::istream& is);

		private:
			void init();

			void readFeatures(Pharmacophore& pharm, std::size_t num_ftrs);
			void readPharmProperties(Pharmacophore& pharm);

			const Base::DataIOBase& ioBase;	
			Internal::ByteBuffer    dataBuffer;
			std::size_t             startFeatureIdx;
		};
	}
}

#endif // CDPL_PHARM_CDFDATAREADER_HPP