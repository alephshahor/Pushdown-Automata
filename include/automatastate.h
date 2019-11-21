#include "transitionfunction.h"

class AutomataState{

    private:

        std::vector<TransitionFunction> mTransitionFunctions;

    public:

        AutomataState();
        void insertTransitionFunction(TransitionFunction function);

        /*!
         * \brief transitionFunction
         * \param symbol
         * \return the transition functions with the parameter symbol
         * as input.
         */
        std::vector<TransitionFunction> transitionFunction(char symbol);




};
