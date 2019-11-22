#include "include/pushdownautomata.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <regex>


PushdownAutomata::PushdownAutomata(std::string programFilePath)
{
    std::string program;
    std::ifstream programFile;

    programFile.open(programFilePath);
    if(programFile.is_open()){
            std::stringstream strStream;
            strStream << programFile.rdbuf();
            program = strStream.str();
        }else{
            throw std::runtime_error("File " + programFilePath + " cannot be opened.\n");
        }
     programFile.close();

     // Comments are deleted from the program.
     std::regex comments("#.*");
     program = std::regex_replace(program, comments, "");

     // Empty newlines are deleted from the program.
     std::string tempProgram;
     std::istringstream f(program);
     std::string line;
         while (std::getline(f, line)) {
             if(!line.empty()){
                tempProgram.append(line);
                tempProgram.append("\n");
             }
      }
    program = tempProgram;
    std::cout << program;


//     std::istringstream f(program);
//         std::string line;
//         while (std::getline(f, line)) {
//             if(line.empty()){
//                 std::cout << "Line is empty\n";
//             }else{
//                 std::cout << line << std::endl;
//             }
//         }





}
