#include "config.h"
#include "MockPossibilitiesRegistry.h"
#include "logic/UniquePossibilityInElementHeuristic.h"

BOOST_AUTO_TEST_CASE(unique_possibility_in_element_removes_others_\
possibilities_in_cells_holding_unique_possibility_in_element)
{
    MockPossibilitiesRegistry registry;
    UniquePossibilityInElementHeuristic heuristic(registry);
    mock::sequence s;
    // 3 4 12 and 13 are adjacent so none is part of an element that does not contain one of those cells
    MOCK_EXPECT(registry.valuesForCell).once().in(s).with(12).returns(values_set_type{3, 5});
    MOCK_EXPECT(registry.cellsForValue).once().in(s).with(3).returns(cells_set_type{3, 4, 12, 13});
    MOCK_EXPECT(registry.cellsForValue).once().in(s).with(5).returns(cells_set_type{12});
    MOCK_EXPECT(registry.remove).in(s).once().with(possibility_type{12, 3});

    // 42 43 51 and 52 are adjacent so none is part of an element that does not contain one of those cells
    MOCK_EXPECT(registry.valuesForCell).once().in(s).with(42).returns(values_set_type{1, 4, 6});
    MOCK_EXPECT(registry.cellsForValue).once().in(s).with(1).returns(cells_set_type{42, 43, 51, 52});
    MOCK_EXPECT(registry.cellsForValue).once().in(s).with(4).returns(cells_set_type{42});
    MOCK_EXPECT(registry.remove).in(s).once().with(possibility_type{42, 1});
    MOCK_EXPECT(registry.remove).in(s).once().with(possibility_type{42, 6});
    MOCK_EXPECT(registry.cellsForValue).once().in(s).with(6).returns(cells_set_type{42, 43, 51, 52});

    for (index_type cell = 0; cell < max_cell_index; ++cell)
    {
        if (cell == 12 or cell == 42) continue;
        MOCK_EXPECT(registry.valuesForCell).once().with(cell).returns(values_set_type());
    }
    heuristic.apply();
}

