#include "complex_static_data.h"
#include "conversion.h"
#include <limits>

const index_type undefined_index = std::numeric_limits<index_type>::max();

namespace
{
    values_set_type compute_values_set()
    {
        values_set_type res;
        for (unsigned short i = 1; i <= max_value; ++i)
            res.insert(i);
        return res;
    }
}

const values_set_type values_set = compute_values_set();

namespace
{
    elements_cells_type compute_rows_cells_indexes()
    {
        elements_cells_type res;
        for (index_type cell_index = 0; cell_index < max_cell_index; ++cell_index)
        {
            const index_type row_index = convert_index<ElementType::Cell, ElementType::Row>(cell_index);
            const index_type col_index = convert_index<ElementType::Cell, ElementType::Column>(cell_index);
            res[row_index][col_index] = cell_index;
        }
        return res;
    }
    elements_cells_type compute_columns_cells_indexes()
    {
        elements_cells_type res;
        for (index_type cell_index = 0; cell_index < max_cell_index; ++cell_index)
        {
            const index_type row_index = convert_index<ElementType::Cell, ElementType::Row>(cell_index);
            const index_type col_index = convert_index<ElementType::Cell, ElementType::Column>(cell_index);
            res[col_index][row_index] = cell_index;
        }
        return res;
    }
    elements_cells_type compute_squares_cells_indexes()
    {
        elements_cells_type res;
        for (index_type sqr_index = 0; sqr_index < max_element_index; ++sqr_index)
        {
            const index_type orig_cell_index = convert_index<ElementType::Square, ElementType::Cell>(sqr_index);
            const index_type orig_row_index = convert_index<ElementType::Cell, ElementType::Row>(orig_cell_index);
            const index_type orig_col_index = convert_index<ElementType::Cell, ElementType::Column>(orig_cell_index);
            for (unsigned short row_off = 0; row_off < 3; ++row_off)
                for (unsigned short col_off = 0; col_off < 3; ++col_off)
                {
                    const index_type cell_index = cell_for(orig_row_index + row_off, orig_col_index + col_off);
                    res[sqr_index][col_off + 3 * row_off] = cell_index;
                }
        }
        return res;
    }
}

const elements_cells_type rows_cells_indexes = compute_rows_cells_indexes();
const elements_cells_type columns_cells_indexes = compute_columns_cells_indexes();
const elements_cells_type squares_cells_indexes = compute_squares_cells_indexes();


