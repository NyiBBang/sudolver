#include "config.h"
#include "MockValidator.h"
#include "MockStepper.h"
#include "MockChangesChecker.h"
#include "MockHypothesisMaker.h"
#include "MockBacktracker.h"
#include "logic/Solver.h"

struct SolverFixture
{
    SolverFixture()
        : solver(validator, checker, hypomaker, backtracker)
    {}

    MockValidator validator;
    MockChangesChecker checker;
    MockHypothesisMaker hypomaker;
    MockBacktracker backtracker;
    Solver solver;
    mock::sequence s;
};

BOOST_FIXTURE_TEST_CASE(solver_calls_step_on_each_stepper_every_step_until_valid_or_no_changes, SolverFixture)
{
    MockStepper stepper1, stepper2;
    solver.suscribe(stepper1);
    solver.suscribe(stepper2);
    MOCK_EXPECT(validator.isValid).once().in(s).returns(false);
    MOCK_EXPECT(checker.hasChanges).once().in(s).returns(true);
    MOCK_EXPECT(checker.reset).once().in(s);
    MOCK_EXPECT(stepper1.step).once().in(s);
    MOCK_EXPECT(stepper2.step).once().in(s);
    MOCK_EXPECT(backtracker.mustBacktrack).once().in(s).returns(false);
    MOCK_EXPECT(checker.gridHasChanges).once().in(s).returns(true);
    MOCK_EXPECT(validator.isValid).once().in(s).returns(true);
    solver.run();
}

BOOST_FIXTURE_TEST_CASE(solver_stops_if_there_is_no_changes_between_two_steps_even_if_not_valid, SolverFixture)
{
    MockStepper stepper;
    solver.suscribe(stepper);
    MOCK_EXPECT(validator.isValid).once().in(s).returns(false);
    MOCK_EXPECT(checker.hasChanges).once().in(s).returns(true);
    MOCK_EXPECT(checker.reset).once().in(s);
    MOCK_EXPECT(stepper.step).once().in(s);
    MOCK_EXPECT(backtracker.mustBacktrack).once().in(s).returns(false);
    MOCK_EXPECT(checker.gridHasChanges).once().in(s).returns(true);
    MOCK_EXPECT(validator.isValid).once().in(s).returns(false);
    MOCK_EXPECT(checker.hasChanges).once().in(s).returns(false);
    solver.run();
}

BOOST_FIXTURE_TEST_CASE(solver_will_try_to_make_an_hypothesis_about_a_cell_if_grid_didnot_change_after_heuristics, SolverFixture)
{
    MockStepper stepper;
    solver.suscribe(stepper);
    MOCK_EXPECT(validator.isValid).once().in(s).returns(false);
    MOCK_EXPECT(checker.hasChanges).once().in(s).returns(true);
    MOCK_EXPECT(checker.reset).once().in(s);
    MOCK_EXPECT(stepper.step).once().in(s);
    MOCK_EXPECT(backtracker.mustBacktrack).once().in(s).returns(false);
    MOCK_EXPECT(checker.gridHasChanges).once().in(s).returns(false);
    MOCK_EXPECT(hypomaker.make).once().in(s);
    MOCK_EXPECT(validator.isValid).once().in(s).returns(true);
    solver.run();
}

BOOST_FIXTURE_TEST_CASE(solver_backtracks_if_it_has_to_and_then_restarts_the_loop, SolverFixture)
{
    MockStepper stepper;
    solver.suscribe(stepper);
    MOCK_EXPECT(validator.isValid).once().in(s).returns(false);
    MOCK_EXPECT(checker.hasChanges).once().in(s).returns(true);
    MOCK_EXPECT(checker.reset).once().in(s);
    MOCK_EXPECT(stepper.step).once().in(s);
    MOCK_EXPECT(backtracker.mustBacktrack).once().in(s).returns(true);
    MOCK_EXPECT(backtracker.backtrack).once().in(s);
    MOCK_EXPECT(validator.isValid).once().in(s).returns(false);
    MOCK_EXPECT(checker.hasChanges).once().in(s).returns(true);
    MOCK_EXPECT(checker.reset).once().in(s);
    MOCK_EXPECT(stepper.step).once().in(s);
    MOCK_EXPECT(backtracker.mustBacktrack).once().in(s).returns(false);
    MOCK_EXPECT(checker.gridHasChanges).once().in(s).returns(true);
    MOCK_EXPECT(validator.isValid).once().in(s).returns(true);
    solver.run();
}

