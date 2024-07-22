/**
 * @file ssbehaviourtreedecorator.hpp
 *
 * @brief A behaviour tree that is limited to having a single child.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include "ssbehaviourtreedecorator.hpp"

namespace ssutil::behaviourtree{
    
    void decorator::append_child(abstractbehaviourtree *child)
    {
        if(children.size() == NCHILDREN_MAX){
            throw std::length_error("The root can have only " + std::to_string(NCHILDREN_MAX) + " child!");
        }
        abstractbehaviourtree::append_child(child);

    }

}
