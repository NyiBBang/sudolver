#include "FilledCellNoPossibilityConstraint.h"
#include "complex_static_data.h"
#include "IPossibilitiesRegistry.h"

FilledCellNoPossibilityConstraint::FilledCellNoPossibilityConstraint(const grid_entity_type& grid, IPossibilitiesRegistry& registry)
    : grid_(grid)
    , registry_(registry)
{}

void FilledCellNoPossibilityConstraint::apply()
{
    for (index_type cell = 0; cell < max_cell_index; ++cell)
        if ((*grid_)[cell] != 0)
            for (auto value : values_set)
                registry_.remove({cell, value});
}

