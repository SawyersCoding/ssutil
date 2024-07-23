/**
 * @file ssbehaviourtreesucceeder.hpp
 *
 * @brief Always returns SUCCESS.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#ifndef SSBEHAVIOURTREESUCCEEDER_HPP
#define SSBEHAVIOURTREESUCCEEDER_HPP

#include "ssbehaviourtreedecorator.hpp"

namespace ssutil::behaviourtree{

    class succeeder : public decorator {

        public:
            /// @brief Processes this tree.
            /// @return Always returns SUCCESS.
            virtual status tick();

    };

}

#endif // SSBEHAVIOURTREESUCCEEDER_HPP