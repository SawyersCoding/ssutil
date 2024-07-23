/**
 * @file ssbehaviourtreedoallselector.hpp
 *
 * @brief Process all subtrees and returns the 
 * result of a sequence.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#ifndef SSBEHAVIOURTREEDOALLSEQUENCE_HPP
#define SSBEHAVIOURTREEDOALLSEQUENCE_HPP

#include "ssabstractbehaviourtree.hpp"

namespace ssutil::behaviourtree{

    class doallsequence : public abstractbehaviourtree {

            /// @brief Processes this tree.
            /// @return FAILURE if any subtree returns FAILURE.
            virtual status tick();

    };

}


#endif // SSBEHAVIOURTREEDOALLSEQUENCE_HPP