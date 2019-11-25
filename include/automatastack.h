#include <stack>
#include <set>
#include <vector>
#include <iostream>

class AutomataStack{


    private:

        std::set<char> mAlphabet;
        std::stack<char> mStack;
        char    mInitialSymbol;

    public:

        AutomataStack(std::set<char> alphabet, char initialSymbol);
        AutomataStack(const AutomataStack& other);
        AutomataStack();

        void push(char symbol);
        void push(std::vector<char> symbols);
        char top();
        char pop();

        void printStack();

        void reset();

        std::stack<char> stack() const;
        void setStack(const std::stack<char> &stack);

        char initialSymbol() const;
        void setInitialSymbol(char initialSymbol);

        std::set<char> alphabet() const;
        void setAlphabet(const std::set<char> &alphabet);

private:

        bool isInAlphabet(char symbol);

};
