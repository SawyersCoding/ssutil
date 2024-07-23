

#include <iostream>
#include <string>
#include "../src/ssbehaviourtreedoallselector.hpp"
#include "../src/ssbehaviourtreeroot.hpp"

using namespace ssutil::behaviourtree;

class fizzbuzzleaf : public abstractbehaviourtree{

    private:
        int div;
        int *cur;
        std::string word;
        std::string* outWord;

    public:
        fizzbuzzleaf(int div, int *cur, std::string word, std::string* outWord){
            this->div = div;
            this->cur = cur;
            this->word = word;
            this->outWord = outWord;
        }

        virtual status tick(){
            if(*cur % div == 0) {
                *outWord += word;
                return SUCCESS;
            }
            return FAILURE;
        }

};

int main(){
    int a, b, n, i;
    std::string to_print;
    a = 3;
    b = 5;
    n = 100;

    // fizz buzz tree
    // Create trees
    abstractbehaviourtree *fizzbuzz = new root();
    doallselector dasel;
    fizzbuzzleaf fizz(a, &i, "Fizz", &to_print);
    fizzbuzzleaf buzz(b, &i, "Buzz", &to_print);

    // Connect trees
    *fizzbuzz += &dasel;
    dasel += &fizz;
    dasel += &buzz;

    for(i = 1; i <= n; i++){
        to_print = "";
        if(fizzbuzz->tick() == FAILURE){
            to_print = std::to_string(i);
        }

        std::cout << to_print << std::endl;
    }
}