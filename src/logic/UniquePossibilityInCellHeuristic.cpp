#include "UniquePossibilityInCellHeuristic.h"
#include "IPossibilitiesRegistry.h"

UniquePossibilityInCellHeuristic::UniquePossibilityInCellHeuristic(const grid_entity_type& grid, IPossibilitiesRegistry& registry)
    : grid_(grid)
    , registry_(registry)
{}

void UniquePossibilityInCellHeuristic::apply()
{
   for (index_type cell = 0; cell < max_cell_index; ++cell)
   {
       const values_set_type values = registry_.valuesForCell(cell);
       if (values.size() == 1)
       {
           (*grid_)[cell] = *values.begin();
           for (value_type value : values)
              registry_.remove({cell, value});
       }
   }
}

