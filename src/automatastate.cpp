#include "include/automatastate.h"

AutomataState::AutomataState(char identifier):
    mIdentifier(identifier),
    mTransitionFunctions()
{

}

char AutomataState::identifier() const
{
    return mIdentifier;
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

bool AutomataState::operator<(AutomataState &other) const
{
    return other.identifier() < mIdentifier;
}


