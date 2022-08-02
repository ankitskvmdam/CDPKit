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
class FVector(Boost.Python.instance):

    ##
    # \brief Initializes the \e %FVector instance.
    # \param self The \e %FVector instance to initialize.
    #
    def __init__(self: object) -> None: pass

    ##
    # \brief Initializes the \e %FVector instance.
    # \param self The \e %FVector instance to initialize.
    # \param v 
    #
    def __init__(self: object, v: FVector) -> None: pass

    ##
    # \brief Initializes the \e %FVector instance.
    # \param self The \e %FVector instance to initialize.
    # \param n 
    #
    def __init__(self: object, n: int) -> None: pass

    ##
    # \brief Initializes the \e %FVector instance.
    # \param self The \e %FVector instance to initialize.
    # \param n 
    # \param v 
    #
    def __init__(self: object, n: int, v: float) -> None: pass

    ##
    # \brief Initializes the \e %FVector instance.
    # \param arg1 The \e %FVector instance to initialize.
    # \param e 
    #
    def __init__(arg1: object, e: ConstFVectorExpression) -> None: pass

    ##
    # \brief Initializes the \e %FVector instance.
    # \param arg1 The \e %FVector instance to initialize.
    # \param e 
    #
    def __init__(arg1: object, e: ConstDVectorExpression) -> None: pass

    ##
    # \brief Initializes the \e %FVector instance.
    # \param arg1 The \e %FVector instance to initialize.
    # \param e 
    #
    def __init__(arg1: object, e: ConstLVectorExpression) -> None: pass

    ##
    # \brief Initializes the \e %FVector instance.
    # \param arg1 The \e %FVector instance to initialize.
    # \param e 
    #
    def __init__(arg1: object, e: ConstULVectorExpression) -> None: pass

    ##
    # \brief Initializes the \e %FVector instance.
    # \param arg1 The \e %FVector instance to initialize.
    # \param a 
    #
    def __init__(arg1: object, a: object) -> None: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \param n 
    # \param v 
    #
    def resize(self: FVector, n: int, v: float = 0.0) -> None: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \param v 
    #
    def clear(self: FVector, v: float = 0.0) -> None: pass

    ##
    # \brief Returns the numeric identifier (ID) of the wrapped C++ class instance.
    # \param self The \e %FVector instance this method is called upon.
    #
    # Different Python \e %FVector instances may reference the same underlying C++ class instance. The commonly used Python expression
    # <tt>a is not b</tt> thus cannot tell reliably whether the two \e %FVector instances \e a and \e b reference different C++ objects. 
    # The numeric identifier returned by this method allows to correctly implement such an identity test via the simple expression
    # <tt>a.getObjectID() != b.getObjectID()</tt>.
    #
    # \return The numeric ID of the internally referenced C++ class instance.
    #
    def getObjectID(self: FVector) -> int: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %FVector instance \a e.
    # \param self The \e %FVector instance this method is called upon.
    # \param e The \e %FVector instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: FVector, e: ConstFVectorExpression) -> FVector: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %FVector instance \a e.
    # \param self The \e %FVector instance this method is called upon.
    # \param e The \e %FVector instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: FVector, e: ConstDVectorExpression) -> FVector: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %FVector instance \a e.
    # \param self The \e %FVector instance this method is called upon.
    # \param e The \e %FVector instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: FVector, e: ConstLVectorExpression) -> FVector: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %FVector instance \a e.
    # \param self The \e %FVector instance this method is called upon.
    # \param e The \e %FVector instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: FVector, e: ConstULVectorExpression) -> FVector: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %FVector instance \a v.
    # \param self The \e %FVector instance this method is called upon.
    # \param v The \e %FVector instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: FVector, v: FVector) -> FVector: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %FVector instance \a a.
    # \param self The \e %FVector instance this method is called upon.
    # \param a The \e %FVector instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: FVector, a: object) -> None: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \return 
    #
    def isEmpty(self: FVector) -> bool: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \return 
    #
    def getSize(self: FVector) -> int: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \param i 
    # \return 
    #
    def getElement(self: FVector, i: int) -> float: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \return 
    #
    def toArray(self: FVector) -> object: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \param v 
    #
    def swap(self: FVector, v: FVector) -> None: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \param i 
    # \param v 
    #
    def setElement(self: FVector, i: int, v: float) -> None: pass

    ##
    # \brief Returns the result of the comparison operation <tt>self == v</tt>.
    # \param self The \e %FVector instance this method is called upon.
    # \param v The \e %FVector instance to be compared with.
    # \return The result of the comparison operation.
    #
    def __eq__(self: FVector, v: FVector) -> bool: pass

    ##
    # \brief Returns the result of the comparison operation <tt>self == e</tt>.
    # \param self The \e %FVector instance this method is called upon.
    # \param e The \e %FVector instance to be compared with.
    # \return The result of the comparison operation.
    #
    def __eq__(self: FVector, e: ConstFVectorExpression) -> bool: pass

    ##
    # \brief Returns the result of the comparison operation <tt>self != v</tt>.
    # \param self The \e %FVector instance this method is called upon.
    # \param v The \e %FVector instance to be compared with.
    # \return The result of the comparison operation.
    #
    def __ne__(self: FVector, v: FVector) -> bool: pass

    ##
    # \brief Returns the result of the comparison operation <tt>self != e</tt>.
    # \param self The \e %FVector instance this method is called upon.
    # \param e The \e %FVector instance to be compared with.
    # \return The result of the comparison operation.
    #
    def __ne__(self: FVector, e: ConstFVectorExpression) -> bool: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \param i 
    # \return 
    #
    def __call__(self: FVector, i: int) -> float: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \param i 
    # \return 
    #
    def __getitem__(self: FVector, i: int) -> float: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \return 
    #
    def __len__(self: FVector) -> int: pass

    ##
    # \brief Returns a string representation of the \e %FVector instance.
    # \param self The \e %FVector instance this method is called upon.
    # \return The generated string representation.
    #
    def __str__(self: FVector) -> str: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \return 
    #
    def __pos__(self: FVector) -> FVector: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \return 
    #
    def __neg__(self: object) -> ConstFVectorExpression: pass

    ##
    # \brief Returns the result of the addition operation <tt>self + e</tt>.
    # \param self The \e %FVector instance representing the first addend.
    # \param e Specifies the second addend.
    # \return A \e %FVector instance holding the result of the addition.
    #
    def __add__(self: object, e: ConstFVectorExpression) -> ConstFVectorExpression: pass

    ##
    # \brief Returns the result of the subtraction operation <tt>self - e</tt>.
    # \param self The \e %FVector instance acting as minuend.
    # \param e Specifies the subtrahend.
    # \return A \e %FVector instance holding the result of the subtraction.
    #
    def __sub__(self: object, e: ConstFVectorExpression) -> ConstFVectorExpression: pass

    ##
    # \brief Returns the result of the multiplication operation <tt>self * t</tt>.
    # \param self The \e %FVector instance acting as multiplicand.
    # \param t Specifies the multiplier.
    # \return A \e %FVector instance holding the result of the multiplication.
    #
    def __mul__(self: object, t: float) -> ConstFVectorExpression: pass

    ##
    # \brief Returns the result of the multiplication operation <tt>self * e</tt>.
    # \param self The \e %FVector instance acting as multiplicand.
    # \param e Specifies the multiplier.
    # \return A \e %FVector instance holding the result of the multiplication.
    #
    def __mul__(self: object, e: ConstFMatrixExpression) -> ConstFVectorExpression: pass

    ##
    # \brief Returns the result of the division operation <tt>self / t</tt>.
    # \param self The \e %FVector instance acting as dividend.
    # \param t Specifies the divisor.
    # \return A \e %FVector instance holding the result of the division.
    #
    def __div__(self: object, t: float) -> ConstFVectorExpression: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \param t 
    # \return 
    #
    def __truediv__(self: object, t: float) -> ConstFVectorExpression: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \param t 
    # \return 
    #
    def __rmul__(self: object, t: float) -> ConstFVectorExpression: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \param i 
    # \param v 
    #
    def __setitem__(self: FVector, i: int, v: float) -> None: pass

    ##
    # \brief Performs the in-place addition operation <tt>self += v</tt>.
    # \param self The \e %FVector instance acting as in-place addend.
    # \param v Specifies the second addend.
    # \return The updated \e %FVector instance \a self.
    #
    def __iadd__(self: FVector, v: FVector) -> FVector: pass

    ##
    # \brief Performs the in-place addition operation <tt>self += e</tt>.
    # \param self The \e %FVector instance acting as in-place addend.
    # \param e Specifies the second addend.
    # \return The updated \e %FVector instance \a self.
    #
    def __iadd__(self: FVector, e: ConstFVectorExpression) -> FVector: pass

    ##
    # \brief Performs the in-place subtraction operation <tt>self -= v</tt>.
    # \param self The \e %FVector instance acting as in-place minuend.
    # \param v Specifies the subtrahend.
    # \return The updated \e %FVector instance \a self.
    #
    def __isub__(self: FVector, v: FVector) -> FVector: pass

    ##
    # \brief Performs the in-place subtraction operation <tt>self -= e</tt>.
    # \param self The \e %FVector instance acting as in-place minuend.
    # \param e Specifies the subtrahend.
    # \return The updated \e %FVector instance \a self.
    #
    def __isub__(self: FVector, e: ConstFVectorExpression) -> FVector: pass

    ##
    # \brief Performs the in-place multiplication operation <tt>self *= t</tt>.
    # \param self The \e %FVector instance acting as in-place multiplicand.
    # \param t Specifies the multiplier.
    # \return The updated \e %FVector instance \a self.
    #
    def __imul__(self: FVector, t: float) -> FVector: pass

    ##
    # \brief Performs the in-place division operation <tt>self /= t</tt>.
    # \param self The \e %FVector instance acting as in-place dividend.
    # \param t Specifies the divisor.
    # \return The updated \e %FVector instance \a self.
    #
    def __idiv__(self: FVector, t: float) -> FVector: pass

    ##
    # \brief 
    # \param self The \e %FVector instance this method is called upon.
    # \param t 
    # \return 
    #
    def __itruediv__(self: FVector, t: float) -> FVector: pass

    ##
    # \brief 
    #
    objectID = property(getObjectID)

    ##
    # \brief 
    #
    size = property(getSize)