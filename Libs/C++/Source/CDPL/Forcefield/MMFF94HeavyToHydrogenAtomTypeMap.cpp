/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * MMFF94HeavyToHydrogenAtomTypeMap.cpp 
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

#include "CDPL/Config.hpp"

#include <cstring>
#include <sstream>

#if defined(HAVE_BOOST_IOSTREAMS)

#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/stream.hpp>

#endif // defined(HAVE_BOOST_IOSTREAMS)

#include "CDPL/Forcefield/MMFF94HeavyToHydrogenAtomTypeMap.hpp"
#include "CDPL/Base/Exceptions.hpp"

#include "MMFF94ParameterData.hpp"
#include "Utilities.hpp"


using namespace CDPL; 


namespace
{
 
    Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::SharedPointer builtinMap(new Forcefield::MMFF94HeavyToHydrogenAtomTypeMap());
    const std::string                                           NOT_FOUND;

    struct Init
    {

		Init() {
			builtinMap->loadDefaults();
		}

    } init;
}


Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::SharedPointer Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::defaultMap = builtinMap;


Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::MMFF94HeavyToHydrogenAtomTypeMap()
{}

void Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::addEntry(const std::string& parent_type, const std::string& hyd_type)
{
    entries.insert(DataStorage::value_type(parent_type, hyd_type));
}

const std::string& Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::getEntry(const std::string& parent_type) const
{
    DataStorage::const_iterator it = entries.find(parent_type);

    if (it == entries.end())
		return NOT_FOUND;

    return it->second;
}

void Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::clear()
{
    entries.clear();
}

Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::ConstEntryIterator 
Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::getEntriesBegin() const
{
    return entries.begin();
}

Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::ConstEntryIterator 
Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::getEntriesEnd() const
{
    return entries.end();
}

Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::EntryIterator 
Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::getEntriesBegin()
{
	return entries.begin();
}

Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::EntryIterator 
Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::getEntriesEnd()
{
	return entries.end();
}

bool Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::removeEntry(const std::string& parent_type)
{
	return entries.erase(parent_type);
}

Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::EntryIterator 
Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::removeEntry(const EntryIterator& it)
{
	return entries.erase(it);
}

void Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::load(std::istream& is)
{
    std::string line;
    std::string parent_type;
    std::string hyd_type;

    while (readMMFF94DataLine(is, line, "MMFF94HeavyToHydrogenAtomTypeMap: error while reading hydrogen atom type definition entry")) {
		std::istringstream line_iss(line);

		if (!(line_iss >> parent_type))
			throw Base::IOError("MMFF94HeavyToHydrogenAtomTypeMap: error while reading parent atom type");
		
		if (!(line_iss >> hyd_type))
			throw Base::IOError("MMFF94HeavyToHydrogenAtomTypeMap: error while reading hydrogen atom type");
	
		addEntry(parent_type, hyd_type);
    }
}

void Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::loadDefaults()
{

#if defined(HAVE_BOOST_IOSTREAMS)

    boost::iostreams::stream<boost::iostreams::array_source> is(MMFF94ParameterData::HYDROGEN_ATOM_TYPE_DEFINITIONS, 
																std::strlen(MMFF94ParameterData::HYDROGEN_ATOM_TYPE_DEFINITIONS));
#else // defined(HAVE_BOOST_IOSTREAMS)

	std::istringstream is(std::string(MMFF94ParameterData::HYDROGEN_ATOM_TYPE_DEFINITIONS);

#endif // defined(HAVE_BOOST_IOSTREAMS)

    load(is);
}

void Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::set(const SharedPointer& map)
{	
    defaultMap = (!map ? builtinMap : map);
}

const Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::SharedPointer& Forcefield::MMFF94HeavyToHydrogenAtomTypeMap::get()
{
    return defaultMap;
}