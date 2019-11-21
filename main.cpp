#define CATCH_CONFIG_RUNNER
#include "mainwindow.h"
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
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        return a.exec();
    }
}
