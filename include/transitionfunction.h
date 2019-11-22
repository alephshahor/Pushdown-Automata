#include <vector>
#include <string>

class TransitionFunction{

    private:

        char mInputSymbol;
        char mPopSymbol;
        std::vector<char> mPushSymbols;
        std::string  mNextState;


    public:

        TransitionFunction(char inputSymbol, char popSymbol, std::vector<char> pushSymbols, std::string nextState);

        char popSymbol() const;
        std::vector<char> pushSymbols() const;
        std::string nextState() const;
        char inputSymbol() const;

};
