/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * ConformerGeneratorImpl.hpp 
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
 * \brief Definition of the class CDPL::ConfGen::ConformerGeneratorImpl.
 */

#ifndef CDPL_CONFGEN_CONFORMERGENERATORIMPL_HPP
#define CDPL_CONFGEN_CONFORMERGENERATORIMPL_HPP

#include <vector>
#include <cstddef>
#include <memory>

#include <boost/timer/timer.hpp>

#include "CDPL/ConfGen/ConformerGeneratorSettings.hpp"
#include "CDPL/ConfGen/ConformerDataArray.hpp"
#include "CDPL/ConfGen/CallbackFunction.hpp"
#include "CDPL/Chem/FragmentList.hpp"
#include "CDPL/ForceField/MMFF94InteractionParameterizer.hpp"
#include "CDPL/ForceField/MMFF94InteractionData.hpp"
#include "CDPL/Util/ObjectPool.hpp"
#include "CDPL/Util/ObjectStack.hpp"
#include "CDPL/Util/BitSet.hpp"

#include "TorsionDriverImpl.hpp"
#include "FragmentAssemblerImpl.hpp"
#include "ForceFieldInteractionMask.hpp"


namespace CDPL 
{

    namespace ConfGen 
    {
	
		class RMSDConformerSelector;

		class ConformerGeneratorImpl 
		{

		public:
			typedef ConformerDataArray::const_iterator ConstConformerIterator;

			ConformerGeneratorImpl();

			~ConformerGeneratorImpl();

			ConformerGeneratorSettings& getSettings();

			void clearFragmentLibraries();

			void addFragmentLibrary(const FragmentLibrary::SharedPointer& lib);

			void setTorsionLibrary(const TorsionLibrary::SharedPointer& lib);

			const TorsionLibrary::SharedPointer& getTorsionLibrary() const;

			void setAbortCallback(const CallbackFunction& func);

			const CallbackFunction& getAbortCallback() const;

			void setTimeoutCallback(const CallbackFunction& func);

			const CallbackFunction& getTimeoutCallback() const;

			unsigned int generate(const Chem::MolecularGraph& molgraph);

			std::size_t getNumConformers() const;

			ConformerData& getConformer(std::size_t idx);

			ConstConformerIterator getConformersBegin() const;

			ConstConformerIterator getConformersEnd() const;

		private:
			struct FragmentConfData;
			struct FragmentConfCombination;

			ConformerGeneratorImpl(const ConformerGeneratorImpl&);

			ConformerGeneratorImpl& operator=(const ConformerGeneratorImpl&);

			void init(const Chem::MolecularGraph& molgraph);

			void splitIntoTorsionFragments();
			
			bool setupMMFF94Parameters();
			
			unsigned int generateFragmentConformers();
			
			unsigned int generateFragmentConformerCombinations();
			void generateFragmentConformerCombinations(std::size_t frag_idx, double comb_energy);

			unsigned int generateConformers();

			unsigned int selectOutputConformers();

			double getMMFF94BondLength(std::size_t atom1_idx, std::size_t atom2_idx) const;

			static bool compFragmentConfCombinationEnergy(const FragmentConfCombination* comb1, 
														  const FragmentConfCombination* comb2);
			static bool compFragmentConfCount(const FragmentConfData* conf_data1, 
											  const FragmentConfData* conf_data2);

			unsigned int invokeCallbacks() const;
			bool timedout() const;

			typedef std::vector<std::size_t> UIntArray;

			struct FragmentConfData
			{

				Chem::Fragment::SharedPointer fragment;
				ConformerDataArray            conformers;
				std::size_t                   lastConfIdx;
				bool                          isFlexRingSys;

				void clear() {
					conformers.clear();
					fragment.reset();
				}
			};

			struct FragmentConfCombination
			{

				UIntArray   confIndices;
				double      energy;
				bool        valid;
			};

			typedef Util::ObjectStack<FragmentConfData> FragmentConfDataCache;
			typedef Util::ObjectStack<FragmentConfCombination> FragmentConfCombinationCache;
			typedef Util::ObjectPool<ConformerData> ConformerDataCache;
			typedef ForceField::MMFF94InteractionData MMFF94InteractionData;
			typedef ForceField::MMFF94InteractionParameterizer MMFF94Parameterizer;
			typedef std::vector<const Chem::Bond*> BondList;
			typedef std::vector<FragmentConfData*> FragmentConfDataList;
			typedef std::vector<FragmentConfCombination*> FragmentConfCombinationList;
			typedef std::auto_ptr<RMSDConformerSelector> RMSDConformerSelectorPtr;

			ConformerDataCache           confDataCache;
			FragmentConfDataCache        fragConfDataCache;
			FragmentConfCombinationCache fragConfCombCache;
			ConformerGeneratorSettings   settings;
			const Chem::MolecularGraph*  molGraph;
			ConformerDataArray           workingConfs;
			ConformerDataArray           tmpWorkingConfs;
			ConformerDataArray           outputConfs;
			CallbackFunction             abortCallback;
			CallbackFunction             timeoutCallback;
			boost::timer::cpu_timer      timer;
			RMSDConformerSelectorPtr     confSelector;
			TorsionDriverImpl            torDriver;
			FragmentAssemblerImpl        fragAssembler;
			MMFF94Parameterizer          mmff94Parameterizer;
			MMFF94InteractionData        mmff94Data;
			ForceFieldInteractionMask    mmff94InteractionMask;
			BondList                     torDriveBonds;
			BondList                     fragSplitBonds;
			Chem::FragmentList           fragments;
			Util::BitSet                 tmpBitSet;
			Util::BitSet                 invertibleNMask;
			Util::BitSet                 fixedAtomConfigMask;
			FragmentConfDataList         torFragConfDataList;
			FragmentConfCombinationList  torFragConfCombList;
			UIntArray                    currConfComb;
		};
    }
}

#endif // CDPL_CONFGEN_CONFORMERGENERATORIMPL_HPP