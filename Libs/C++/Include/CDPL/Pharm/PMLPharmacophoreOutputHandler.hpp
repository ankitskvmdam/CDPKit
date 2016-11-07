/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * PMLPharmacophoreOutputHandler.hpp 
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

/**
 * \file
 * \brief Definition of the class CDPL::Pharm::PMLPharmacophoreOutputHandler.
 */

#ifndef CDPL_PHARM_PMLPHARMACOPHOREOUTPUTHANDLER_HPP
#define CDPL_PHARM_PMLPHARMACOPHOREOUTPUTHANDLER_HPP

#include "CDPL/Pharm/APIPrefix.hpp"
#include "CDPL/Base/DataOutputHandler.hpp"


namespace CDPL 
{

	namespace Pharm
	{

		class Pharmacophore;

		/**
		 * \addtogroup CDPL_PHARM_PML_IO
		 * @{
		 */

		/**
		 * \brief A handler for the output of pharmacophore data in the native I/O format of <em>LigandScout</em>.
		 */
		class CDPL_PHARM_API PMLPharmacophoreOutputHandler : public Base::DataOutputHandler<Pharmacophore>
		{

		public:
			PMLPharmacophoreOutputHandler() {}

			const Base::DataFormat& getDataFormat() const;

			Base::DataWriter<Pharmacophore>::SharedPointer createWriter(std::ostream& os) const;
		};

		/**
		 * @}
		 */
	}
}

#endif // CDPL_PHARM_PMLPHARMACOPHOREOUTPUTHANDLER_HPP