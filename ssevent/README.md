# ssevent

An implementation of the observer pattern inspired by C# events.

Often, the observer pattern has subjects/events maintain a list of objects which implement an interface for observers/listeners. This can become cumbersome when a specific object must listen for several events or one wants to invoke a global function when an event occurs.

These issues are remedied by ssevents by having ssevents maintain a set of functions to invoke instead a set of objects that implement the desired function. This way, any function with the appropriate prototype can be invoked by the ssevent. This is accomplished using the functional library.

The main drawback to this approach is that one must use the std::bind to subscribe a member function to an event. Thus, subscribing a member function is slightly different from subscribing a global function. 

## example.cpp:

```
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
```
