#include "catch.hpp"
#include "../include/automatatape.h"

TEST_CASE("Automata Tape is constructed properly"){

    SECTION("When a valid string is provided"){
        std::set<char> alphabet = {'a','b'};
        std::string inputString = "aabb";
        AutomataTape tape(inputString, alphabet);
        REQUIRE(tape.currentSymbol() == 'a');
    }

    SECTION("But fails if the string input elements are not in the alphabet"){
        bool thereIsError = false;
        try {
            std::set<char> alphabet = {'a','c'};
            std::string inputString = "aabb";
            AutomataTape tape(inputString, alphabet);
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
            AutomataTape tape(inputString, alphabet);
        } catch (std::exception& e) {
            thereIsError = true;
        }

        REQUIRE(thereIsError == true);
    }
}

TEST_CASE("Automata Tape provides the current symbol properly"){

    SECTION("When we the current symbol is the initial symbol"){
        std::set<char> alphabet = {'a','b'};
        std::string inputString = "aabb";
        AutomataTape tape(inputString, alphabet);
        REQUIRE(tape.currentSymbol() == 'a');
    }

    SECTION("When the current symbol is the second symbol"){
        std::set<char> alphabet = {'a','b'};
        std::string inputString = "ab";
        AutomataTape tape(inputString, alphabet);
        tape.shift();
        REQUIRE(tape.currentSymbol() == 'b');
    }

    SECTION("When the current symbol is the last symbol"){
        std::set<char> alphabet = {'a','b'};
        std::string inputString = "ab";
        AutomataTape tape(inputString, alphabet);
        tape.shift();
        tape.shift();
        REQUIRE(tape.currentSymbol() == NULL);
    }
}
