#include "config.h"
#include "MockValidator.h"
#include "MockPossibilitiesRegistry.h"
#include "MockCombinationsRegistry.h"
#include "logic/BacktrackReasons.h"
#include <algorithm>

struct ReasonsFixture
{
    ReasonsFixture()
        : grid(new grid_value_type)
        , reasons(validator, grid, combRegistry, registry)
    {
        std::fill(grid->begin(), grid->end(), 1);
    }

    MockValidator validator;
    MockPossibilitiesRegistry registry;
    MockCombinationsRegistry combRegistry;
    grid_entity_type grid;
    BacktrackReasons reasons;
};

BOOST_FIXTURE_TEST_CASE(backtrack_reasons_checks_on_fully_defined_but_invalid_grid, ReasonsFixture)
{
    mock::sequence s;
    MOCK_EXPECT(validator.isFullyDefined).once().in(s).returns(true);
    MOCK_EXPECT(validator.isValid).once().in(s).returns(false);
    BOOST_CHECK(reasons.checkFullInvalid());

    MOCK_EXPECT(validator.isFullyDefined).once().in(s).returns(true);
    MOCK_EXPECT(validator.isValid).once().in(s).returns(true);
    BOOST_CHECK(!reasons.checkFullInvalid());

    MOCK_EXPECT(validator.isFullyDefined).once().in(s).returns(false);
    BOOST_CHECK(!reasons.checkFullInvalid());
}

BOOST_FIXTURE_TEST_CASE(backtrack_reasons_checks_on_empty_cells_with_no_available_combination, ReasonsFixture)
{
    mock::sequence s;
    (*grid)[42] = 0;
    MOCK_EXPECT(registry.valuesForCell).once().in(s).with(42).returns(values_set_type{1, 4});
    MOCK_EXPECT(combRegistry.combinationsValuesForCell).once().in(s).with(42).returns(values_set_type{1, 4});
    BOOST_CHECK(reasons.checkEmptyCellNoCombi());

    MOCK_EXPECT(registry.valuesForCell).once().in(s).with(42).returns(values_set_type{1, 4, 5});
    MOCK_EXPECT(combRegistry.combinationsValuesForCell).once().in(s).with(42).returns(values_set_type{1, 4});
    BOOST_CHECK(!reasons.checkEmptyCellNoCombi());
}

BOOST_FIXTURE_TEST_CASE(backtrack_reasons_checks_on_empty_cells_with_no_possibility, ReasonsFixture)
{
    mock::sequence s;
    (*grid)[42] = 0;
    MOCK_EXPECT(registry.valuesForCell).once().in(s).with(42).returns(values_set_type{});
    BOOST_CHECK(reasons.checkEmptyCellNoPossib());

    MOCK_EXPECT(registry.valuesForCell).once().in(s).with(42).returns(values_set_type{1});
    BOOST_CHECK(!reasons.checkEmptyCellNoPossib());
}

