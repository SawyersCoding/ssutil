/**
 * @file ssbehaviourtreeroot.hpp
 *
 * @brief A root for any behaviour tree.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#ifndef SSBEHAVIOURTREEROOT_HPP
#define SSBEHAVIOURTREEROOT_HPP

#include <stdexcept>
#include <string>
#include "ssabstractbehaviourtree.hpp"

namespace ssutil::behaviourtree{

    class root : public abstractbehaviourtree {
        
        public:
            const int NCHILDREN_MAX = 1;

        public:

            /// @brief Appends a behaviour tree to the end this tree's children.
            /// @param child The tree to append.
            virtual void append_child(abstractbehaviourtree *child) override;
            
            /// @brief Processes this tree.
            /// @return The status of the subtree or SUCCESS if no subtree exists.
            status tick() override;

    };

}

# endif // SSBEHAVIOURTREEROOT_HPP
