#include "include/utilities.h"

namespace Utilities {
    std::vector<std::__cxx11::string> splitString(std::__cxx11::string s)
    {
        {
            std::vector<std::string> splitedString;
            std::string currentString;
            for(int i = 0; i < s.size(); i++){
                if(s[i] != ' '){
                    currentString.push_back(s[i]);
                }else{
                    splitedString.push_back(currentString);
                    currentString = "";
                }
            }

            if(currentString != "")
                splitedString.push_back(currentString);

            return splitedString;
        }
    }

    void printVector(std::vector<char> v_)
    {
        for(auto element : v_){
            std::cout << element << " ";
        }
    }

    void tabulate(int ammount)
    {
        for(int i = 0; i < ammount * 2; i++){
            std::cout << "\t";
        }
        std::cout << "|->";
    }

}

