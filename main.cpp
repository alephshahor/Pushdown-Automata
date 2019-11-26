#define CATCH_CONFIG_RUNNER
#include "mainwindow.h"
#include "include/pushdownautomata.h"
#include "test/catch.hpp"
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    // Tests are runned.
    int result = Catch::Session().run(argc, argv);
    // If the tests doesn't pass the application
    // is not deployed.
    if(result > 0){
        return result;
    }else{
        PushdownAutomata automata(std::string(CURRENT_DIRECTORY) + "/inputs/APf-viernes.txt");
        if(automata.isAccepted("aabcc", true)){
            std::cout << "Is accepted\n";
        }else std::cout << "Is not accepted\n";
//        QApplication a(argc, argv);
//        MainWindow w;q
//        w.show();
//        return a.exec();
    }
}
