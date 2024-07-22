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
#include "ssbehaviourtreedecorator.hpp"

namespace ssutil::behaviourtree{

    class root : public decorator {

        public:
            
            /// @brief Processes this tree.
            /// @return The status of the subtree or SUCCESS if no subtree exists.
            status tick() override;

    };

}

# endif // SSBEHAVIOURTREEROOT_HPP
