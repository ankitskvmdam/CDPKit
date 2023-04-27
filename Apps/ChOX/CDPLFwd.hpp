/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * CDPLFwd.hpp 
 *
 * This file is part of the Chemical Data Processing Toolkit
 *
 * Copyright (C) 2003-2020 Thomas A. Seidel <thomas.seidel@univie.ac.at>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; see the file COPYING. If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#ifndef CHOX_CDPLFWD_HPP
#define CHOX_CDPLFWD_HPP


namespace CDPL
{

	namespace Chem
	{

		class Molecule;
		class Reaction;
	}

	namespace Base
	{

		class PropertyContainer;
		class ControlParameterContainer;
		class LookupKey;
		class Variant;
		class Exception;
		class DataFormat;
	}

	namespace Vis
	{

		class View2D;
		class StructureView2D;
		class ReactionView2D;
		class Renderer2D;
		class Font;
		class Color;
		class SizeSpecification;
		class QtFontMetrics;
	}
}

#endif // CHOX_CDPLFWD_HPP
