/**
 * @file ssbehaviourtreeuntilfail.cpp
 *
 * @brief Repeatedly processes the subtree until a FAILURE occurs.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include "ssbehaviourtreeuntilfail.hpp"

namespace ssutil::behaviourtree{
   
    status untilfail::tick()
    {
        status cur = SUCCESS;

        while(cur != FAILURE){
            for(abstractbehaviourtree* child : children){
                cur = child->tick();
            }
        }

        return SUCCESS;
    }

}
