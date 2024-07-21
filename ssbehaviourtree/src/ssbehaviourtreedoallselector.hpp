/**
 * @file ssbehaviourtreedoallselector.hpp
 *
 * @brief Process all subtrees and returns the 
 * result of a selector
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include "ssabstractbehaviourtree.hpp"

namespace ssutil::behaviourtree{

    class doallselector : public abstractbehaviourtree {
        public:

            /// @brief Processes this tree.
            /// @return SUCCESS if any subtree returns SUCCESS.
            virtual status tick();

    };

}