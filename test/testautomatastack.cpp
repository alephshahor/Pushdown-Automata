#include "catch.hpp"
#include "../include/automatastack.h"

TEST_CASE("Automata Stack is constructed properly"){
    std::set<char> stackAlphabet = {'A','B','Z'};
    AutomataStack stack(stackAlphabet, 'Z');
}

TEST_CASE("Automata Stack push the Stack initial symbol during construction"){
    std::set<char> stackAlphabet = {'A','B','Z'};
    AutomataStack stack(stackAlphabet, 'Z');
    REQUIRE(stack.pop() == 'Z');
}

TEST_CASE("Automata Stack adding and removing functions work properly"){
    std::set<char> stackAlphabet = {'A','B','Z'};
    AutomataStack stack(stackAlphabet, 'Z');

    stack.push('A');
    stack.push('B');
    REQUIRE(stack.pop() == 'B');
    REQUIRE(stack.pop() == 'A');
    REQUIRE(stack.pop() == 'Z');

    bool thereIsError = false;
    try {
        stack.push('C');
    } catch (std::exception& e) {
         thereIsError = true;
    }
    REQUIRE(thereIsError == true);

}
