#include "SolvingStepper.h"
#include "IApplyable.h"

SolvingStepper::SolvingStepper(IApplyable& heuristic)
    : heuristic_(heuristic)
{}

void SolvingStepper::step()
{
    heuristic_.apply();
}

