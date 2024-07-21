/**
 * @file ssabstractbehaviourtree.cpp
 *
 * @brief A base abstract class for all behaviour trees.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include "ssabstractbehaviourtree.hpp"

namespace ssutil::behaviourtree{

    void abstractbehaviourtree::append_child(abstractbehaviourtree *child)
    {
        children.push_back(child);
    }

    void abstractbehaviourtree::operator+=(abstractbehaviourtree *child)
    {
        append_child(child);
    }

}
