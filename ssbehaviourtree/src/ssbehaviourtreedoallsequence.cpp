/**
 * @file ssbehaviourtreedoallselector.cpp
 *
 * @brief Process all subtrees and returns the 
 * result of a sequence.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include "ssbehaviourtreedoallsequence.hpp"

namespace ssutil::behaviourtree{

    status doallsequence::tick()
    {
        status ret = SUCCESS;
        for(abstractbehaviourtree* child : children){
            if(child->tick() == FAILURE) ret = FAILURE;
        }
        return ret;
    }

}
