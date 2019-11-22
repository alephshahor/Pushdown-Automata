#include "transitionfunction.h"

class AutomataState{

    private:
        char mIdentifier;
        std::vector<TransitionFunction> mTransitionFunctions;

    public:

        AutomataState(char identifier);
        char identifier() const;
        void insertTransitionFunction(TransitionFunction function);

        /*!
         * \brief transitionFunction
         * \param symbol
         * \return the transition functions with the parameter symbol
         * as input.
         */
        std::vector<TransitionFunction> transitionFunction(char symbol);
        bool operator<(AutomataState& other) const;




};
