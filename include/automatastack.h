#include <stack>
#include <set>

class AutomataStack{


    private:

        std::set<char> mAlphabet;
        std::stack<char> mStack;
        char    mInitialSymbol;

    public:

        AutomataStack(std::set<char> alphabet, char initialSymbol);
        AutomataStack();

        void push(char symbol);
        char pop();

        std::stack<char> stack() const;
        void setStack(const std::stack<char> &stack);

        char initialSymbol() const;
        void setInitialSymbol(char initialSymbol);

        std::set<char> alphabet() const;
        void setAlphabet(const std::set<char> &alphabet);

private:

        bool isInAlphabet(char symbol);

};
