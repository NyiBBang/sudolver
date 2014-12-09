#ifndef LOGIC_COMPLEX_TYPES_H
#define LOGIC_COMPLEX_TYPES_H

#include "basic_types.h"
#include "basic_static_data.h"
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>
#include <set>
#include <unordered_set>
#include <stack>

typedef std::set<value_type> values_set_type;
typedef std::unordered_set<value_type> values_uset_type;
typedef boost::array<value_type, max_cell_index> grid_value_type;
typedef boost::shared_ptr<grid_value_type> grid_entity_type;
typedef boost::array<index_type, cell_by_element> element_cells_type;
typedef boost::array<element_cells_type, max_element_index> elements_cells_type;
typedef std::set<index_type> cells_set_type;
typedef std::unordered_set<index_type> cells_uset_type;
typedef std::pair<index_type, value_type> combination_type;
typedef std::unordered_set<combination_type> combinations_type;
typedef std::pair<grid_value_type, combinations_type> state_type;
typedef std::stack<state_type> stack_type;
typedef std::pair<index_type, value_type> possibility_type;
typedef std::unordered_set<combination_type> possibilities_type;

namespace std
{
    template<>
    class hash<std::pair<index_type, value_type>>
    {
        public:
            size_t operator()(const std::pair<index_type, value_type>& s) const;
    };
}

#endif

