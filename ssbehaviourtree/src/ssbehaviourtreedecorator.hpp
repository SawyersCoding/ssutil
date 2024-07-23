/**
 * @file ssbehaviourtreedecorator.hpp
 *
 * @brief A behaviour tree that is limited to having a single child.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#ifndef SSBEHAVIOURTREEDECORATOR_HPP
#define SSBEHAVIOURTREEDECORATOR_HPP

#include <stdexcept>
#include "ssabstractbehaviourtree.hpp"

namespace ssutil::behaviourtree{

    class decorator : public abstractbehaviourtree {

        public:
            const int NCHILDREN_MAX = 1;        

        public:

            /// @brief Appends a behaviour tree to the end this tree's children.
            /// @param child The tree to append.
            virtual void append_child(abstractbehaviourtree *child) override;

            /// @brief Processes this tree.
            /// @return The status of this tree (i.e. did the task fail, succeed, or is incomplete?).
            virtual status tick() = 0;
    };

}

#endif // SSBEHAVIOURTREEDECORATOR_HPP