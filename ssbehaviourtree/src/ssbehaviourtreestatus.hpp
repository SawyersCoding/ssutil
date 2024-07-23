/**
 * @file ssbehaviourtreestatus.hpp
 *
 * @brief The status options which a behaviour tree can return.
 *
 * @namespace ssutil::behaviourtree
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#ifndef SSBEHAVIOURTREESTATUS_HPP
#define SSBEHAVIOURTREESTATUS_HPP

namespace ssutil::behaviourtree {

    enum status{
        FAILURE = 0,
        SUCCESS = 1,
        RUNNING = 2
    };

}

#endif // SSBEHAVIOURTREESTATUS_HPP
