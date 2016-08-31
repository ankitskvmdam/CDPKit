/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * MolecularGraphFunctions.hpp 
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
 * \brief Declaration of functions that operate on Chem::MolecularGraph instances.
 */

#ifndef CDPL_BIOMOL_MOLECULARGRAPHFUNCTIONS_HPP
#define CDPL_BIOMOL_MOLECULARGRAPHFUNCTIONS_HPP

#include <string>
#include <cstddef>

#include "CDPL/Biomol/APIPrefix.hpp"
#include "CDPL/Biomol/PDBData.hpp"
#include "CDPL/Biomol/AtomPropertyFlag.hpp"
#include "CDPL/Chem/Fragment.hpp"


namespace CDPL 
{

	namespace Chem
	{
	
		class MolecularGraph;
	}

	namespace Biomol 
	{

		/**
		 * \addtogroup CDPL_BIOMOL_MOLECULAR_GRAPH_FUNCTIONS
		 * @{
		 */

		CDPL_BIOMOL_API const std::string& getResidueCode(const Chem::MolecularGraph& molgraph);

		CDPL_BIOMOL_API void setResidueCode(Chem::MolecularGraph& molgraph, const std::string& code);

		CDPL_BIOMOL_API void clearResidueCode(Chem::MolecularGraph& molgraph);

		CDPL_BIOMOL_API bool hasResidueCode(const Chem::MolecularGraph& molgraph);


		CDPL_BIOMOL_API std::size_t getResidueSequenceNumber(const Chem::MolecularGraph& molgraph);

		CDPL_BIOMOL_API void setResidueSequenceNumber(Chem::MolecularGraph& molgraph, std::size_t seq_no);

		CDPL_BIOMOL_API void clearResidueSequenceNumber(Chem::MolecularGraph& molgraph);

		CDPL_BIOMOL_API bool hasResidueSequenceNumber(const Chem::MolecularGraph& molgraph);


		CDPL_BIOMOL_API char getResidueInsertionCode(const Chem::MolecularGraph& molgraph);

		CDPL_BIOMOL_API void setResidueInsertionCode(Chem::MolecularGraph& molgraph, char code);

		CDPL_BIOMOL_API void clearResidueInsertionCode(Chem::MolecularGraph& molgraph);

		CDPL_BIOMOL_API bool hasResidueInsertionCode(const Chem::MolecularGraph& molgraph);


		CDPL_BIOMOL_API char getChainID(const Chem::MolecularGraph& molgraph);

		CDPL_BIOMOL_API void setChainID(Chem::MolecularGraph& molgraph, char id);

		CDPL_BIOMOL_API void clearChainID(Chem::MolecularGraph& molgraph);

		CDPL_BIOMOL_API bool hasChainID(const Chem::MolecularGraph& molgraph);


		CDPL_BIOMOL_API std::size_t getModelNumber(const Chem::MolecularGraph& molgraph);

		CDPL_BIOMOL_API void setModelNumber(Chem::MolecularGraph& molgraph, std::size_t model_no);

		CDPL_BIOMOL_API void clearModelNumber(Chem::MolecularGraph& molgraph);

		CDPL_BIOMOL_API bool hasModelNumber(const Chem::MolecularGraph& molgraph);
	

		CDPL_BIOMOL_API const PDBData::SharedPointer& getPDBData(const Chem::MolecularGraph& molgraph);

		CDPL_BIOMOL_API void setPDBData(Chem::MolecularGraph& molgraph, const PDBData::SharedPointer& data);

		CDPL_BIOMOL_API void clearPDBData(Chem::MolecularGraph& molgraph);
	
		CDPL_BIOMOL_API bool hasPDBData(const Chem::MolecularGraph& molgraph);


		CDPL_CHEM_API void extractProximalAtoms(const Chem::MolecularGraph& core, const Chem::MolecularGraph& macromol, Chem::Fragment& env_atoms, double max_dist);

		CDPL_BIOMOL_API void extractEnvironmentResidues(const Chem::MolecularGraph& core, const Chem::MolecularGraph& macromol, Chem::Fragment& env_residues, double max_dist);

		CDPL_BIOMOL_API void setHydrogenResidueSequenceInfo(Chem::MolecularGraph& molgraph, bool overwrite, unsigned int flags = AtomPropertyFlag::DEFAULT);

		/**
		 * @}
		 */
	}
}

#endif // CDPL_BIOMOL_MOLECULARGRAPHFUNCTIONS_HPP
 