#include "../include/automatatape.h"
#include <stdexcept>

//TODO: Handle the exception in case that the input string is not valid.

AutomataTape::AutomataTape(std::set<char> alphabet):
    mAlphabet(alphabet),
    mCurrentSymbol(nullptr)
{
}

AutomataTape::AutomataTape()
{

}

char AutomataTape::currentSymbol() const
{
    if(mCurrentSymbol)
         return *mCurrentSymbol;
    else return NULL;
}

void AutomataTape::setInputString(std::string inputString)
{
    mInputString = inputString;
    mCurrentSymbol = &mInputString[0];
    checkInputIsValid();
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

// TODO: This functions should be deleted when testing is finished.
std::set<char> AutomataTape::alphabet() const
{
    return mAlphabet;
}

void AutomataTape::setAlphabet(const std::set<char> &alphabet)
{
    mAlphabet = alphabet;
}
