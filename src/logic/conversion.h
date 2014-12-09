#ifndef LOGIC_CONVERSION_H
#define LOGIC_CONVERSION_H

#include "basic_types.h"

template<ElementType TypeFrom, ElementType TypeTo>
index_type convert_index(index_type index);
index_type cell_for(index_type row, index_type column);

#endif

