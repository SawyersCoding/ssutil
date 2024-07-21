/**
 * @file ssabstractbehaviourtree.chpp
 *
 * @brief A base abstract class for all behaviour trees.
 *
 * @namespace ssutil
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include "ssabstractbehaviourtree.hpp"

namespace ssutil{

    void ssabstractbehaviourtree::append_child(ssabstractbehaviourtree *child)
    {
        children.push_back(child);
    }

    void ssabstractbehaviourtree::operator+=(ssabstractbehaviourtree *child)
    {
        append_child(child);
    }

}
