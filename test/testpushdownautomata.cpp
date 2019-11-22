#include "catch.hpp"
#include "../include/pushdownautomata.h"

TEST_CASE("Pushdown Automata construction"){
    SECTION("When a correct filepath is provided works"){
        PushdownAutomata automata(std::string(CURRENT_DIRECTORY) + "/inputs/APf.txt");
    }

    SECTION("When an incorrect filepath is provided it fails"){
        bool thereIsError = false;
        try {
            PushdownAutomata automata(std::string(CURRENT_DIRECTORY) + "/inputs/APfail.txt");
        } catch (std::exception& e) {
            thereIsError = true;
        }
        REQUIRE(thereIsError == true);
    }

    PushdownAutomata automata(std::string(CURRENT_DIRECTORY) + "/inputs/APf.txt");
    SECTION("The tape is properly constructed"){
        std::set<char> tapeAlphabet = {'a','b'};
        std::set<char> notTapeAlphabet = {'a','b','c'};
        AutomataTape tape = automata.tape();
        REQUIRE(tape.alphabet() == tapeAlphabet);
        REQUIRE(tape.alphabet() != notTapeAlphabet);
        REQUIRE(tape.currentSymbol() == NULL);
    }

    SECTION("The stack is properly constructed"){
        std::set<char> stackAlphabet = {'S','A'};
        std::set<char> notStackAlphabet = {'S','A','C'};
        AutomataStack stack = automata.stack();
        REQUIRE(stack.alphabet() == stackAlphabet);
        REQUIRE(stack.alphabet() != notStackAlphabet);
        REQUIRE(stack.initialSymbol() == 'S');
        REQUIRE(stack.stack().size() == 1);
        REQUIRE(stack.pop() == 'S');
        REQUIRE(stack.stack().size() == 0);
    }

    SECTION("The current and initial states are set properly"){
        AutomataState* initialState = automata.initialState();
        AutomataState* currentState = automata.currentState();
        REQUIRE(initialState == currentState);
        REQUIRE(initialState -> identifier() == "q1");
        REQUIRE(initialState -> acceptationState() == false);
    }

    SECTION("All the states are created"){
        REQUIRE(automata.states().size() == 3);
        REQUIRE(automata.states()[0].identifier() == "q1");
        REQUIRE(automata.states()[0].acceptationState() == false);
        REQUIRE(automata.states()[1].identifier() == "q2");
        REQUIRE(automata.states()[1].acceptationState() == false);
        REQUIRE(automata.states()[2].identifier() == "q3");
        REQUIRE(automata.states()[2].acceptationState() == true);
    }

    SECTION("All the transition functions are properly created"){
        AutomataState q1 = automata.states()[0];
        std::vector<TransitionFunction> q1TransitionFunctions = q1.transitionFunction('a');
        REQUIRE(q1TransitionFunctions[0].inputSymbol() == 'a');
        REQUIRE(q1TransitionFunctions[0].popSymbol() == 'S');
        REQUIRE(q1TransitionFunctions[0].nextState() == "q1");
        REQUIRE(q1TransitionFunctions[0].pushSymbols().size() == 2);
        REQUIRE(q1TransitionFunctions[0].pushSymbols()[0] == 'A');
        REQUIRE(q1TransitionFunctions[0].pushSymbols()[1] == 'S');

        REQUIRE(q1TransitionFunctions[1].inputSymbol() == 'a');
        REQUIRE(q1TransitionFunctions[1].popSymbol() == 'A');
        REQUIRE(q1TransitionFunctions[1].nextState() == "q1");
        REQUIRE(q1TransitionFunctions[1].pushSymbols().size() == 2);
        REQUIRE(q1TransitionFunctions[1].pushSymbols()[0] == 'A');
        REQUIRE(q1TransitionFunctions[1].pushSymbols()[1] == 'A');

        std::vector<TransitionFunction> q1TransitionFunctions2 = q1.transitionFunction('b');
        REQUIRE(q1TransitionFunctions2[0].inputSymbol() == 'b');
        REQUIRE(q1TransitionFunctions2[0].popSymbol() == 'A');
        REQUIRE(q1TransitionFunctions2[0].nextState() == "q2");
        REQUIRE(q1TransitionFunctions2[0].pushSymbols().size() == 1);
        REQUIRE(q1TransitionFunctions2[0].pushSymbols()[0] == '.');

        AutomataState q2 = automata.states()[1];
        std::vector<TransitionFunction> q2TransitionFunctions = q2.transitionFunction('b');
        REQUIRE(q2TransitionFunctions[0].inputSymbol() == 'b');
        REQUIRE(q2TransitionFunctions[0].popSymbol() == 'A');
        REQUIRE(q2TransitionFunctions[0].nextState() == "q2");
        REQUIRE(q2TransitionFunctions[0].pushSymbols().size() == 1);
        REQUIRE(q2TransitionFunctions[0].pushSymbols()[0] == '.');

        std::vector<TransitionFunction> q2TransitionFunctions2 = q2.transitionFunction('.');
        REQUIRE(q2TransitionFunctions2[0].inputSymbol() == '.');
        REQUIRE(q2TransitionFunctions2[0].popSymbol() == 'S');
        REQUIRE(q2TransitionFunctions2[0].nextState() == "q3");
        REQUIRE(q2TransitionFunctions2[0].pushSymbols().size() == 1);
        REQUIRE(q2TransitionFunctions2[0].pushSymbols()[0] == 'S');

        REQUIRE(automata.states()[2].transitionFunctions().empty() == true);


    }

}


