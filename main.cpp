#define CATCH_CONFIG_RUNNER
#include "mainwindow.h"
#include "include/pushdownautomata.h"
#include "test/catch.hpp"
#include <iostream>
#include <QApplication>

#define TEST_PASSED 0

std::string readInputFileName(){
    std::cout << "Insert the name of the file: ";
    std::string fileName;
    std::getline(std::cin, fileName);
    return fileName;
}

bool readVerboseParameter(){

    bool readed;
    bool verboseMode = false;
    char verboseParameter;

    do{
        readed = true;
        std::cout << "Verbose mode? [Y/N]: ";
        std::cin >> verboseParameter;

        if(verboseParameter == 'Y' || verboseParameter == 'y'){
            verboseMode = true;
        }else if(verboseParameter == 'N' || verboseParameter == 'n'){
            verboseMode = false;
        }else{
            readed = false;
            std::cout << "Invalid verbose option\n";
        }

    }while(!readed);

    getchar();

    return verboseMode;
}



int main(int argc, char *argv[])
{
    // Tests are runned.
    int result = Catch::Session().run(argc, argv);
    // If the tests doesn't pass the application
    // is not executed.
    if(result != TEST_PASSED){
        return result;
    }else{

            std::string fileName = readInputFileName();
            bool verboseMode = readVerboseParameter();

            PushdownAutomata automata(std::string(CURRENT_DIRECTORY) + "/inputs/" + fileName);

            std::string inputString;

            while(true){
                std::cout << "Insert the input string: ";
                std::getline(std::cin, inputString);
                if(automata.isAccepted(inputString, verboseMode)){
                    std::cout << "Is accepted\n";
                }else std::cout << "Is not accepted\n";
        }
    }
}
