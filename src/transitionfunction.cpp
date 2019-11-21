
#include "../include/transitionfunction.h"

TransitionFunction::TransitionFunction(char inputSymbol, char popSymbol, std::set<char> pushSymbols, int nextState):
    mInputSymbol(inputSymbol),
    mPopSymbol(popSymbol),
    mPushSymbols(pushSymbols),
    mNextState(nextState)
{
}


char TransitionFunction::popSymbol() const
{
    return mPopSymbol;
}

std::set<char> TransitionFunction::pushSymbols() const
{
    return mPushSymbols;
}

int TransitionFunction::nextState() const
{
    return mNextState;
}

