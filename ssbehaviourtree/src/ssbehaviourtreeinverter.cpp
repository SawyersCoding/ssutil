/**
 * @file ssbehaviourtreeinverter.hpp
 *
 * @brief A decorator that inverts the result of the child node. Thus,
 * SUCCESS become FAILURES and vice versa.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include "ssbehaviourtreeinverter.hpp"

namespace ssutil::behaviourtree{
    
    status ssutil::behaviourtree::inverter::tick()
    {
        status to_invert;
        if(children.size() == NCHILDREN_MAX) {
            to_invert = children[0]->tick();
            if(to_invert == SUCCESS) return FAILURE;
            else if (to_invert == FAILURE) return SUCCESS;
            else return to_invert;
        }
        return SUCCESS;
    }

}
