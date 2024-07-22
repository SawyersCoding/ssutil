/**
 * @file ssbehaviourtreeroot.cpp
 *
 * @brief A root for any behaviour tree.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include "ssbehaviourtreeroot.hpp"

namespace ssutil::behaviourtree{

    status root::tick()
    {
        if(children.size() == NCHILDREN_MAX) return children[0]->tick();
        return SUCCESS;
    }

}
