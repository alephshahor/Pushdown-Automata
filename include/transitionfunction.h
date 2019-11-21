#include <set>

class TransitionFunction{

    private:

        char mInputSymbol;
        char mPopSymbol;
        std::set<char> mPushSymbols;
        int  mNextState;


    public:

        TransitionFunction(char inputSymbol, char popSymbol, std::set<char> pushSymbols, int nextState);

        char popSymbol() const;
        std::set<char> pushSymbols() const;
        int nextState() const;
};
