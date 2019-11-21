#include <stack>
#include <set>

class AutomataStack{


    private:

        std::set<char> mAlphabet;
        std::stack<char> mStack;

    public:

        AutomataStack(std::set<char> alphabet);

        void push(char symbol);
        char pop();

    private:

        bool isInAlphabet(char symbol);

};
