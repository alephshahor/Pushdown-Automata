#include "catch.hpp"
#include "../include/automatastack.h"

TEST_CASE("Automata Stack is constructed properly"){
    std::set<char> stackAlphabet = {'A','B'};
    AutomataStack stack(stackAlphabet);
}

TEST_CASE("Automata Stack adding and removing functions work properly"){
    std::set<char> stackAlphabet = {'A','B'};
    AutomataStack stack(stackAlphabet);

    stack.push('A');
    stack.push('B');
    REQUIRE(stack.pop() == 'B');
    REQUIRE(stack.pop() == 'A');

    bool thereIsError = false;
    try {
        stack.push('C');
    } catch (std::exception& e) {
         thereIsError = true;
    }
    REQUIRE(thereIsError == true);

}
