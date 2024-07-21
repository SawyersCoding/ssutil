/**
 * @file ssbehaviourtreesequence.cpp
 *
 * @brief A sequence node in a behaviour tree. Processes as 
 * many subtrees as possible while they return SUCCESS.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include "ssbehviourtreesequence.hpp"

namespace ssutil::behaviourtree{

    status sequence::tick()
    {
        status cur_status = SUCCESS;

        for(abstractbehaviourtree *child : children){
            cur_status = child->tick();
            // Stop if not success
            if(cur_status != SUCCESS) return cur_status; 
        }

        return SUCCESS;
    }

}