/**
 * @file ssbehaviourtreeselector.hpp
 *
 * @brief Processes all subtrees and returns SUCCESS if any
 * return SUCCESS.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include "ssbehviourtreeselector.hpp"

namespace ssutil::behaviourtree{
    status selector::tick()
    {
        for(abstractbehaviourtree* child : children){
            if(child->tick() == SUCCESS) return SUCCESS;
        }
        return FAILURE;
    }
}