#include "include/automatastate.h"

AutomataState::AutomataState(std::string identifier):
    mIdentifier(identifier),
    mAcceptationState(false),
    mTransitionFunctions()
{

}

std::string AutomataState::identifier() const
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

bool AutomataState::operator==(AutomataState &other) const
{
    return other.identifier() == mIdentifier;
}

bool AutomataState::acceptationState() const
{
    return mAcceptationState;
}

void AutomataState::setAcceptationState(bool acceptationState)
{
    mAcceptationState = acceptationState;
}


//TODO: Remove this functions when tests are done.

std::vector<TransitionFunction> AutomataState::transitionFunctions() const
{
    return mTransitionFunctions;
}

void AutomataState::setTransitionFunctions(const std::vector<TransitionFunction> &transitionFunctions)
{
    mTransitionFunctions = transitionFunctions;
}
