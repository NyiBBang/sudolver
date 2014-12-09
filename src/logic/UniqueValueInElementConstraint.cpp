#include "UniqueValueInElementConstraint.h"
#include "IPossibilitiesRegistry.h"
#include "conversion.h"
#include "complex_static_data.h"

UniqueValueInElementConstraint::UniqueValueInElementConstraint(const grid_entity_type& grid, IPossibilitiesRegistry& registry)
    : grid_(grid)
    , registry_(registry)
{}

void UniqueValueInElementConstraint::apply()
{
    for (index_type cell = 0; cell < max_cell_index; ++cell)
    {
        const value_type value = (*grid_)[cell];
        if (value != 0)
        {
            const index_type row = convert_index<ElementType::Cell, ElementType::Row>(cell);
            const index_type col = convert_index<ElementType::Cell, ElementType::Column>(cell);
            const index_type sqr = convert_index<ElementType::Cell, ElementType::Square>(cell);
            for (index_type adjcell : rows_cells_indexes[row])
                if (adjcell != cell)
                    registry_.remove({adjcell, value});
            for (index_type adjcell : columns_cells_indexes[col])
                if (adjcell != cell)
                    registry_.remove({adjcell, value});
            for (index_type adjcell : squares_cells_indexes[sqr])
                if (adjcell != cell)
                    registry_.remove({adjcell, value});
        }
    }
}

