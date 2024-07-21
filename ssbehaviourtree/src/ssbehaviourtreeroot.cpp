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

    void root::append_child(abstractbehaviourtree *child)
    {
        if(children.size() == NCHILDREN_MAX){
            throw std::length_error("The root can have only " + std::to_string(NCHILDREN_MAX) + " child!");
        }
        abstractbehaviourtree::append_child(child);
    }

    status root::tick()
    {
        if(children.size() == NCHILDREN_MAX) return children[0]->tick();
        return SUCCESS;
    }

}
