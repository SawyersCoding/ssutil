/**
 * @file ssbehaviourtreeselector.hpp
 *
 * @brief Processes subtrees until first occurance of SUCCESS.
 * Returns FAILURE if no subtree returns SUCCESS.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#ifndef SSBEHAVIOURTREESELECTOR_HPP
#define SSBEHAVIOURTREESELECTOR_HPP

#include "ssabstractbehaviourtree.hpp"

namespace ssutil::behaviourtree{

    class selector : public abstractbehaviourtree {

        public:
            /// @brief Processes this tree.
            /// @return SUCCESS if any subtree returns SUCCESS.
            virtual status tick();

    };

}

#endif // SSBEHAVIOURTREESELECTOR_HPP