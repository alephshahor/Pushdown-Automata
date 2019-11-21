#include <vector>

class TransitionFunction{

    private:

        char mInputSymbol;
        char mPopSymbol;
        std::vector<char> mPushSymbols;
        char  mNextState;


    public:

        TransitionFunction(char inputSymbol, char popSymbol, std::vector<char> pushSymbols, char nextState);

        char popSymbol() const;
        std::vector<char> pushSymbols() const;
        char nextState() const;
        char inputSymbol() const;

};
