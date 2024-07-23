/**
 * @file ssbehaviourtreesucceeder.cpp
 *
 * @brief Always returns SUCCESS.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include "ssbehaviourtreesucceeder.hpp"

namespace ssutil::behaviourtree{
    
    status succeeder::tick()
    {
        if(children.size() == NCHILDREN_MAX){
            children[0]->tick();
        }
        return SUCCESS;
    }

}
