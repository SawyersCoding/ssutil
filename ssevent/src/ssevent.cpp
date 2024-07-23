/**
 * @file ssevent.cpp
 *
 * @brief ssevent are used for invoking designated 
 * functions when an event of interest occurs.
 *
 * @namespace ssutil::event
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include "ssevent.hpp"

namespace ssutil::event{

	event::event() { }

	void event::add_callback(std::function<void(void *)> *callback)
	{
   		 callbacks.emplace(callback);
	}

	void event::notify()
	{
   		 for(std::function<void(void *)> *callback : callbacks){
   		     (*callback)(this);
   		 }
	}

	void event::remove_callback(std::function<void(void *)> *callback)
	{
   		 callbacks.erase(callback);
	}

	void event::operator+=(std::function<void(void *)> *callback)
	{
   		 add_callback(callback);
	}

	void event::operator-=(std::function<void(void *)> *callback)
	{
   		 remove_callback(callback);
	}

}
