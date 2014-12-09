#include "config.h"
#include "logic/StateSaver.h"
#include "logic/Registries.h"
#include "logic/HypothesisMaker.h"
#include <algorithm>

BOOST_AUTO_TEST_CASE(brute_force_sequence)
{
    grid_entity_type grid(new grid_value_type);
    std::fill(grid->begin(), grid->end(), 1);
    (*grid)[40] = 0;
    possibilities_type poss;
    combinations_type combis;
    stack_type stack;
    StateSaver stateSaver(grid, combis, stack);
    Registries reg(poss, combis);
    HypothesisMaker hypomaker(grid, reg, stateSaver, reg);
    mock::sequence s;
    poss.insert({40, 3});
    poss.insert({40, 6});
    poss.insert({40, 9});

    hypomaker.make();
    BOOST_CHECK_EQUAL(stack.size(), 1);
    BOOST_CHECK_EQUAL((*grid)[40], 3);
    BOOST_CHECK_EQUAL(combis.size(), 0);

    hypomaker.backtrack();
    BOOST_CHECK_EQUAL(stack.size(), 0);
    BOOST_CHECK_EQUAL((*grid)[40], 0);
    BOOST_REQUIRE_EQUAL(combis.size(), 1);
    combination_type combi = *combis.begin();
    BOOST_CHECK_EQUAL(combi.first, 40);
    BOOST_CHECK_EQUAL(combi.second, 3);

    hypomaker.make();
    BOOST_CHECK_EQUAL(stack.size(), 1);
    BOOST_CHECK_EQUAL((*grid)[40], 6);
    BOOST_CHECK_EQUAL(combis.size(), 0);

    hypomaker.backtrack();
    BOOST_CHECK_EQUAL(stack.size(), 0);
    BOOST_CHECK_EQUAL((*grid)[40], 0);
    BOOST_REQUIRE_EQUAL(combis.size(), 2);

    auto combiit = combis.begin();
    combi = *combiit++;
    BOOST_CHECK_EQUAL(combi.first, 40);
    BOOST_CHECK_EQUAL(combi.second, 3);
    combi = *combiit;
    BOOST_CHECK_EQUAL(combi.first, 40);
    BOOST_CHECK_EQUAL(combi.second, 6);

    hypomaker.make();
    BOOST_CHECK_EQUAL(stack.size(), 1);
    BOOST_CHECK_EQUAL((*grid)[40], 9);
    BOOST_CHECK_EQUAL(combis.size(), 0);
}

