#ifndef LOGIC_SOLVING_STEPPER_H
#define LOGIC_SOLVING_STEPPER_H

#include "IStepper.h"

class IApplyable;

class SolvingStepper : public IStepper
{
    public:
        SolvingStepper(IApplyable& heuristic);

        virtual void step();

    private:
        IApplyable& heuristic_;
};

#endif

