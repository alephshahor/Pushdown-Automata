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

    /*!
     * \brief shift increments the mCurrentSymbol pointer to the next
     * symbol of the tape.
     */
    void shift();

  private:

    void checkInputIsValid() const;
    bool isInAlphabet(char symbol) const;

};
