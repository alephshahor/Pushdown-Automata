#include "catch.hpp"
#include "../include/automatastate.h"

bool areEqual(TransitionFunction f1, TransitionFunction f2){
    if(f1.nextState() == f2.nextState()
       && f1.popSymbol() == f2.popSymbol()
       && f1.nextState() == f2.nextState()
       && f1.pushSymbols() == f2.pushSymbols()){
        return true;
    }else return false;
}

TEST_CASE("Automata State is constructed properly"){
    AutomataState automataState('r');
}

TEST_CASE("Automata State identifier is defined"){
    AutomataState automataState('r');
    REQUIRE(automataState.identifier() == 'r');
}

TEST_CASE("Automata State's transition functions work properly"){
    std::vector<char> pushSymbols = {'A','B'};
    TransitionFunction transitionFunction('a','b',pushSymbols,'1');
    TransitionFunction transitionFunction2('a','c',pushSymbols,'1');
    TransitionFunction transitionFunction3('b','c',pushSymbols,'1');

    AutomataState automataState('r');
    automataState.insertTransitionFunction(transitionFunction);
    automataState.insertTransitionFunction(transitionFunction2);
    automataState.insertTransitionFunction(transitionFunction3);

    std::vector<TransitionFunction> aFunctions = automataState.transitionFunction('a');
    std::vector<TransitionFunction> bFunctions = automataState.transitionFunction('b');

    REQUIRE(aFunctions.size() == 2);
    int coincidencesCount = 0;
    for(auto function : aFunctions){
        if(areEqual(function, transitionFunction) || areEqual(function, transitionFunction2)){
            coincidencesCount += 1;
        }
    }
    REQUIRE(coincidencesCount == 2);

    REQUIRE(bFunctions.size() == 1);
    auto function = bFunctions.begin();
    REQUIRE(areEqual(*function, transitionFunction3) == true);
}
