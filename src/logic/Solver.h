#ifndef LOGIC_SOLVER_H
#define LOGIC_SOLVER_H

#include <vector>

class IValidator;
class IChangesChecker;
class IStepper;
class IHypothesisMaker;
class IBacktracker;

class Solver
{
    public:
        Solver(IValidator& validator, IChangesChecker& checker, IHypothesisMaker& hypomaker, IBacktracker& backtracker);

        void run();
        void suscribe(IStepper& stepper);
        void unsuscribe(IStepper& stepper);

    private:
        IValidator& validator_;
        IChangesChecker& checker_;
        IHypothesisMaker& hypomaker_;
        IBacktracker& backtracker_;
        std::vector<IStepper*> steppers_;
};

#endif

