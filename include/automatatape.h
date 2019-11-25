#include <string>
#include <set>

class AutomataTape{

  private:
    std::string mInputString;
    std::set<char> mAlphabet;
    char* mCurrentSymbol;

  public:
    AutomataTape(std::set<char> alphabet);
    AutomataTape();

    int inputSize() const;

//    char currentSymbol() const;
    char getSymbol(int position);

    void setInputString(std::string inputString);
    void printTape();

    /*!
     * \brief shift increments the mCurrentSymbol pointer to the next
     * symbol of the tape.
     */
    void shift();

    std::set<char> alphabet() const;
    void setAlphabet(const std::set<char> &alphabet);

private:

    void checkInputIsValid() const;
    bool isInAlphabet(char symbol) const;

};
