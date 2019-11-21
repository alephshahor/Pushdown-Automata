#include <string>
#include <set>

class AutomataTape{

  private:
    std::string mInputString;
    std::set<char> mAlphabet;
    char* mCurrentSymbol;

  public:
    AutomataTape(std::string inputString, std::set<char> alphabet);
    char currentSymbol() const;
    void shift();

  private:
    void checkInputIsValid() const;
    bool isInAlphabet(char symbol) const;

};
