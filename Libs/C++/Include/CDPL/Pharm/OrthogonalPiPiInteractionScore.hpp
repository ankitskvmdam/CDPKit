/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * OrthogonalPiPiInteractionScore.hpp 
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
 * \brief Definition of the class CDPL::Pharm::OrthogonalPiPiInteractionScore.
 */

#ifndef CDPL_PHARM_ORTHOGONALPIPIINTERACTIONSCORE_HPP
#define CDPL_PHARM_ORTHOGONALPIPIINTERACTIONSCORE_HPP

#include <boost/function.hpp>

#include "CDPL/Pharm/APIPrefix.hpp"
#include "CDPL/Math/Vector.hpp"


namespace CDPL 
{

    namespace Pharm
    {

		class Feature;

		/**
		 * \brief OrthogonalPiPiInteractionScore.
		 */
		class CDPL_PHARM_API OrthogonalPiPiInteractionScore
		{

		  public:
			static const double DEF_MAX_H_DISTANCE;
			static const double DEF_MIN_V_DISTANCE;
			static const double DEF_MAX_V_DISTANCE;
			static const double DEF_ANGLE_TOLERANCE;

			typedef boost::function1<double, double> NormalizationFunction;

			/**
			 * \brief Constructs a \c %OrthogonalPiPiInteractionScore functor with the specified constraints.
			 * \param min_v_dist The minimum allowed distance of the vertically oriented aromatic ring to the plane of the horizontally oriented ring.
			 * \param max_v_dist The maximum allowed distance of the vertically oriented aromatic ring to the plane of the horizontally oriented ring.
			 * \param max_h_dist The maximum allowed distance of the ring-centers projected to the plane of the horizontally oriented aromatic ring.
			 * \param ang_tol The maximum allowed angle deviation from 90° of the two ring-plane orientation vectors.
			 */
			OrthogonalPiPiInteractionScore(double min_v_dist = DEF_MIN_V_DISTANCE, double max_v_dist = DEF_MAX_V_DISTANCE,
										   double max_h_dist = DEF_MAX_H_DISTANCE, double ang_tol = DEF_ANGLE_TOLERANCE);

			double getMinVDistance() const;

			double getMaxVDistance() const;

			double getMaxHDistance() const;

			double getAngleTolerance() const;

			void setNormalizationFunction(const NormalizationFunction& func);

			double operator()(const Feature& ftr1, const Feature& ftr2) const;

			double operator()(const Math::Vector3D& ftr1_pos, const Feature& ftr2) const;

		  private:
			double calcDistanceScore(const Math::Vector3D&, const Math::Vector3D&) const;

			double                minVDist;
			double                maxVDist;
			double                maxHDist;
			double                angleTol;
			NormalizationFunction normFunc;
		};
    }
}

#endif // CDPL_PHARM_ORTHOGONALPIPIINTERACTIONSCORE_HPP
