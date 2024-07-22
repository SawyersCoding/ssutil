/**
 * @file ssbehaviourtreeselector.cpp
 *
 * @brief Processes all subtrees and returns SUCCESS if any
 * return SUCCESS.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include "ssbehaviourtreeselector.hpp"

namespace ssutil::behaviourtree{
    status selector::tick()
    {
        for(abstractbehaviourtree* child : children){
            if(child->tick() == SUCCESS) return SUCCESS;
        }
        return FAILURE;
    }
}