/**
 * @file ssbehaviourtreerepeater.cpp
 *
 * @brief Repeats processing the subtree a number of times.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include "ssbehaviourtreerepeater.hpp"

namespace ssutil::behaviourtree{

    repeater::repeater(int n)
    {
        this->n = n;
    }

    status repeater::tick()
    {
        int reps, i;

        reps = n;
        while(reps--){
            for(abstractbehaviourtree* child : children){
                child->tick();
            }
        }

        return SUCCESS;
    }
}
