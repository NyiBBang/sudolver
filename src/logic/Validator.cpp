#include "Validator.h"
#include "complex_static_data.h"
#include <algorithm>

namespace
{
const elements_cells_type& elements_cells_indexes(ElementType type)
{
    if (type == ElementType::Row) return rows_cells_indexes;
    if (type == ElementType::Column) return columns_cells_indexes;
    if (type == ElementType::Square) return squares_cells_indexes;
    throw std::runtime_error("Unknown element type");
}

typedef boost::array<value_type, cell_by_element> element_values_type;
element_values_type element_cells_values(const grid_entity_type& grid,
                                         const element_cells_type& element_cells)
{
    element_values_type res;
    unsigned short i = 0;
    for (index_type cell_index : element_cells)
        res[i++] = (*grid)[cell_index];
    return res;
}

bool validate(const grid_entity_type& grid, index_type index, ElementType type)
{
    const element_values_type& element_values =
        element_cells_values(grid, elements_cells_indexes(type)[index]);
    for (values_set_type::const_iterator it = values_set.begin(); it != values_set.end(); ++it)
    {
        if (std::find(element_values.begin(), element_values.end(), *it)
                == element_values.end())
            return false;
    }
    return true;
}
}

Validator::Validator(const grid_entity_type& grid)
    : grid_(grid)
{
}

bool Validator::isValid() const
{
    for (index_type index = 0; index < max_element_index; ++index)
        if (!validate(grid_, index, ElementType::Row)) return false;
    for (index_type index = 0; index < max_element_index; ++index)
        if (!validate(grid_, index, ElementType::Column)) return false;
    for (index_type index = 0; index < max_element_index; ++index)
        if (!validate(grid_, index, ElementType::Square)) return false;
    return true;
}

bool Validator::isFullyDefined() const
{
    for (index_type index = 0; index < max_cell_index; ++index)
        if ((*grid_)[index] == 0) return false;
    return true;
}

