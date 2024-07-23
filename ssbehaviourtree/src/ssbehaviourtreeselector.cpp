/**
 * @file ssbehaviourtreeselector.cpp
 *
 * @brief Processes subtrees until first occurance of SUCCESS.
 * Returns FAILURE if no subtree returns SUCCESS.
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