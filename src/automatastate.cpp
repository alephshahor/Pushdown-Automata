#include "include/automatastate.h"

AutomataState::AutomataState():
    mTransitionFunctions()
{

}

void AutomataState::insertTransitionFunction(TransitionFunction function)
{
    mTransitionFunctions.push_back(function);
}

std::vector<TransitionFunction> AutomataState::transitionFunction(char symbol)
{
    std::vector<TransitionFunction> functions;
    for(auto function : mTransitionFunctions){
        if(function.inputSymbol() == symbol){
            functions.push_back(function);
        }
    }
    return functions;
}
