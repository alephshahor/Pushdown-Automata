#include "include/automatastack.h"
#include <stdexcept>

AutomataStack::AutomataStack(std::set<char> alphabet, char initialSymbol):
    mInitialSymbol(initialSymbol),
    mAlphabet(alphabet)
{
    push(mInitialSymbol);
}

AutomataStack::AutomataStack(const AutomataStack &other)
{
    mAlphabet = other.alphabet();
    mStack = other.stack();
    mInitialSymbol = other.initialSymbol();
}

AutomataStack::AutomataStack()
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

void AutomataStack::push(std::vector<char> symbols)
{
    for(int i = symbols.size() - 1; i >= 0; i--){
        if(symbols[i] != '.')
            mStack.push(symbols[i]);
    }
}

char AutomataStack::pop(){
    char topSymbol = mStack.top();
    mStack.pop();
    return topSymbol;
}

void AutomataStack::printStack()
{

     std::stack<char> copyStack = mStack;
         while(copyStack.size() > 0){
               std::cout << copyStack.top() << " ";
               copyStack.pop();
         }
         std::cout << "\n";

}

void AutomataStack::reset()
{
    while(!mStack.empty()){
        mStack.pop();
    }
    mStack.push(mInitialSymbol);
}

char AutomataStack::top(){
    return mStack.top();
}

bool AutomataStack::isInAlphabet(char symbol)
{
        for(auto alphabetSymbol: mAlphabet){
            if(alphabetSymbol == symbol)
                return true;
        }

        return false;
}

// TODO: Remove this methods when testing is finished

std::stack<char> AutomataStack::stack() const
{
    return mStack;
}

void AutomataStack::setStack(const std::stack<char> &stack)
{
    mStack = stack;
}

char AutomataStack::initialSymbol() const
{
    return mInitialSymbol;
}

void AutomataStack::setInitialSymbol(char initialSymbol)
{
    mInitialSymbol = initialSymbol;
}

std::set<char> AutomataStack::alphabet() const
{
    return mAlphabet;
}

void AutomataStack::setAlphabet(const std::set<char> &alphabet)
{
    mAlphabet = alphabet;
}

