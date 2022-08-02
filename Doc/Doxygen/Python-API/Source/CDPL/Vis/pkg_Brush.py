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
class Brush(Boost.Python.instance):

    ##
    # \brief 
    #
    class Style(Boost.Python.enum):

        ##
        # \brief NO_PATTERN.
        #
        NO_PATTERN = 0

        ##
        # \brief SOLID_PATTERN.
        #
        SOLID_PATTERN = 1

        ##
        # \brief DENSE1_PATTERN.
        #
        DENSE1_PATTERN = 2

        ##
        # \brief DENSE2_PATTERN.
        #
        DENSE2_PATTERN = 3

        ##
        # \brief DENSE3_PATTERN.
        #
        DENSE3_PATTERN = 4

        ##
        # \brief DENSE4_PATTERN.
        #
        DENSE4_PATTERN = 5

        ##
        # \brief DENSE5_PATTERN.
        #
        DENSE5_PATTERN = 6

        ##
        # \brief DENSE6_PATTERN.
        #
        DENSE6_PATTERN = 7

        ##
        # \brief DENSE7_PATTERN.
        #
        DENSE7_PATTERN = 8

        ##
        # \brief H_PATTERN.
        #
        H_PATTERN = 9

        ##
        # \brief V_PATTERN.
        #
        V_PATTERN = 10

        ##
        # \brief CROSS_PATTERN.
        #
        CROSS_PATTERN = 11

        ##
        # \brief LEFT_DIAG_PATTERN.
        #
        LEFT_DIAG_PATTERN = 12

        ##
        # \brief RIGHT_DIAG_PATTERN.
        #
        RIGHT_DIAG_PATTERN = 13

        ##
        # \brief DIAG_CROSS_PATTERN.
        #
        DIAG_CROSS_PATTERN = 14

    ##
    # \brief Initializes the \e %Brush instance.
    # \param self The \e %Brush instance to initialize.
    #
    def __init__(self: object) -> None: pass

    ##
    # \brief Initializes the \e %Brush instance.
    # \param self The \e %Brush instance to initialize.
    # \param brush 
    #
    def __init__(self: object, brush: Brush) -> None: pass

    ##
    # \brief Initializes the \e %Brush instance.
    # \param self The \e %Brush instance to initialize.
    # \param style 
    #
    def __init__(self: object, style: Style) -> None: pass

    ##
    # \brief Initializes the \e %Brush instance.
    # \param self The \e %Brush instance to initialize.
    # \param color 
    # \param style 
    #
    def __init__(self: object, color: Color, style: Style = CDPL.Vis.Style.SOLID_PATTERN) -> None: pass

    ##
    # \brief Returns the numeric identifier (ID) of the wrapped C++ class instance.
    # \param self The \e %Brush instance this method is called upon.
    #
    # Different Python \e %Brush instances may reference the same underlying C++ class instance. The commonly used Python expression
    # <tt>a is not b</tt> thus cannot tell reliably whether the two \e %Brush instances \e a and \e b reference different C++ objects. 
    # The numeric identifier returned by this method allows to correctly implement such an identity test via the simple expression
    # <tt>a.getObjectID() != b.getObjectID()</tt>.
    #
    # \return The numeric ID of the internally referenced C++ class instance.
    #
    def getObjectID(self: Brush) -> int: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %Brush instance \a brush.
    # \param self The \e %Brush instance this method is called upon.
    # \param brush The \e %Brush instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: Brush, brush: Brush) -> Brush: pass

    ##
    # \brief 
    # \param self The \e %Brush instance this method is called upon.
    # \return 
    #
    def getColor(self: Brush) -> Color: pass

    ##
    # \brief 
    # \param self The \e %Brush instance this method is called upon.
    # \param color 
    #
    def setColor(self: Brush, color: Color) -> None: pass

    ##
    # \brief 
    # \param self The \e %Brush instance this method is called upon.
    # \return 
    #
    def getStyle(self: Brush) -> Style: pass

    ##
    # \brief 
    # \param self The \e %Brush instance this method is called upon.
    # \param style 
    #
    def setStyle(self: Brush, style: Style) -> None: pass

    ##
    # \brief Returns the result of the comparison operation <tt>self == brush</tt>.
    # \param self The \e %Brush instance this method is called upon.
    # \param brush The \e %Brush instance to be compared with.
    # \return The result of the comparison operation.
    #
    def __eq__(self: Brush, brush: Brush) -> bool: pass

    ##
    # \brief Returns the result of the comparison operation <tt>self != brush</tt>.
    # \param self The \e %Brush instance this method is called upon.
    # \param brush The \e %Brush instance to be compared with.
    # \return The result of the comparison operation.
    #
    def __ne__(self: Brush, brush: Brush) -> bool: pass

    ##
    # \brief 
    #
    objectID = property(getObjectID)

    ##
    # \brief 
    #
    color = property(getColor, setColor)

    ##
    # \brief 
    #
    style = property(getStyle, setStyle)