#include "ssevent.hpp"

ssutil::ssevent::ssevent() { }

void ssutil::ssevent::add_callback(std::function<void(void *)> *callback)
{
    callbacks.emplace(callback);
}

void ssutil::ssevent::notify()
{
    for(std::function<void(void *)> *callback : callbacks){
        (*callback)(this);
    }
}

void ssutil::ssevent::remove_callback(std::function<void(void *)> *callback)
{
    callbacks.erase(callback);
}

void ssutil::ssevent::operator+=(std::function<void(void *)> *callback)
{
    add_callback(callback);
}

void ssutil::ssevent::operator-=(std::function<void(void *)> *callback)
{
    remove_callback(callback);
}
