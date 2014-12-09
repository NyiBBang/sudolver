#include "config.h"
#include "logic/StateSaver.h"

namespace std
{
    std::ostream& operator<<(std::ostream& os, const grid_value_type& grid)
    {
        os << "[ ";
        if (grid.size() > 0)
        {
            std::copy(grid.begin(), grid.end() - 1, std::ostream_iterator<value_type>(os, ", "));
            os << *(grid.end() - 1);
        }
        os << " ]";
        return os;
    }
    std::ostream& operator<<(std::ostream& os, const combination_type& combi)
    {
        os << "[ " << combi.first << ", " << combi.second << " ]";
        return os;
    }
    std::ostream& operator<<(std::ostream& os, const combinations_type& combis)
    {
        os << "[ ";
        std::copy(combis.begin(), combis.end(), std::ostream_iterator<combinations_type::key_type>(os, " "));
        os << (combis.size() > 0 ? "" : " ") << "]";
        return os;
    }
    std::ostream& operator<<(std::ostream& os, const state_type& state)
    {
        os << "[ " << state.first << ", " << state.second << " ]";
        return os;
    }
}

BOOST_AUTO_TEST_CASE(state_saver_adds_current_grid_and_combinations_to_stack_when_saving)
{
    grid_entity_type grid(new grid_value_type);
    combinations_type combi;
    combi.insert({2,8});
    combinations_type combiorig = combi;
    stack_type stack;
    StateSaver saver(grid, combi, stack);
    saver.save();
    BOOST_REQUIRE_EQUAL(stack.size(), 1);
    BOOST_CHECK_EQUAL(stack.top(), std::make_pair(*grid, combiorig));
}

BOOST_AUTO_TEST_CASE(state_saver_removes_a_grid_and_combinations_from_stack_when_restoring)
{
    grid_entity_type grid(new grid_value_type);
    combinations_type combi;
    stack_type stack;
    StateSaver saver(grid, combi, stack);
    saver.save();
    BOOST_CHECK_EQUAL(stack.size(), 1);
    saver.restore();
    BOOST_CHECK_EQUAL(stack.size(), 0);
}

BOOST_AUTO_TEST_CASE(state_saver_replaces_current_grid_by_last_saved_one_when_restoring)
{
    grid_entity_type grid(new grid_value_type);
    (*grid)[42] = 6;
    combinations_type combi;
    stack_type stack;
    StateSaver saver(grid, combi, stack);
    saver.save();
    (*grid)[42] = 3;
    saver.restore();
    BOOST_CHECK_EQUAL((*grid)[42], 6);
}

BOOST_AUTO_TEST_CASE(state_saver_clears_curent_combinations_when_saving)
{
    grid_entity_type grid(new grid_value_type);
    combinations_type combi;
    combi.insert({12,5});
    stack_type stack;
    StateSaver saver(grid, combi, stack);
    saver.save();
    BOOST_CHECK(combi.empty());
}

BOOST_AUTO_TEST_CASE(state_saver_replaces_current_combinations_by_last_saved_one_when_restoring)
{
    grid_entity_type grid(new grid_value_type);
    combinations_type combi;
    combi.insert({12,5});
    stack_type stack;
    StateSaver saver(grid, combi, stack);
    saver.save();
    combi.insert({42,9});
    saver.restore();
    BOOST_CHECK_EQUAL(combi.count({42,9}), 0);
}

