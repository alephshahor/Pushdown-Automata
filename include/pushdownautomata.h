#pragma once
#include "automatastack.h"
#include "automatastate.h"
#include "automatatape.h"

class PushdownAutomata{

    private:

        AutomataTape mTape;
        AutomataStack mStack;
        std::vector<AutomataState> mStates;
        AutomataState* mCurrentState;
        AutomataState* mInitialState;


    public:

        PushdownAutomata(std::string programFilePath);

        AutomataTape tape() const;
        void setTape(const AutomataTape &tape);

        AutomataStack stack() const;
        void setStack(const AutomataStack &stack);

        std::vector<AutomataState> states() const;
        void setStates(const std::vector<AutomataState> &states);

        AutomataState *currentState() const;
        void setCurrentState(AutomataState *currentState);

        AutomataState *initialState() const;

        void setInputString(std::string inputString);

        bool isAccepted(std::string inputString);
        void runMachine(AutomataState* state, AutomataStack currentStack, bool& solutionFound, int currentSymbol);

private:

        void removeComments(std::string& program);
        void removeEmptyLines(std::string& program);
        void createStates(std::string statesIdentifiers);
        void setInitialState(std::string initialState);
        void setAcceptationStates(std::string acceptationStatesIdentifiersString);
        void setTransitionFunction(std::string transitionFunctionString);


        std::set<char> createAlphabet(std::string alphabetString);

        std::vector<AutomataState>::iterator findState(std::string identifier);


};
