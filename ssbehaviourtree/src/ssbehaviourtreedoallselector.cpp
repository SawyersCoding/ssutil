/**
 * @file ssbehaviourtreedoallselector.cpp
 *
 * @brief Process all subtrees and returns the 
 * result of a selector
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include "ssbehaviourtreedoallselector.hpp"

namespace ssutil::behaviourtree{
    
    status doallselector::tick()
    {
        status ret = FAILURE;
        for(abstractbehaviourtree* child : children){
            if(child->tick() == SUCCESS) ret = SUCCESS;
        }
        return ret;
    }

}