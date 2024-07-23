/**
 * @file ssbehaviourtreeuntilfail.hpp
 *
 * @brief Repeatedly processes the subtree until a FAILURE occurs.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#ifndef SSBEHAVIOURTREEUNTILFAIL_HPP
#define SSBEHAVIOURTREEUNTILFAIL_HPP

#include "ssbehaviourtreedecorator.hpp"

namespace ssutil::behaviourtree{

    class untilfail : public decorator {

        public:
            /// @brief Processes the subtree.
            /// @return SUCCESS when there is a failure in the subtree.
            virtual status tick();

    };

}

#endif // SSBEHAVIOURTREEUNTILFAIL_HPP