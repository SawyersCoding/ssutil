#include "ssevent.hpp"

void ssutil::ssevent::add_callback(const std::function<void(void *)> callback)
{
    callbacks.emplace(callback);
}

void ssutil::ssevent::notify()
{
    for(const std::function<void(void*)> callback : callbacks){
        callback(this);
    }
}

void ssutil::ssevent::remove_callback(const std::function<void(void *)> callback)
{
    callbacks.erase(callback);
}
