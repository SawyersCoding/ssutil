/**
 * @file example.cpp
 *
 * @brief Using ssevents requires some housekeeping and mindfulness syntactically.
 * 
 * It's important that functions be removed from the event's set of functions
 * to invoke when they are no longer needed or the caller is deconstructed. To
 * do this, one must store the function pointer for later.
 * 
 * This file demonstrates the creation of two kinds of functions; One that is a 
 * member function of a class and one that is global.
 *
 * @namespace ssutil
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include <iostream>
#include "../src/ssevent.hpp"

namespace ssutil {

    class exclass{
        public:
            void greet(void* sender){
                std::cout << "\tHi from exclass!" << std::endl;
            }
    };

    void goodbye(void* sender){
        std::cout << "\tBye from regular ol' function!" << std::endl;
    }

}

int main(){
    std::function<void(void*)> greet, bye;
    ssutil::ssevent on_greeting, on_goodbye, on_everything, on_nothing;
    ssutil::exclass example;

    // Define functions to be called when events occur
    greet = std::bind(&ssutil::exclass::greet, &example, &on_greeting);
    bye = ssutil::goodbye;
    
    // Add functions to desired events
    on_greeting += &greet;
    on_goodbye += &bye;
    on_everything += &greet;
    on_everything += &bye;
    on_nothing += &greet;
    on_nothing += &bye;
    // Remove everything to test function removal
    on_nothing -= &greet;
    on_nothing -= &bye;

    // Invoke events
    std::cout << "On greeting:" << std::endl;
    on_greeting.notify();
    
    std::cout << "\nOn goodbye:" << std::endl;
    on_goodbye.notify();
    
    std::cout << "\nOn everything:" << std::endl;
    on_everything.notify();

    std::cout << "\nOn nothing:" << std::endl;
    on_nothing.notify();

    // Clean up
    on_greeting -= &greet;
    on_goodbye -= &bye;
    on_everything -= &greet;
    on_everything -= &bye;
    // on_nothing has already been cleaned up for the example

    return 0;
}
