/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * FeatureGeometryMatchFunctor.hpp 
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
 * \brief Definition of the class CDPL::Pharm::FeatureGeometryMatchFunctor.
 */

#ifndef CDPL_PHARM_FEATUREGEOMETRYMATCHFUNCTOR_HPP
#define CDPL_PHARM_FEATUREGEOMETRYMATCHFUNCTOR_HPP

#include "CDPL/Pharm/APIPrefix.hpp"

#include "CDPL/Math/Matrix.hpp"


namespace CDPL 
{

    namespace Pharm
    {

		class Feature;

		/**
		 * \addtogroup CDPL_PHARM_FUNCTORS
		 * @{
		 */

		/**
		 * \brief FeatureGeometryMatchFunctor.
		 */
		class CDPL_PHARM_API FeatureGeometryMatchFunctor
		{

		  public:
			static const double DEF_HBA_ANGLE_TOLERANCE;
			static const double DEF_HBD_ANGLE_TOLERANCE;
			static const double DEF_AR_PLANE_ANGLE_TOLERANCE;

			FeatureGeometryMatchFunctor(bool strict_geom_mode, double hba_ang_tol = DEF_HBA_ANGLE_TOLERANCE, 
										double hbd_ang_tol = DEF_HBD_ANGLE_TOLERANCE,
										double ar_ang_tol = DEF_AR_PLANE_ANGLE_TOLERANCE):
		         strictMode(strict_geom_mode), hbaVecAngleTol(hba_ang_tol), 
		         hbdVecAngleTol(hbd_ang_tol), arPlaneAngleTol(ar_ang_tol) {}

			double getHBondAcceptorAngleTolerance() const;

			double getHBondDonorAngleTolerance() const;

			double getAromPlaneAngleTolerance() const;

			bool strictGeometryMatching() const;
		  
			/**
			 * \brief Checks if both \a ftr1 and \a ftr2 have the same feature geometry and calculates a score reflecting the goodness of their spatial match.
			 *
			 * If 'strict geometry matching' has been requested, the two features are required to have exactly the same geometry (if they do not, a score of \e 0 is returned).
			 * Only for features that both possess geometry Pharm::FeatureGeometry::PLANE or Pharm::FeatureGeometry::VECTOR a goodness of match score is calculated. If one of the
			 * features has a different geometry, a score of \e 1 is returned.
			 *
			 * \param ftr1 The first feature.
			 * \param ftr2 The second feature.
			 * \return A score from \e 0 (=spatial deviation outside the allowed range or incompatible geometries) and \e 1 (optimum spatial match) describing the 
			 *         goodness of the spatial match of the two features.
			 */
			double operator()(const Feature& ftr1, const Feature& ftr2) const;

			/**
			 * \brief Checks if both \a ftr1 and \a ftr2 have the same feature geometry and calculates a score reflecting the goodness of their spatial match.
			 *
			 * If 'strict geometry matching' has been requested, the two features are required to have exactly the same geometry (if they do not, a score of \e 0 is returned).
			 * Only for features that both possess geometry Pharm::FeatureGeometry::PLANE or Pharm::FeatureGeometry::VECTOR a goodness of match score is calculated. If one of the
			 * features has a different geometry, a score of \e 1 is returned.
			 *
			 * \param ftr1 The first feature.
			 * \param ftr2 The second feature.
			 * \param xform The transformation to apply to the geometrical attributes of the second feature.
			 * \return A score from \e 0 (=spatial deviation outside the allowed range or incompatible geometries) and \e 1 (optimum spatial match) describing the 
			 *         goodness of the spatial match of the two features.
			 */
			double operator()(const Feature& ftr1, const Feature& ftr2, const Math::Matrix4D& xform) const;

		  private:
			bool   strictMode;
			double hbaVecAngleTol;
			double hbdVecAngleTol;
			double arPlaneAngleTol;
		};

		/**
		 * @}
		 */
    }
}

#endif // CDPL_PHARM_FEATUREGEOMETRYMATCHFUNCTOR_HPP
