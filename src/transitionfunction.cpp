#include "../include/transitionfunction.h"
#include "include/utilities.h"
#include <iostream>

TransitionFunction::TransitionFunction(char inputSymbol, char popSymbol, std::vector<char> pushSymbols, std::string nextState):
    mInputSymbol(inputSymbol),
    mPopSymbol(popSymbol),
    mPushSymbols(pushSymbols),
    mNextState(nextState)
{

}

void TransitionFunction::printTransitionFunction()
{
    std::cout << mInputSymbol << "," << mPopSymbol << " ----> ";
    Utilities::printVector(mPushSymbols);
    std::cout << mNextState << "\n";
}


char TransitionFunction::popSymbol() const
{
    return mPopSymbol;
}

std::vector<char> TransitionFunction::pushSymbols() const
{
    return mPushSymbols;
}

std::string TransitionFunction::nextState() const
{
    return mNextState;
}


char TransitionFunction::inputSymbol() const
{
    return mInputSymbol;
}


