#
# This file is part of the Chemical Data Processing Toolkit
#
# Copyright (C) Thomas A. Seidel <thomas.seidel@univie.ac.at>
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program; see the file COPYING. If not, write to
# the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
# Boston, MA 02111-1307, USA.
#

##
# \brief 
#
class Vector3DArray(Boost.Python.instance):

    ##
    # \brief Initializes the \e %Vector3DArray instance.
    # \param self The \e %Vector3DArray instance to initialize.
    #
    def __init__(self: object) -> None: pass

    ##
    # \brief Initializes the \e %Vector3DArray instance.
    # \param self The \e %Vector3DArray instance to initialize.
    # \param array 
    #
    def __init__(self: object, array: Vector3DArray) -> None: pass

    ##
    # \brief Initializes the \e %Vector3DArray instance.
    # \param arg1 The \e %Vector3DArray instance to initialize.
    # \param a 
    #
    def __init__(arg1: object, a: object) -> None: pass

    ##
    # \brief Returns the numeric identifier (ID) of the wrapped C++ class instance.
    # \param self The \e %Vector3DArray instance this method is called upon.
    #
    # Different Python \e %Vector3DArray instances may reference the same underlying C++ class instance. The commonly used Python expression
    # <tt>a is not b</tt> thus cannot tell reliably whether the two \e %Vector3DArray instances \e a and \e b reference different C++ objects. 
    # The numeric identifier returned by this method allows to correctly implement such an identity test via the simple expression
    # <tt>a.getObjectID() != b.getObjectID()</tt>.
    #
    # \return The numeric ID of the internally referenced C++ class instance.
    #
    def getObjectID(self: Vector3DArray) -> int: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \return 
    #
    def getSize(self: Vector3DArray) -> int: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \return 
    #
    def isEmpty(self: Vector3DArray) -> bool: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param num_elem 
    # \param value 
    #
    def resize(self: Vector3DArray, num_elem: int, value: Vector3D) -> None: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param num_elem 
    #
    def reserve(self: Vector3DArray, num_elem: int) -> None: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \return 
    #
    def getCapacity(self: Vector3DArray) -> int: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    #
    def clear(self: Vector3DArray) -> None: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %Vector3DArray instance \a array.
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param array The \e %Vector3DArray instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: Vector3DArray, array: Vector3DArray) -> Vector3DArray: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %Vector3DArray instance \a num_elem.
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param num_elem The \e %Vector3DArray instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: Vector3DArray, num_elem: int, value: Vector3D) -> None: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %Vector3DArray instance \a a.
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param a The \e %Vector3DArray instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: Vector3DArray, a: object) -> None: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param value 
    #
    def addElement(self: Vector3DArray, value: Vector3D) -> None: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param values 
    #
    def addElements(self: Vector3DArray, values: Vector3DArray) -> None: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param idx 
    # \param value 
    #
    def insertElement(self: Vector3DArray, idx: int, value: Vector3D) -> None: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param idx 
    # \param num_elem 
    # \param value 
    #
    def insertElements(self: Vector3DArray, idx: int, num_elem: int, value: Vector3D) -> None: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param index 
    # \param values 
    #
    def insertElements(self: Vector3DArray, index: int, values: Vector3DArray) -> None: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    #
    def popLastElement(self: Vector3DArray) -> None: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param idx 
    #
    def removeElement(self: Vector3DArray, idx: int) -> None: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param begin_idx 
    # \param end_idx 
    #
    def removeElements(self: Vector3DArray, begin_idx: int, end_idx: int) -> None: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \return 
    #
    def getFirstElement(self: Vector3DArray) -> Vector3D: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \return 
    #
    def getLastElement(self: Vector3DArray) -> Vector3D: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param idx 
    # \return 
    #
    def getElement(self: Vector3DArray, idx: int) -> Vector3D: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param idx 
    # \param value 
    #
    def setElement(self: Vector3DArray, idx: int, value: Vector3D) -> None: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param as_vec 
    # \return 
    #
    def toArray(self: Vector3DArray, as_vec: bool) -> object: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param idx 
    #
    def __delitem__(self: Vector3DArray, idx: int) -> None: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param idx 
    # \return 
    #
    def __getitem__(self: Vector3DArray, idx: int) -> Vector3D: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \return 
    #
    def __len__(self: Vector3DArray) -> int: pass

    ##
    # \brief 
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param index 
    # \param value 
    #
    def __setitem__(self: Vector3DArray, index: int, value: Vector3D) -> None: pass

    ##
    # \brief Returns the result of the comparison operation <tt>self == array</tt>.
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param array The \e %Vector3DArray instance to be compared with.
    # \return The result of the comparison operation.
    #
    def __eq__(self: Vector3DArray, array: object) -> bool: pass

    ##
    # \brief Returns the result of the comparison operation <tt>self != array</tt>.
    # \param self The \e %Vector3DArray instance this method is called upon.
    # \param array The \e %Vector3DArray instance to be compared with.
    # \return The result of the comparison operation.
    #
    def __ne__(self: Vector3DArray, array: object) -> bool: pass

    ##
    # \brief 
    #
    objectID = property(getObjectID)

    ##
    # \brief 
    #
    size = property(getSize)