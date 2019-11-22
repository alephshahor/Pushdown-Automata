#include "transitionfunction.h"
#include <string>

class AutomataState{

    private:
        std::string mIdentifier;
        bool        mAcceptationState;
        std::vector<TransitionFunction> mTransitionFunctions;

    public:

        AutomataState(std::string identifier);
        std::string identifier() const;
        void insertTransitionFunction(TransitionFunction function);

        /*!
         * \brief transitionFunction
         * \param symbol
         * \return the transition functions with the parameter symbol
         * as input.
         */
        std::vector<TransitionFunction> transitionFunction(char symbol);
        bool operator<(AutomataState& other) const;
        bool operator ==(AutomataState &other) const;


        bool acceptationState() const;
        void setAcceptationState(bool acceptationState);

        std::vector<TransitionFunction> transitionFunctions() const;
        void setTransitionFunctions(const std::vector<TransitionFunction> &transitionFunctions);
};
