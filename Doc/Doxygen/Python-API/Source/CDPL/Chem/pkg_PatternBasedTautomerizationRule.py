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
class PatternBasedTautomerizationRule(TautomerizationRule):

    ##
    # \brief 
    #
    class BondOrderChange(Boost.Python.instance):

        ##
        # \brief Initializes the \e %BondOrderChange instance.
        # \param self The \e %BondOrderChange instance to initialize.
        #
        def __init__(self: object) -> None: pass

        ##
        # \brief Initializes the \e %BondOrderChange instance.
        # \param self The \e %BondOrderChange instance to initialize.
        # \param bond_chg 
        #
        def __init__(self: object, bond_chg: BondOrderChange) -> None: pass

        ##
        # \brief Replaces the current state of \a self with a copy of the state of the \e %BondOrderChange instance \a bond_chg.
        # \param self The \e %BondOrderChange instance this method is called upon.
        # \param bond_chg The \e %BondOrderChange instance to copy.
        # \return The assignment target \a self.
        #
        def assign(self: BondOrderChange, bond_chg: BondOrderChange) -> BondOrderChange: pass

        ##
        # \brief Returns the numeric identifier (ID) of the wrapped C++ class instance.
        # \param self The \e %BondOrderChange instance this method is called upon.
        #
        # Different Python \e %BondOrderChange instances may reference the same underlying C++ class instance. The commonly used Python expression
        # <tt>a is not b</tt> thus cannot tell reliably whether the two \e %BondOrderChange instances \e a and \e b reference different C++ objects. 
        # The numeric identifier returned by this method allows to correctly implement such an identity test via the simple expression
        # <tt>a.getObjectID() != b.getObjectID()</tt>.
        #
        # \return The numeric ID of the internally referenced C++ class instance.
        #
        def getObjectID(self: BondOrderChange) -> int: pass

        ##
        # \brief 
        #
        objectID = property(getObjectID)

        ##
        # \brief FIXME!
        #
        atom1ID = property(getAtom1ID)

        ##
        # \brief FIXME!
        #
        atom2ID = property(getAtom2ID)

        ##
        # \brief FIXME!
        #
        orderChange = property(getOrderChange)

    ##
    # \brief Initializes the \e %PatternBasedTautomerizationRule instance.
    # \param self The \e %PatternBasedTautomerizationRule instance to initialize.
    # \param id 
    #
    def __init__(self: object, id: int) -> None: pass

    ##
    # \brief Initializes the \e %PatternBasedTautomerizationRule instance.
    # \param self The \e %PatternBasedTautomerizationRule instance to initialize.
    # \param rule 
    #
    def __init__(self: object, rule: PatternBasedTautomerizationRule) -> None: pass

    ##
    # \brief Returns the numeric identifier (ID) of the wrapped C++ class instance.
    # \param self The \e %PatternBasedTautomerizationRule instance this method is called upon.
    #
    # Different Python \e %PatternBasedTautomerizationRule instances may reference the same underlying C++ class instance. The commonly used Python expression
    # <tt>a is not b</tt> thus cannot tell reliably whether the two \e %PatternBasedTautomerizationRule instances \e a and \e b reference different C++ objects. 
    # The numeric identifier returned by this method allows to correctly implement such an identity test via the simple expression
    # <tt>a.getObjectID() != b.getObjectID()</tt>.
    #
    # \return The numeric ID of the internally referenced C++ class instance.
    #
    def getObjectID(self: PatternBasedTautomerizationRule) -> int: pass

    ##
    # \brief 
    # \param self The \e %PatternBasedTautomerizationRule instance this method is called upon.
    # \param pattern 
    # \param bond_chgs 
    #
    def addTransformationPattern(self: PatternBasedTautomerizationRule, pattern: MolecularGraph, bond_chgs: object) -> None: pass

    ##
    # \brief 
    # \param self The \e %PatternBasedTautomerizationRule instance this method is called upon.
    # \param pattern 
    #
    def addExcludePattern(self: PatternBasedTautomerizationRule, pattern: MolecularGraph) -> None: pass

    ##
    # \brief 
    # \param self The \e %PatternBasedTautomerizationRule instance this method is called upon.
    # \param rule 
    #
    def addExcludePatterns(self: PatternBasedTautomerizationRule, rule: PatternBasedTautomerizationRule) -> None: pass

    ##
    # \brief 
    # \param self The \e %PatternBasedTautomerizationRule instance this method is called upon.
    #
    def clearExcludePatterns(self: PatternBasedTautomerizationRule) -> None: pass

    ##
    # \brief Replaces the current state of \a self with a copy of the state of the \e %PatternBasedTautomerizationRule instance \a rule.
    # \param self The \e %PatternBasedTautomerizationRule instance this method is called upon.
    # \param rule The \e %PatternBasedTautomerizationRule instance to copy.
    # \return The assignment target \a self.
    #
    def assign(self: PatternBasedTautomerizationRule, rule: PatternBasedTautomerizationRule) -> PatternBasedTautomerizationRule: pass

    ##
    # \brief 
    #
    objectID = property(getObjectID)