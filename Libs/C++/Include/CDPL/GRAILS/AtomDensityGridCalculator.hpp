/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * AtomDensityGridCalculator.hpp 
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
 * \brief Definition of the class CDPL::GRAILS::AtomDensityGridCalculator.
 */

#ifndef CDPL_GRAILS_ATOMDENSITYGRIDCALCULATOR_HPP
#define CDPL_GRAILS_ATOMDENSITYGRIDCALCULATOR_HPP

#include <vector>
#include <cstddef>

#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>

#include "CDPL/GRAILS/APIPrefix.hpp"
#include "CDPL/Math/Vector.hpp"
#include "CDPL/Math/VectorArray.hpp"
#include "CDPL/Chem/Atom3DCoordinatesFunction.hpp"
#include "CDPL/Grid/SpatialGrid.hpp"


namespace CDPL 
{

	namespace Internal 
	{

		template <typename PT, typename CT, typename ST> class Octree;
	}

	namespace Chem
	{

		class AtomContainer;
	}
	
    namespace GRAILS
    {

		/**
		 * \brief AtomDensityGridCalculator.
		 */
		class CDPL_GRAILS_API AtomDensityGridCalculator
		{

		  public:
			static const double DEF_DISTANCE_CUTOFF;

			typedef boost::shared_ptr<AtomDensityGridCalculator> SharedPointer;

			typedef boost::function3<double, const Math::Vector3D&, const Math::Vector3D&, const Chem::Atom&> DensityFunction;
			typedef boost::function1<double, const Math::DVector&> DensityCombinationFunction;

			AtomDensityGridCalculator();

			AtomDensityGridCalculator(const AtomDensityGridCalculator& calc);

			AtomDensityGridCalculator(const DensityFunction& func);

			AtomDensityGridCalculator(const DensityFunction& density_func, const DensityCombinationFunction& comb_func); 

			void setDistanceCutoff(double dist);

			double getDistanceCutoff() const;

			void setDensityFunction(const DensityFunction& func);

			const DensityFunction& getDensityFunction() const;

			void setDensityCombinationFunction(const DensityCombinationFunction& func);

			const DensityCombinationFunction& getDensityCombinationFunction() const;

			/**
			 * \brief Specifies a function for the retrieval of atom 3D-coordinates for grid calculation.
			 * \param func The atom 3D-coordinates function.
			 */
			void setAtom3DCoordinatesFunction(const Chem::Atom3DCoordinatesFunction& func);

			const Chem::Atom3DCoordinatesFunction& getAtom3DCoordinatesFunction() const;

			void calculate(const Chem::AtomContainer& atoms, Grid::DSpatialGrid& grid);

			AtomDensityGridCalculator& operator=(const AtomDensityGridCalculator& calc);

		  private:
			typedef Internal::Octree<Math::Vector3D, Math::Vector3DArray, double> Octree;
			typedef boost::shared_ptr<Octree> OctreePtr;
			typedef std::vector<std::size_t> AtomIndexList;

			Math::DVector                    partialDensities;
			DensityFunction                  densityFunc;
			DensityCombinationFunction       densityCombinationFunc;
			Chem::Atom3DCoordinatesFunction  coordsFunc;
			double                           distCutoff;
			OctreePtr                        octree;
			Math::Vector3DArray              atomCoords;
			AtomIndexList                    atomIndices;
		};
    }
}

#endif // CDPL_GRAILS_ATOMDENSITYGRIDCALCULATOR_HPP