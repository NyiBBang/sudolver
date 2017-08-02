#pragma once

#include "types.hpp"
#include <algorithm>

//bool validate(const Grid_type& grid, index_type index, ElementType type)
//{
//    const element_values_type& element_values =
//        element_cells_values(grid, elements_cells_indexes(type)[index]);
//    for (values_set_type::const_iterator it = values_set.begin();
//         it != values_set.end(); ++it) {
//        if (std::find(element_values.begin(), element_values.end(), *it) ==
//            element_values.end())
//            return false;
//    }
//    return true;
//}
//
//template <typename ForwardIterator>
//bool is_valid(ForwardIterator begin, ForwardIterator end)
//{
//    for (index_type index = 0; index < max_element_index; ++index)
//        if (!validate(grid_, index, ElementType::Row))
//            return false;
//    for (index_type index = 0; index < max_element_index; ++index)
//        if (!validate(grid_, index, ElementType::Column))
//            return false;
//    for (index_type index = 0; index < max_element_index; ++index)
//        if (!validate(grid_, index, ElementType::Square))
//            return false;
//    return true;
//}
//
template <typename ForwardIterator>
bool is_fully_defined(ForwardIterator begin, ForwardIterator end)
{
    return std::all_of(
        begin, end,
        [](const typename std::iterator_traits<ForwardIterator>::value_type&
               value) { return value != decltype(value){}; });
}
