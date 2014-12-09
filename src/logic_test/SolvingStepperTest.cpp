#include "config.h"
#include "MockApplyable.h"
#include "logic/SolvingStepper.h"

BOOST_AUTO_TEST_CASE(solving_stepper_applies_its_applyable_heuristic_once_when_stepped)
{
    MockApplyable applyable;
    SolvingStepper solver(applyable);
    MOCK_EXPECT(applyable.apply).once();
    solver.step();
}

