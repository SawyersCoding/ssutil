/**
 * @file ssabstractbehaviourtree.hpp
 *
 * @brief A base abstract class for all behaviour trees.
 *
 * @namespace ssutil
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#ifndef SSABSTRACTBEHAVIOURTREE_HPP
#define SSABSTRACTBEHAVIOURTREE_HPP

#include <vector>
#include "ssbehaviourtreestatus.hpp"

namespace ssutil{
    
    class ssabstractbehaviourtree{

        protected:
            std::vector<ssabstractbehaviourtree *> children;

        public:

            /// @brief Appends a behaviour tree to the end this tree's children.
            /// @param child The tree to append.
            virtual void append_child(ssabstractbehaviourtree *child);

            /// @brief Processes this tree.
            /// @return The status of this tree (i.e. did the task fail, succeed, or is incomplete?).
            virtual ssbehaviourtreestatus tick() = 0;

            // ----- OPERATORS     

            /// @brief Appends a behaviour tree to the end this tree's children.
            /// @param child The tree to append.
            void operator+=(ssabstractbehaviourtree *child);
    };

}

#endif // SSABSTRACTBEHAVIOURTREE_HPP
