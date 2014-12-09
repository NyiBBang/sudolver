#include "logic/Solver.h"
#include "logic/SolvingStepper.h"
#include "logic/Registries.h"
#include "logic/HeuristicsConstraints.h"
#include "logic/Validator.h"
#include "logic/ChangesChecker.h"
#include "logic/StateSaver.h"
#include "logic/HypothesisMaker.h"
#include "logic/BacktrackReasons.h"
#include "io.h"
#include <stdexcept>
#include <iostream>

#define CODE_SOLVED 0
#define CODE_INVALID 1
#define CODE_STUCK 2

int main(void)
{
    int res = 0;
    try
    {
        // Get values from input and display it.
        grid_entity_type grid(new grid_value_type());
        std::cin >> *grid;

        // Ask from input if we should try to solve it.
        while (true)
        {
            std::string answer;
            std::getline(std::cin, answer);
            if (std::cin.eof() or std::cin.bad())
                throw std::ios_base::failure("EOF or bad input on cin");
            if (std::cin.fail())
                std::cin.clear();
            else if (answer == "yes")
                break;
            else if (answer == "no")
                return 0;
        }

        // At this point we know we want to solve it.
        possibilities_type poss;
        combinations_type combinations;
        Registries registry(poss, combinations);
        HeuristicsConstraints heuristics(grid, registry);
        Validator validator(grid);
        ChangesChecker checker(grid, poss);
        stack_type stack;
        StateSaver stateSaver(grid, combinations, stack);
        BacktrackReasons reasons(validator, grid, registry, registry);
        HypothesisMaker hypomaker(grid, registry, stateSaver, registry);
        hypomaker.addReason(reasons);
        Solver solver(validator, checker, hypomaker, hypomaker);
        SolvingStepper stepper(heuristics);
        solver.suscribe(stepper);
        solver.run();

        /*
         * After solving, either we were stuck or the grid got fully
         * defined. In either case, check its validity.
         */
        const bool valid = validator.isValid();
        const bool full  = validator.isFullyDefined();
        if (valid)
        {
            std::cout << "Grid was solved :D" << std::endl
                      << "Here's the solution:" << std::endl;
            res = CODE_SOLVED;
        }
        else if (full)
        {
            std::cout << "Grid seems full but is not valid o_O" << std::endl
                      << "Here's the result:" << std::endl;
            res = CODE_INVALID;
        }
        else
        {
            std::cout << "Could not solve grid, got stuck :'(" << std::endl
                      << "Here's where I was:" << std::endl;
            res = CODE_STUCK;
        }
        std::cout << *grid << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << "ERROR: " << ex.what() << std::endl;
    }
    return res;
}
