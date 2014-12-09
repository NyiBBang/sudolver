#include "Solver.h"
#include "IValidator.h"
#include "IChangesChecker.h"
#include "IStepper.h"
#include "IHypothesisMaker.h"
#include "IBacktracker.h"
#include <algorithm>

Solver::Solver(IValidator& validator, IChangesChecker& checker, IHypothesisMaker& hypomaker, IBacktracker& backtracker)
    : validator_(validator)
    , checker_(checker)
    , hypomaker_(hypomaker)
    , backtracker_(backtracker)
{}

void Solver::run()
{
    while (!validator_.isValid() and checker_.hasChanges())
    {
        checker_.reset();
        for (const auto stepper : steppers_)
            stepper->step();
        if (backtracker_.mustBacktrack())
            backtracker_.backtrack();
        else if (!checker_.gridHasChanges())
            hypomaker_.make();
    }
}

void Solver::suscribe(IStepper& stepper)
{
    steppers_.push_back(&stepper);
}

void Solver::unsuscribe(IStepper& stepper)
{
    steppers_.erase(std::remove(steppers_.begin(), steppers_.end(), &stepper), steppers_.end());
}

