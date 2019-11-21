#include <string>

class AutomataTape{
  private:
    std::string mInputString;
    char mCurrentSymbol;

  public:
    AutomataTape(std::string inputString);
    char currentSymbol();
};
