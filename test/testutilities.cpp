#include "catch.hpp"
#include "../include/utilities.h"

TEST_CASE("Split string function works properly"){
    std::string s("Hello World Im a Programmer");
    std::vector<std::string> splitedString = Utilities::splitString(s);
    REQUIRE(splitedString[0] == "Hello");
    REQUIRE(splitedString[1] == "World");
    REQUIRE(splitedString[2] == "Im");
    REQUIRE(splitedString[3] == "a");
    REQUIRE(splitedString[4] == "Programmer");
}
