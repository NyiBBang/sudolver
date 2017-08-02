#include "config.h"
#include "logic/ChangesChecker.h"
#include <algorithm>

BOOST_AUTO_TEST_CASE(changes_checker_returns_changes_when_not_reset)
{
    grid_entity_type grid(new grid_value_type);
    std::fill(grid->begin(), grid->end(), 0);
    possibilities_type poss;
    ChangesChecker checker(grid, poss);
    BOOST_CHECK(checker.hasChanges());
}

BOOST_AUTO_TEST_CASE(changes_checker_returns_changes_when_grid_has_changed)
{
    grid_entity_type grid(new grid_value_type);
    std::fill(grid->begin(), grid->end(), 0);
    possibilities_type poss;
    ChangesChecker checker(grid, poss);
    checker.reset();
    (*grid)[3] = 42;
    BOOST_CHECK(checker.hasChanges());
}

BOOST_AUTO_TEST_CASE(changes_checker_returns_changes_when_possibilites_have_changed)
{
    grid_entity_type grid(new grid_value_type);
    std::fill(grid->begin(), grid->end(), 0);
    possibilities_type poss;
    ChangesChecker checker(grid, poss);
    checker.reset();
    poss.insert({42, 8});
    BOOST_CHECK(checker.hasChanges());
}

BOOST_AUTO_TEST_CASE(changes_checker_returns_no_changes_when_neither_grid_or_possibilities_have_changed)
{
    grid_entity_type grid(new grid_value_type);
    std::fill(grid->begin(), grid->end(), 0);
    possibilities_type poss;
    ChangesChecker checker(grid, poss);
    checker.reset();
    BOOST_CHECK(!checker.hasChanges());
}

BOOST_AUTO_TEST_CASE(changes_checker_returns_no_changes_after_reset)
{
    grid_entity_type grid(new grid_value_type);
    std::fill(grid->begin(), grid->end(), 0);
    possibilities_type poss;
    ChangesChecker checker(grid, poss);
    checker.reset();
    poss.insert({31, 3});
    BOOST_CHECK(checker.hasChanges());
    checker.reset();
    BOOST_CHECK(!checker.hasChanges());
}

BOOST_AUTO_TEST_CASE(changes_checker_returns_grid_has_changes_when_grid_does_have_changes)
{
    grid_entity_type grid(new grid_value_type);
    std::fill(grid->begin(), grid->end(), 0);
    possibilities_type poss;
    ChangesChecker checker(grid, poss);
    checker.reset();
    (*grid)[3] = 42;
    BOOST_CHECK(checker.gridHasChanges());
}

BOOST_AUTO_TEST_CASE(changes_checker_returns_grid_has_no_changes_if_only_poss_have_changes)
{
    grid_entity_type grid(new grid_value_type);
    std::fill(grid->begin(), grid->end(), 0);
    possibilities_type poss;
    ChangesChecker checker(grid, poss);
    checker.reset();
    poss.insert({31, 3});
    BOOST_CHECK(!checker.gridHasChanges());
}

