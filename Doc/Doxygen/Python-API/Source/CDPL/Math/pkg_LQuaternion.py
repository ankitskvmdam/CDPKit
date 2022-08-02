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
class LQuaternion(Boost.Python.instance):

    ##
    # \brief Initializes the \e %LQuaternion instance.
    # \param self The \e %LQuaternion instance to initialize.
    #
    def __init__(self: object) -> None: pass

    ##
    # \brief Initializes the \e %LQuaternion instance.
    # \param self The \e %LQuaternion instance to initialize.
    # \param q 
    #
    def __init__(self: object, q: LQuaternion) -> None: pass

    ##
    # \brief Initializes the \e %LQuaternion instance.
    # \param self The \e %LQuaternion instance to initialize.
    # \param c1 
    # \param c2 
    # \param c3 
    # \param c4 
    #
    def __init__(self: object, c1: int, c2: int = 0, c3: int = 0, c4: int = 0) -> None: pass

    ##
    # \brief Initializes the \e %LQuaternion instance.
    # \param arg1 The \e %LQuaternion instance to initialize.
    # \param e 
    #
    def __init__(arg1: object, e: ConstFQuaternionExpression) -> None: pass

    ##
    # \brief Initializes the \e %LQuaternion instance.
    # \param arg1 The \e %LQuaternion instance to initialize.
    # \param e 
    #
    def __init__(arg1: object, e: ConstDQuaternionExpression) -> None: pass

    ##
    # \brief Initializes the \e %LQuaternion instance.
    # \param arg1 The \e %LQuaternion instance to initialize.
    # \param e 
    #
    def __init__(arg1: object, e: ConstLQuaternionExpression) -> None: pass

    ##
    # \brief Initializes the \e %LQuaternion instance.
    # \param arg1 The \e %LQuaternion instance to initialize.
    # \param e 
    #
    def __init__(arg1: object, e: ConstULQuaternionExpression) -> None: pass

    ##
    # \brief Initializes the \e %LQuaternion instance.
    # \param arg1 The \e %LQuaternion instance to initialize.
    # \param a 
    #
    def __init__(arg1: object, a: object) -> None: pass

    ##
    # \brief Returns the numeric identifier (ID) of the wrapped C++ class instance.
    # \param self The \e %LQuaternion instance this method is called upon.
    #
    # Different Python \e %LQuaternion instances may reference the same underlying C++ class instance. The commonly used Python expression
    # <tt>a is not b</tt> thus cannot tell reliably whether the two \e %LQuaternion instances \e a and \e b reference different C++ objects. 
    # The numeric identifier returned by this method allows to correctly implement such an identity test via the simple expression
    # <tt>a.getObjectID() != b.getObjectID()</tt>.
    #
    # \return The numeric ID of the internally referenced C++ class instance.
    #
    def getObjectID(self: LQuaternion) -> int: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %LQuaternion instance \a e.
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param e The \e %LQuaternion instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: LQuaternion, e: ConstFQuaternionExpression) -> LQuaternion: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %LQuaternion instance \a e.
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param e The \e %LQuaternion instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: LQuaternion, e: ConstDQuaternionExpression) -> LQuaternion: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %LQuaternion instance \a e.
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param e The \e %LQuaternion instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: LQuaternion, e: ConstLQuaternionExpression) -> LQuaternion: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %LQuaternion instance \a e.
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param e The \e %LQuaternion instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: LQuaternion, e: ConstULQuaternionExpression) -> LQuaternion: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %LQuaternion instance \a q.
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param q The \e %LQuaternion instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: LQuaternion, q: LQuaternion) -> LQuaternion: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %LQuaternion instance \a a.
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param a The \e %LQuaternion instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: LQuaternion, a: object) -> None: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \return 
    #
    def getC1(self: LQuaternion) -> int: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \return 
    #
    def getC2(self: LQuaternion) -> int: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \return 
    #
    def getC3(self: LQuaternion) -> int: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \return 
    #
    def getC4(self: LQuaternion) -> int: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \return 
    #
    def toArray(self: LQuaternion) -> object: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param q 
    #
    def swap(self: LQuaternion, q: LQuaternion) -> None: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param v 
    #
    def setC1(self: LQuaternion, v: int) -> None: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param v 
    #
    def setC2(self: LQuaternion, v: int) -> None: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param v 
    #
    def setC3(self: LQuaternion, v: int) -> None: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param v 
    #
    def setC4(self: LQuaternion, v: int) -> None: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param c1 
    # \param c2 
    # \param c3 
    # \param c4 
    #
    def set(self: LQuaternion, c1: int = 0, c2: int = 0, c3: int = 0, c4: int = 0) -> None: pass

    ##
    # \brief Returns the result of the comparison operation <tt>self == q</tt>.
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param q The \e %LQuaternion instance to be compared with.
    # \return The result of the comparison operation.
    #
    def __eq__(self: LQuaternion, q: LQuaternion) -> bool: pass

    ##
    # \brief Returns the result of the comparison operation <tt>self == q</tt>.
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param q The \e %LQuaternion instance to be compared with.
    # \return The result of the comparison operation.
    #
    def __eq__(self: LQuaternion, q: ConstLQuaternionExpression) -> bool: pass

    ##
    # \brief Returns the result of the comparison operation <tt>self != q</tt>.
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param q The \e %LQuaternion instance to be compared with.
    # \return The result of the comparison operation.
    #
    def __ne__(self: LQuaternion, q: LQuaternion) -> bool: pass

    ##
    # \brief Returns the result of the comparison operation <tt>self != q</tt>.
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param q The \e %LQuaternion instance to be compared with.
    # \return The result of the comparison operation.
    #
    def __ne__(self: LQuaternion, q: ConstLQuaternionExpression) -> bool: pass

    ##
    # \brief Returns a string representation of the \e %LQuaternion instance.
    # \param self The \e %LQuaternion instance this method is called upon.
    # \return The generated string representation.
    #
    def __str__(self: LQuaternion) -> str: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \return 
    #
    def __pos__(self: LQuaternion) -> LQuaternion: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \return 
    #
    def __neg__(self: object) -> ConstLQuaternionExpression: pass

    ##
    # \brief Returns the result of the addition operation <tt>self + t</tt>.
    # \param self The \e %LQuaternion instance representing the first addend.
    # \param t Specifies the second addend.
    # \return A \e %LQuaternion instance holding the result of the addition.
    #
    def __add__(self: object, t: int) -> ConstLQuaternionExpression: pass

    ##
    # \brief Returns the result of the addition operation <tt>self + e</tt>.
    # \param self The \e %LQuaternion instance representing the first addend.
    # \param e Specifies the second addend.
    # \return A \e %LQuaternion instance holding the result of the addition.
    #
    def __add__(self: object, e: ConstLQuaternionExpression) -> ConstLQuaternionExpression: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param t 
    # \return 
    #
    def __radd__(self: object, t: int) -> ConstLQuaternionExpression: pass

    ##
    # \brief Returns the result of the subtraction operation <tt>self - t</tt>.
    # \param self The \e %LQuaternion instance acting as minuend.
    # \param t Specifies the subtrahend.
    # \return A \e %LQuaternion instance holding the result of the subtraction.
    #
    def __sub__(self: object, t: int) -> ConstLQuaternionExpression: pass

    ##
    # \brief Returns the result of the subtraction operation <tt>self - e</tt>.
    # \param self The \e %LQuaternion instance acting as minuend.
    # \param e Specifies the subtrahend.
    # \return A \e %LQuaternion instance holding the result of the subtraction.
    #
    def __sub__(self: object, e: ConstLQuaternionExpression) -> ConstLQuaternionExpression: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param t 
    # \return 
    #
    def __rsub__(self: object, t: int) -> ConstLQuaternionExpression: pass

    ##
    # \brief Returns the result of the multiplication operation <tt>self * t</tt>.
    # \param self The \e %LQuaternion instance acting as multiplicand.
    # \param t Specifies the multiplier.
    # \return A \e %LQuaternion instance holding the result of the multiplication.
    #
    def __mul__(self: object, t: int) -> ConstLQuaternionExpression: pass

    ##
    # \brief Returns the result of the multiplication operation <tt>self * e</tt>.
    # \param self The \e %LQuaternion instance acting as multiplicand.
    # \param e Specifies the multiplier.
    # \return A \e %LQuaternion instance holding the result of the multiplication.
    #
    def __mul__(self: object, e: ConstLQuaternionExpression) -> ConstLQuaternionExpression: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param t 
    # \return 
    #
    def __rmul__(self: object, t: int) -> ConstLQuaternionExpression: pass

    ##
    # \brief Returns the result of the division operation <tt>self / t</tt>.
    # \param self The \e %LQuaternion instance acting as dividend.
    # \param t Specifies the divisor.
    # \return A \e %LQuaternion instance holding the result of the division.
    #
    def __div__(self: object, t: int) -> ConstLQuaternionExpression: pass

    ##
    # \brief Returns the result of the division operation <tt>self / e</tt>.
    # \param self The \e %LQuaternion instance acting as dividend.
    # \param e Specifies the divisor.
    # \return A \e %LQuaternion instance holding the result of the division.
    #
    def __div__(self: object, e: ConstLQuaternionExpression) -> ConstLQuaternionExpression: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param t 
    # \return 
    #
    def __truediv__(self: object, t: int) -> ConstLQuaternionExpression: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param t 
    # \return 
    #
    def __rdiv__(self: object, t: int) -> ConstLQuaternionExpression: pass

    ##
    # \brief Performs the in-place addition operation <tt>self += t</tt>.
    # \param self The \e %LQuaternion instance acting as in-place addend.
    # \param t Specifies the second addend.
    # \return The updated \e %LQuaternion instance \a self.
    #
    def __iadd__(self: LQuaternion, t: int) -> LQuaternion: pass

    ##
    # \brief Performs the in-place addition operation <tt>self += q</tt>.
    # \param self The \e %LQuaternion instance acting as in-place addend.
    # \param q Specifies the second addend.
    # \return The updated \e %LQuaternion instance \a self.
    #
    def __iadd__(self: LQuaternion, q: LQuaternion) -> LQuaternion: pass

    ##
    # \brief Performs the in-place addition operation <tt>self += q</tt>.
    # \param self The \e %LQuaternion instance acting as in-place addend.
    # \param q Specifies the second addend.
    # \return The updated \e %LQuaternion instance \a self.
    #
    def __iadd__(self: LQuaternion, q: ConstLQuaternionExpression) -> LQuaternion: pass

    ##
    # \brief Performs the in-place subtraction operation <tt>self -= t</tt>.
    # \param self The \e %LQuaternion instance acting as in-place minuend.
    # \param t Specifies the subtrahend.
    # \return The updated \e %LQuaternion instance \a self.
    #
    def __isub__(self: LQuaternion, t: int) -> LQuaternion: pass

    ##
    # \brief Performs the in-place subtraction operation <tt>self -= q</tt>.
    # \param self The \e %LQuaternion instance acting as in-place minuend.
    # \param q Specifies the subtrahend.
    # \return The updated \e %LQuaternion instance \a self.
    #
    def __isub__(self: LQuaternion, q: LQuaternion) -> LQuaternion: pass

    ##
    # \brief Performs the in-place subtraction operation <tt>self -= q</tt>.
    # \param self The \e %LQuaternion instance acting as in-place minuend.
    # \param q Specifies the subtrahend.
    # \return The updated \e %LQuaternion instance \a self.
    #
    def __isub__(self: LQuaternion, q: ConstLQuaternionExpression) -> LQuaternion: pass

    ##
    # \brief Performs the in-place multiplication operation <tt>self *= t</tt>.
    # \param self The \e %LQuaternion instance acting as in-place multiplicand.
    # \param t Specifies the multiplier.
    # \return The updated \e %LQuaternion instance \a self.
    #
    def __imul__(self: LQuaternion, t: int) -> LQuaternion: pass

    ##
    # \brief Performs the in-place multiplication operation <tt>self *= q</tt>.
    # \param self The \e %LQuaternion instance acting as in-place multiplicand.
    # \param q Specifies the multiplier.
    # \return The updated \e %LQuaternion instance \a self.
    #
    def __imul__(self: LQuaternion, q: LQuaternion) -> LQuaternion: pass

    ##
    # \brief Performs the in-place multiplication operation <tt>self *= q</tt>.
    # \param self The \e %LQuaternion instance acting as in-place multiplicand.
    # \param q Specifies the multiplier.
    # \return The updated \e %LQuaternion instance \a self.
    #
    def __imul__(self: LQuaternion, q: ConstLQuaternionExpression) -> LQuaternion: pass

    ##
    # \brief Performs the in-place division operation <tt>self /= t</tt>.
    # \param self The \e %LQuaternion instance acting as in-place dividend.
    # \param t Specifies the divisor.
    # \return The updated \e %LQuaternion instance \a self.
    #
    def __idiv__(self: LQuaternion, t: int) -> LQuaternion: pass

    ##
    # \brief Performs the in-place division operation <tt>self /= q</tt>.
    # \param self The \e %LQuaternion instance acting as in-place dividend.
    # \param q Specifies the divisor.
    # \return The updated \e %LQuaternion instance \a self.
    #
    def __idiv__(self: LQuaternion, q: LQuaternion) -> LQuaternion: pass

    ##
    # \brief Performs the in-place division operation <tt>self /= q</tt>.
    # \param self The \e %LQuaternion instance acting as in-place dividend.
    # \param q Specifies the divisor.
    # \return The updated \e %LQuaternion instance \a self.
    #
    def __idiv__(self: LQuaternion, q: ConstLQuaternionExpression) -> LQuaternion: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param t 
    # \return 
    #
    def __itruediv__(self: LQuaternion, t: int) -> LQuaternion: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param q 
    # \return 
    #
    def __itruediv__(self: LQuaternion, q: LQuaternion) -> LQuaternion: pass

    ##
    # \brief 
    # \param self The \e %LQuaternion instance this method is called upon.
    # \param q 
    # \return 
    #
    def __itruediv__(self: LQuaternion, q: ConstLQuaternionExpression) -> LQuaternion: pass

    ##
    # \brief 
    #
    objectID = property(getObjectID)