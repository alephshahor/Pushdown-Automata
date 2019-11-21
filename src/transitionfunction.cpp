#include "../include/transitionfunction.h"

TransitionFunction::TransitionFunction(char inputSymbol, char popSymbol, std::vector<char> pushSymbols, char nextState):
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

std::vector<char> TransitionFunction::pushSymbols() const
{
    return mPushSymbols;
}

char TransitionFunction::nextState() const
{
    return mNextState;
}


char TransitionFunction::inputSymbol() const
{
    return mInputSymbol;
}


