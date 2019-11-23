#include "catch.hpp"
#include "../include/automatatape.h"

TEST_CASE("Automata Tape is constructed properly"){

    SECTION("When a valid string is provided"){
        std::set<char> alphabet = {'a','b'};
        AutomataTape tape(alphabet);
    }
}

TEST_CASE("Automata Tape stores the input string properly"){

   std::set<char> alphabet = {'a','b'};
   std::string inputString = "aabb";
   AutomataTape tape(alphabet);
   tape.setInputString(inputString);

    SECTION("But fails if the string input elements are not in the alphabet"){
        bool thereIsError = false;
        try {
            std::set<char> alphabet = {'a','c'};
            std::string inputString = "aabb";
            AutomataTape tape(alphabet);
            tape.setInputString(inputString);
        } catch (std::exception& e) {
            thereIsError = true;
        }

        REQUIRE(thereIsError == true);
    }

    SECTION("But fails if there's not input string elements"){
        bool thereIsError = false;
        try {
            std::set<char> alphabet = {'a','b'};
            std::string inputString = "";
            AutomataTape tape(alphabet);
            tape.setInputString(inputString);
        } catch (std::exception& e) {
            thereIsError = true;
        }

        REQUIRE(thereIsError == true);
    }
}

TEST_CASE("Automata Tape provides the current symbol properly"){

    SECTION("When we the current symbol is the initial symbol"){

    }

    SECTION("When the current symbol is the second symbol"){
        std::set<char> alphabet = {'a','b'};
        std::string inputString = "ab";
        AutomataTape tape(alphabet);
        tape.setInputString(inputString);
        tape.shift();
        REQUIRE(tape.currentSymbol() == 'b');
    }

    SECTION("When the current symbol is the last symbol"){
        std::set<char> alphabet = {'a','b'};
        std::string inputString = "ab";
        AutomataTape tape(alphabet);
        tape.setInputString(inputString);
        tape.shift();
        tape.shift();
        REQUIRE(tape.currentSymbol() == NULL);
    }

    SECTION("When we specify the symbol by index"){
        std::set<char> alphabet = {'a','b'};
        std::string inputString = "aabb";
        AutomataTape tape(alphabet);
        tape.setInputString(inputString);
        REQUIRE(tape.getSymbol(0) == 'a');
        REQUIRE(tape.getSymbol(1) == 'a');
        REQUIRE(tape.getSymbol(2) == 'b');
        REQUIRE(tape.getSymbol(3) == 'b');

    }
}


