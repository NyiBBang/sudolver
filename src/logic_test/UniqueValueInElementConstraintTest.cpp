#include "config.h"
#include "MockPossibilitiesRegistry.h"
#include "logic/UniqueValueInElementConstraint.h"
#include <algorithm>

BOOST_AUTO_TEST_CASE(constraint_removes_value_possibilities_in_element_when_value_is_set_in_element)
{
    grid_entity_type grid(new grid_value_type);
    std::fill(grid->begin(), grid->end(), 0);
    const value_type valueset = 2;
    (*grid)[33] = valueset;
    MockPossibilitiesRegistry registry;
    UniqueValueInElementConstraint constraint(grid, registry);
    // Row
    MOCK_EXPECT(registry.remove).once().with(possibility_type{27, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{28, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{29, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{30, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{31, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{32, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{34, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{35, valueset});
    // Column
    MOCK_EXPECT(registry.remove).once().with(possibility_type{6,  valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{15, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{24, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{42, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{51, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{60, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{69, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{78, valueset});
    // Square
    MOCK_EXPECT(registry.remove).once().with(possibility_type{34, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{35, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{42, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{43, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{44, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{51, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{52, valueset});
    MOCK_EXPECT(registry.remove).once().with(possibility_type{53, valueset});
    constraint.apply();
}

