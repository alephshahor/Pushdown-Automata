#include "catch.hpp"
#include "../include/transitionfunction.h"

TEST_CASE("Transition function is constructed properly"){
    std::set<char> pushSymbols = {'S','A'};
    TransitionFunction transitionFunction('a','b',pushSymbols,1);
}

TEST_CASE("Transition function getters work properly"){
    std::set<char> pushSymbols = {'S','A'};
    TransitionFunction transitionFunction('a','b',pushSymbols,1);
    REQUIRE(transitionFunction.pushSymbols() == pushSymbols);
    REQUIRE(transitionFunction.popSymbol() == 'b');
    REQUIRE(transitionFunction.nextState() == 1);
}

