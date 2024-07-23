/**
 * @file ssbehaviourtreeinverter.hpp
 *
 * @brief A decorator that inverts the result of the child node. Thus,
 * SUCCESS become FAILURES and vice versa.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#ifndef SSBEHAVIOURTREEINVERTER_H
#define SSBEHAVIOURTREEINVERTER_H

#include "ssbehaviourtreedecorator.hpp"

namespace ssutil::behaviourtree{

    class inverter : public decorator {

        public:
            /// @brief Processes this tree.
            /// @return SUCCESS if child returns FAILURE and vice versa.
            virtual status tick();

    };

}

#endif // SSBEHAVIOURTREEINVERTER_H