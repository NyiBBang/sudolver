#include "conversion.h"
#include "basic_static_data.h"
#include <stdexcept>

template<>
index_type convert_index<ElementType::Cell, ElementType::Row>(index_type index)
{
    if (index >= max_cell_index) throw std::out_of_range("Cell index is out of bound");
    return index / 9;
}

template<>
index_type convert_index<ElementType::Cell, ElementType::Column>(index_type index)
{
    if (index >= max_cell_index) throw std::out_of_range("Cell index is out of bound");
    return index % 9;
}

template<>
index_type convert_index<ElementType::Cell, ElementType::Square>(index_type index)
{
    if (index >= max_cell_index) throw std::out_of_range("Cell index is out of bound");
    return (index / 27) * 3 + (index % 9) / 3;
}

template<>
index_type convert_index<ElementType::Row, ElementType::Cell>(index_type index)
{
    if (index >= max_element_index) throw std::out_of_range("Row index is out of bound");
    return index * max_element_index;
}

template<>
index_type convert_index<ElementType::Column, ElementType::Cell>(index_type index)
{
    if (index >= max_element_index) throw std::out_of_range("Column index is out of bound");
    return index;
}

template<>
index_type convert_index<ElementType::Square, ElementType::Cell>(index_type index)
{
    if (index >= max_element_index) throw std::out_of_range("Square index is out of bound");
    return (index / 3) * 27 + (index % 3) * 3;
}

index_type cell_for(index_type row, index_type column)
{
    if (row >= max_element_index) throw std::out_of_range("Row index is out of bound");
    if (column >= max_element_index) throw std::out_of_range("Column index is out of bound");
    const index_type cell = convert_index<ElementType::Row, ElementType::Cell>(row);
    return cell + column;
}

