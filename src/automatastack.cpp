#include "include/automatastack.h"
#include <stdexcept>


AutomataStack::AutomataStack(std::set<char> alphabet):
    mAlphabet(alphabet)
{

}

//TODO: Handle exception
void AutomataStack::push(char symbol)
{
    if(isInAlphabet(symbol)){
        mStack.push(symbol);
    }else{
        std::string invalidSymbol;
        invalidSymbol.push_back(symbol);
        throw std::runtime_error("Invalid symbol" + invalidSymbol + "\n");
    }
}

char AutomataStack::pop(){
    char topSymbol = mStack.top();
    mStack.pop();
    return topSymbol;
}

bool AutomataStack::isInAlphabet(char symbol)
{
        for(auto alphabetSymbol: mAlphabet){
            if(alphabetSymbol == symbol)
                return true;
        }

        return false;
}
