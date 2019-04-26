/* -*- mode: c++; c-basic-offset: 4; tab-width: 4; indent-tabs-mode: t -*- */

/* 
 * NumPy.hpp 
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


#ifndef CDPL_PYTHON_MATH_NUMPY_HPP
#define CDPL_PYTHON_MATH_NUMPY_HPP

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#define PY_ARRAY_UNIQUE_SYMBOL BOOST_NUMPY_ARRAY_API

#ifndef ENABLE_IMPORT_ARRAY_FUNCTION
# define NO_IMPORT_ARRAY
#endif

#include <numpy/ndarrayobject.h>


namespace CDPLPythonMath
{

	namespace NumPy 
	{

		template <std::size_t Size>
		struct FloatDataTypeNum {};

		template <>
		struct FloatDataTypeNum<4> 
		{

			static const int Value = NPY_FLOAT32;
		};

		template <>
		struct FloatDataTypeNum<8> 
		{

			static const int Value = NPY_FLOAT64;
		};

		template <>
		struct FloatDataTypeNum<16> 
		{

			static const int Value = NPY_FLOAT128;
		};


		template <std::size_t Size>
		struct IntDataTypeNum {};

		template <>
		struct IntDataTypeNum<4> 
		{

			static const int Value = NPY_INT32;
		};

		template <>
		struct IntDataTypeNum<8> 
		{

			static const int Value = NPY_INT64;
		};


		template <std::size_t Size>
		struct UIntDataTypeNum {};

		template <>
		struct UIntDataTypeNum<4> 
		{

			static const int Value = NPY_UINT32;
		};

		template <>
		struct UIntDataTypeNum<8> 
		{

			static const int Value = NPY_UINT64;
		};


		template <typename T>
		struct DataTypeNum {};

		template <>
		struct DataTypeNum<float> : public FloatDataTypeNum<sizeof(float)> {};

		template <>
		struct DataTypeNum<double> : public FloatDataTypeNum<sizeof(double)> {};

		template <>
		struct DataTypeNum<long double> : public FloatDataTypeNum<sizeof(long double)> {};

  
		template <>
		struct DataTypeNum<long int> : public IntDataTypeNum<sizeof(long int)> {}; 

		template <>
		struct DataTypeNum<int> : public IntDataTypeNum<sizeof(int)> {}; 

    
		template <>
		struct DataTypeNum<unsigned long int> : public UIntDataTypeNum<sizeof(unsigned long int)> {}; 

		template <>
		struct DataTypeNum<unsigned int> : public UIntDataTypeNum<sizeof(unsigned int)> {}; 


		bool init(); 
		bool available(); 
	}
}

#endif // CDPL_PYTHON_MATH_NUMPY_HPP