#include "config.h"
#include "MockPossibilitiesRegistry.h"
#include "logic/FilledCellNoPossibilityConstraint.h"
#include "logic/complex_static_data.h"
#include <algorithm>

BOOST_AUTO_TEST_CASE(constraint_remove_all_possibilities_from_filled_cells)
{
    grid_entity_type grid(new grid_value_type);
    std::fill(grid->begin(), grid->end(), 0);
    MockPossibilitiesRegistry registry;
    FilledCellNoPossibilityConstraint constraint(grid, registry);
    (*grid)[12] = 3;
    (*grid)[53] = 8;
    for (auto value : values_set)
    {
        MOCK_EXPECT(registry.remove).once().with(possibility_type{12, value});
        MOCK_EXPECT(registry.remove).once().with(possibility_type{53, value});
    }
    constraint.apply();
}

