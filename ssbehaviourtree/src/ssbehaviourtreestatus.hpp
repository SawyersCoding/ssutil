/**
 * @file ssbehaviourtreestatus.hpp
 *
 * @brief The status options which a behaviour tree can return.
 *
 * @namespace ssutil
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#ifndef SSIBEHTREESTATUS_HPP
#define SSIBEHTREESTATUS_HPP

namespace ssutil{

    enum ssbehaviourtreestatus{
        FAILURE = 0,
        SUCCESS = 1,
        RUNNING = 2
    };

}

#endif // SSIBEHTREESTATUS_HPP
