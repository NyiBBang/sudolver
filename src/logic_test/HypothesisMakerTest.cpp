#include "config.h"
#include "MockPossibilitiesRegistry.h"
#include "MockStateSaver.h"
#include "MockBacktrackReason.h"
#include "MockCombinationsRegistry.h"
#include "logic/HypothesisMaker.h"
#include <algorithm>

struct HypoMakerFixture
{
    HypoMakerFixture()
        : grid(new grid_value_type)
        , hypomaker(grid, registry, stateSaver, combregistry)
    {}

    grid_entity_type grid;
    MockPossibilitiesRegistry registry;
    MockStateSaver stateSaver;
    MockCombinationsRegistry combregistry;
    HypothesisMaker hypomaker;
};

BOOST_FIXTURE_TEST_CASE(hypothesis_maker_saves_state_fills_first_cell_in_grid_with_possibility_adds_combination, HypoMakerFixture)
{
    std::fill(grid->begin(), grid->end(), 0);
    mock::sequence s;
    MOCK_EXPECT(registry.valuesForCell).once().in(s).with(0).returns(values_set_type());
    MOCK_EXPECT(registry.valuesForCell).once().in(s).with(1).returns(values_set_type());
    MOCK_EXPECT(registry.valuesForCell).once().in(s).with(2).returns(values_set_type());
    MOCK_EXPECT(registry.valuesForCell).once().in(s).with(3).returns(values_set_type{3, 5, 8});
    MOCK_EXPECT(combregistry.combinationsValuesForCell).once().in(s).with(3).returns(values_set_type());
    MOCK_EXPECT(combregistry.addCombination).once().in(s).with(combination_type{3, 3});
    MOCK_EXPECT(stateSaver.save).once().in(s);
    hypomaker.make();
    BOOST_CHECK_EQUAL((*grid)[3], 3);
}

BOOST_FIXTURE_TEST_CASE(hypothesis_maker_wont_try_a_combination_already_tried, HypoMakerFixture)
{
    std::fill(grid->begin(), grid->end(), 0);
    mock::sequence s;
    MOCK_EXPECT(registry.valuesForCell).once().in(s).with(0).returns(values_set_type());
    MOCK_EXPECT(registry.valuesForCell).once().in(s).with(1).returns(values_set_type{4});
    MOCK_EXPECT(combregistry.combinationsValuesForCell).once().in(s).with(1).returns(values_set_type{1, 4});
    MOCK_EXPECT(registry.valuesForCell).once().in(s).with(2).returns(values_set_type{3, 5, 8});
    MOCK_EXPECT(combregistry.combinationsValuesForCell).once().in(s).with(2).returns(values_set_type{3, 5});
    MOCK_EXPECT(combregistry.addCombination).once().in(s).with(combination_type{2, 8});
    MOCK_EXPECT(stateSaver.save).once().in(s);
    hypomaker.make();
    BOOST_CHECK_EQUAL((*grid)[2], 8);
}

BOOST_FIXTURE_TEST_CASE(hypothesis_maker_must_backtrack_when_one_of_the_backtrack_reason_says_it_should, HypoMakerFixture)
{
    mock::sequence s;
    MockBacktrackReason reason1, reason2;
    hypomaker.addReason(reason1);
    hypomaker.addReason(reason2);
    MOCK_EXPECT(reason1.check).once().in(s).returns(true);
    BOOST_CHECK(hypomaker.mustBacktrack());
    MOCK_EXPECT(reason1.check).once().in(s).returns(false);
    MOCK_EXPECT(reason2.check).once().in(s).returns(true);
    BOOST_CHECK(hypomaker.mustBacktrack());
    MOCK_EXPECT(reason1.check).once().in(s).returns(false);
    MOCK_EXPECT(reason2.check).once().in(s).returns(false);
    BOOST_CHECK(!hypomaker.mustBacktrack());
}

BOOST_FIXTURE_TEST_CASE(hypothesis_maker_restores_old_state_when_backtracked, HypoMakerFixture)
{
    MOCK_EXPECT(stateSaver.restore).once();
    hypomaker.backtrack();
}

