/**
 * @file ssevent.hpp
 *
 * @brief ssevent are used for invoking designated 
 * functions when an event of interest occurs.
 *
 * @namespace ssutil
 *
 * @author Sawyer Stanley
 * Contact: sawyerscoding@gmail.com
 */


#ifndef SSEVENT_HPP
#define SSEVENT_HPP

#include <functional>
#include <unordered_set>
#include "ssievent.hpp"

namespace ssutil{

    class ssevent : public ssievent {

        private:

            std::unordered_set<const std::function<void(void*)>> callbacks;

        public:

            /// @brief Adds the given callback from the set of callbacks to be invoked
            /// during notify().
            /// @param callback The callback to add.
            void add_callback(const std::function<void(void*)> callback) override;

            /// @brief Invokes all callbacks.
            void notify() override;

            /// @brief Removes the given callback from the set of callbacks to be invoked
            /// during notify().
            /// @param callback The callback to remove.
            void remove_callback(const std::function<void(void*)> callback) override;

    };

}

#endif // SSEVENT_HPP