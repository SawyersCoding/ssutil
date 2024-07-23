# ssbehaviourtree

I used this [website](https://www.gamedeveloper.com/programming/behavior-trees-for-ai-how-they-work) for understanding behaviour trees.

To summarize, behaviour trees are often used for implementing AI in robotics, video games, etc. While there may be some overhead when it comes to setting up a behviour tree, they are for more extendable and maintainable than another common method for implementing AI: state machines (more on this later).

I have implemented several common behaviour tree nodes already, but creating more to suit yours needs is an easy task. In fact, if you plan to use this implementation, you must create your own nodes. The actual "behaviours" that are carried out are entirely implemented in the leaf nodes of a behaviour tree. I have not implemented any leaf nodes aside from those found in the [example](ex/example.cpp), and you'll likely not be using those for your project!

While it's not a necessity imposed by this implementation, note that it is standard to create a root node with a single child, the first node containing logic.

## Available Nodes
### composite (multiple children)
- doallselector: selector but processes all subtrees.

- doallsequence: sequence but processes all subtrees.

- selector: Returns SUCCESS upon finding a subtree that returns SUCCESS. 

- sequence: Returns FAILUE upon finding a subtree that returns FAILURE.

### decorator (single child only)

- inverter: Swaps SUCCESS for FAILURE and vice vera.

- succeeder: Always returns SUCCESS.

- repeater: Repeats processing the subtree.

- root: An entry point for all behaviour trees.

- untilfail: Repeats until a failure occurs.

## example.cpp
```
/**
 * @file example.cpp
 *
 * @brief Ok, it's a silly example, but you get the idea. The objective
 * is to solve the famous "FizzBuzz" problem. Given three positive integers,
 * a, b, and n, for all numbers i in {1 to n}, print "Fizz" if i divides evenly
 * by a, print "Buzz" if i divides evenly by b, print "FizzBuzz" if i divides
 * evenly by a and b, or print i if i does not divide evenly by a or b.
 *
 * @author Sawyer Stanley (https://github.com/SawyersCoding)
 */

#include <iostream>
#include <string>
#include "../src/ssbehaviourtreedoallselector.hpp"
#include "../src/ssbehaviourtreeselector.hpp"
#include "../src/ssbehaviourtreeroot.hpp"

using namespace ssutil::behaviourtree;

class fizzbuzzleaf : public abstractbehaviourtree{

    private:
        int div;
        int *i;
        std::string word;
        std::string* outword;

    public:
        /// @brief Creates a fizzbuzzleaf.
        /// @param div The divisor
        /// @param i The number to be divided.
        /// @param word The word to print upon an even division.
        /// @param outword The string to append to for printing.
        fizzbuzzleaf(int div, int *i, std::string word, std::string* outword){
            this->div = div;
            this->i = i;
            this->word = word;
            this->outword = outword;
        }

        virtual status tick(){
            if(*i % div == 0) {
                *outword += word;
                return SUCCESS;
            }
            return FAILURE;
        }

};

class printileaf : public abstractbehaviourtree {

    private:
        int *i;
        std::string *outword;

    public:
        /// @brief Creates a printileaf.
        /// @param i The number to be divided.
        /// @param outword The string that will be printed.
        printileaf(int *i, std::string *outword){
            this->i = i;
            this->outword = outword;
        }

    public:
        virtual status tick(){
            *outword += std::to_string(*i);
            return SUCCESS;
        } 

};

int main(){
    int a, b, n, i;
    std::string to_print;
    a = 3;
    b = 5;
    n = 100;

    // Create fizzbuzz tree
    abstractbehaviourtree *fizzbuzz = new root();
    selector sel;
    doallselector dasel;
    fizzbuzzleaf fizz(a, &i, "Fizz", &to_print);
    fizzbuzzleaf buzz(b, &i, "Buzz", &to_print);
    printileaf printi(&i, &to_print);

    // Connect trees
    *fizzbuzz += &sel;
    sel += &dasel;
    sel += &printi;
    dasel += &fizz;
    dasel += &buzz;

    // Tick the fizzbuzz behaviour tree at each value of i
    for(i = 1; i <= n; i++){
        to_print = "";
        fizzbuzz->tick();
        std::cout << to_print << std::endl;
    }
}
```

## Why Behaviour Trees?
First, let's consider the behaviour tree's main competition, the state machine. A state machine is a collection of states and transitions between those states. Think of an "idle" state for an NPC in a game. Perhaps this NPC spots a monster, triggering a transition to the "run away faster than slowest friend" state. The NPC is entirely controlled by their current state. Perhaps after they get a safe distance away, they transition back to the "idle" state.

State machines are not complicated as a concept and their implementation is relatively straight-forward compared to a behaviour tree. So what gives?

Imagine the same NPC also has the states "walk", "run", "talk", "sit", "aggro", "damaged", "perished", ... and so on. Now consider all of the transitions required to be able to reach all of the states. As state machines get large, they become difficult to maintain. Additionally, when we inevitable encounter unexpected behaviour, finding the cause across all of the states and transition conditions can be challenging.

Enter behaviour trees. Maintaining those transitions is no longer an issue. Additionally, we can create and recycle entire behaviour trees, inserting them as subtrees in other, larger behaviours. Debugging is no longer a matter of tracking transitions and states, but depth-first searching a tree. Assuming the appropriate composite or decorator nodes have been chosen, the vital information is found entirely in the leaf nodes. 

All of that said, if you have simple behaviours, a state machine is a fine choice to get those behaviours running quickly. When adding a new state to your state machine becomes a challenge, consider a behaviour tree.
