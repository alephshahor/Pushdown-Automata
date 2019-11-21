#include "../include/automatatape.h"
#include <stdexcept>

//TODO: Handle the exception in case that the input string is not valid.
AutomataTape::AutomataTape(std::__cxx11::string inputString, std::set<char> alphabet):
    mInputString(inputString),
    mAlphabet(alphabet)
{
    mCurrentSymbol = &mInputString[0];
    checkInputIsValid();
}

char AutomataTape::currentSymbol() const
{
    return *mCurrentSymbol;
}

void AutomataTape::shift()
{
    if(mCurrentSymbol != nullptr){
        mCurrentSymbol += 1;
    }
}

void AutomataTape::checkInputIsValid() const
{
    if(mInputString.size() < 1){
        throw  std::runtime_error("The size of the string must be at least 1 character long");
    }

    for(auto symbol : mInputString){
        if(!isInAlphabet(symbol)){
            std::string invalidSymbol;
            invalidSymbol.push_back(symbol);
            throw std::runtime_error("Invalid symbol: " + invalidSymbol + "\n");
        }
    }
}

bool AutomataTape::isInAlphabet(char symbol) const
{
    for(auto alphabetSymbol: mAlphabet){
        if(alphabetSymbol == symbol)
            return true;
    }

    return false;
}


