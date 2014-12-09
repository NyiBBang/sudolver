#include "UniquePossibilityInElementHeuristic.h"
#include "IPossibilitiesRegistry.h"
#include "complex_static_data.h"
#include "conversion.h"

UniquePossibilityInElementHeuristic::UniquePossibilityInElementHeuristic(IPossibilitiesRegistry& registry)
    : registry_(registry)
{}

void UniquePossibilityInElementHeuristic::apply()
{
    for (index_type cell = 0; cell < max_cell_index; ++cell)
    {
        const index_type row = convert_index<ElementType::Cell, ElementType::Row>(cell);
        const index_type col = convert_index<ElementType::Cell, ElementType::Column>(cell);
        const index_type sqr = convert_index<ElementType::Cell, ElementType::Square>(cell);

        const values_set_type cellValues = registry_.valuesForCell(cell);
        for (auto value : cellValues)
        {
            const cells_set_type cellsForValue = registry_.cellsForValue(value);
            bool uniqueInRow = true;
            bool uniqueInColumn = true;
            bool uniqueInSquare = true;
            for (auto otherCell : cellsForValue)
            {
                if (otherCell == cell) continue;
                if (convert_index<ElementType::Cell, ElementType::Row>(otherCell) == row)
                    uniqueInRow = false;
                if (convert_index<ElementType::Cell, ElementType::Column>(otherCell) == col)
                    uniqueInColumn = false;
                if (convert_index<ElementType::Cell, ElementType::Square>(otherCell) == sqr)
                    uniqueInSquare = false;
            }

            if (uniqueInRow or uniqueInColumn or uniqueInSquare)
            {
                for (auto otherValue : cellValues)
                {
                    if (otherValue == value) continue;
                    registry_.remove({cell, otherValue});
                }
            }
        }
    }
}

