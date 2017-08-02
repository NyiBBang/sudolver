#include "config.h"
#include "MockPossibilitiesRegistry.h"
#include "logic/UniquePossibilityInCellHeuristic.h"
#include <algorithm>

BOOST_AUTO_TEST_CASE(unique_possibility_heuristic_fills_any_cell_that_has_a_unique_possible_value_and_removes_all_possibilities_for_that_cell)
{
    grid_entity_type grid(new grid_value_type);
    std::fill(grid->begin(), grid->end(), 0);
    MockPossibilitiesRegistry registry;
    UniquePossibilityInCellHeuristic heuristic(grid, registry);
    MOCK_EXPECT(registry.valuesForCell).once().with(1).returns(values_set_type{8});
    MOCK_EXPECT(registry.valuesForCell).exactly(80).with(mock::less(1) or mock::greater(1)).returns(values_set_type());
    MOCK_EXPECT(registry.remove).once().with(possibility_type{1, 8});
    heuristic.apply();
    BOOST_CHECK_EQUAL((*grid)[1], 8);
}

BOOST_AUTO_TEST_CASE(unique_possibility_heuristic_does_not_fill_cell_with_multiple_possible_values)
{
    grid_entity_type grid(new grid_value_type);
    std::fill(grid->begin(), grid->end(), 0);
    MockPossibilitiesRegistry registry;
    UniquePossibilityInCellHeuristic heuristic(grid, registry);
    MOCK_EXPECT(registry.valuesForCell).once().with(2).returns(values_set_type({4, 2}));
    MOCK_EXPECT(registry.valuesForCell).exactly(80).with(mock::less(2) or mock::greater(2)).returns(values_set_type());
    heuristic.apply();
    BOOST_CHECK_EQUAL((*grid)[2], 0);
}

