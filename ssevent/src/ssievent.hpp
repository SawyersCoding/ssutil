/**
 * @file ssievent.hpp
 *
 * @brief An interface for ssievents. ssievents are used for 
 * invoking designated functions when an event of interest
 * occurs.
 *
 * @namespace ssutil
 *
 * @author Sawyer Stanley
 * Contact: sawyerscoding@gmail.com
 */

#ifndef SSIEVENT_HPP
#define SSIEVENT_HPP

#include <functional>

namespace ssutil{

    class ssievent{

        public:

            /// @brief Adds the given callback from the set of callbacks to be invoked
            /// during notify().
            /// @param callback The callback to add.
            virtual void add_callback(const std::function<void(void*)> callback) = 0;

            /// @brief Invokes all callbacks.
            virtual void notify() = 0;

            /// @brief Removes the given callback from the set of callbacks to be invoked
            /// during notify().
            /// @param callback The callback to remove.
            virtual void remove_callback(const std::function<void(void*)> callback) = 0;

    };

}

#endif // SSIEVENT_HPP