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