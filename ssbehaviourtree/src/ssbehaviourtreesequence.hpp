/**
 * @file ssbehaviourtreesequence.hpp
 *
 * @brief A sequence node in a behaviour tree. Processes as 
 * many subtrees as possible while they return SUCCESS.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#ifndef SSBEHAVIOURTREESEQUENCE_HPP
#define SSBEHAVIOURTREESEQUENCE_HPP

#include "ssabstractbehaviourtree.hpp"

namespace ssutil::behaviourtree{

    class sequence : public abstractbehaviourtree {

        public:
            /// @brief Processes this tree.
            /// @return Returns FAILURE upon a subtree returning the same, RUNNING 
            /// likewise, and SUCCESS if all subtrees return SUCCESS.
            virtual status tick();

    };

}

#endif // SSBEHAVIOURTREESEQUENCE_HPP