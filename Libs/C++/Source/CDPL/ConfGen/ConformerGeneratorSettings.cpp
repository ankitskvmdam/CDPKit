/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * ConformerGeneratorSettings.cpp 
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

#include "CDPL/ConfGen/ConformerGeneratorSettings.hpp"
#include "CDPL/ConfGen/ForceFieldType.hpp"
#include "CDPL/ConfGen/NitrogenEnumerationMode.hpp"


using namespace CDPL;


const ConfGen::ConformerGeneratorSettings ConfGen::ConformerGeneratorSettings::DEFAULT;


ConfGen::ConformerGeneratorSettings::ConformerGeneratorSettings():
	sampleHetAtomHs(false), enumRings(true), nitrogenEnumMode(NitrogenEnumerationMode::UNSPECIFIED_STEREO),
	fromScratch(true), outputSupplCoords(false), eWindow(10.0), timeout(30 * 60 * 1000), 
	forceFieldType(ForceFieldType::MMFF94S_NO_ESTAT), strictParam(true), maxNumOutputConfs(100), 
	minRMSD(0.5)
{}

void ConfGen::ConformerGeneratorSettings::sampleHeteroAtomHydrogens(bool sample)
{
	sampleHetAtomHs = sample;
}
				
bool ConfGen::ConformerGeneratorSettings::sampleHeteroAtomHydrogens() const
{
	return sampleHetAtomHs;
}

void ConfGen::ConformerGeneratorSettings::enumerateRings(bool enumerate)
{
	enumRings = enumerate;
}

bool ConfGen::ConformerGeneratorSettings::enumerateRings() const
{
	return enumRings;
}

void ConfGen::ConformerGeneratorSettings::setNitrogenEnumerationMode(unsigned int mode)
{
	nitrogenEnumMode = mode;
}

unsigned int ConfGen::ConformerGeneratorSettings::getNitrogenEnumerationMode() const
{
	return nitrogenEnumMode;
}

void ConfGen::ConformerGeneratorSettings::generateCoordinatesFromScratch(bool generate)
{
	fromScratch = generate;
}
	
bool ConfGen::ConformerGeneratorSettings::generateCoordinatesFromScratch() const
{
	return fromScratch;
}

void ConfGen::ConformerGeneratorSettings::outputSuppliedCoordinates(bool output)
{
	outputSupplCoords = output;
}
	
bool ConfGen::ConformerGeneratorSettings::outputSuppliedCoordinates() const
{
	return outputSupplCoords;
}

void ConfGen::ConformerGeneratorSettings::setEnergyWindow(double win_size)
{
	eWindow = win_size;
}

double ConfGen::ConformerGeneratorSettings::getEnergyWindow() const
{
	return eWindow;
}

void ConfGen::ConformerGeneratorSettings::setTimeout(std::size_t mil_secs)
{
	timeout = mil_secs;
}

std::size_t ConfGen::ConformerGeneratorSettings::getTimeout() const
{
	return timeout;
}

void ConfGen::ConformerGeneratorSettings::setForceFieldType(unsigned int type)
{
	forceFieldType = type;
}
	    
unsigned int ConfGen::ConformerGeneratorSettings::getForceFieldType() const
{
	return forceFieldType;
}
			
void ConfGen::ConformerGeneratorSettings::strictForceFieldParameterization(bool strict)
{
	strictParam = strict;
}

bool ConfGen::ConformerGeneratorSettings::strictForceFieldParameterization() const
{
	return strictParam;
}
			
void ConfGen::ConformerGeneratorSettings::setMaxNumOutputConformers(std::size_t max_num)
{
	maxNumOutputConfs = max_num;
}

std::size_t ConfGen::ConformerGeneratorSettings::getMaxNumOutputConformers() const
{
	return maxNumOutputConfs;
}

void ConfGen::ConformerGeneratorSettings::setMinRMSD(double min_rmsd)
{
	minRMSD = min_rmsd;
}

double ConfGen::ConformerGeneratorSettings::getMinRMSD() const
{
	return minRMSD;
}

ConfGen::FragmentConformerGeneratorSettings& ConfGen::ConformerGeneratorSettings::getFragmentBuildSettings()
{
	return fragBuildSettings;
}

const ConfGen::FragmentConformerGeneratorSettings& ConfGen::ConformerGeneratorSettings::getFragmentBuildSettings() const
{
	return fragBuildSettings;
}