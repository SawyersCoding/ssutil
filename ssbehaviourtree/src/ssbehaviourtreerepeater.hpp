/**
 * @file ssbehaviourtreerepeater.hpp
 *
 * @brief Repeats processing the subtree a number of times.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#ifndef SSBEHAVIOURTREEREPEATER_HPP
#define SSBEHAVIOURTREEREPEATER_HPP

#include "ssbehaviourtreedecorator.hpp"

namespace ssutil::behaviourtree{

    class repeater : public decorator {

        private:
            int n;

        public:
            /// @brief Creates a repeater.
            /// @param n The number of times to process the subtree.
            repeater(int n);

        public:
            /// @brief Processes this tree.
            /// @return The status of this tree (i.e. did the task fail, succeed, or is incomplete?).
            virtual status tick();

    };

}


#endif // SSBEHAVIOURTREEREPEATER_HPP