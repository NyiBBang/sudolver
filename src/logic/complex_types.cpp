#include "complex_types.h"

size_t std::hash<std::pair<index_type, value_type>>::operator()(const std::pair<index_type, value_type>& combi) const
{
    return hash<int>()(combi.first) * 4993 * hash<int>()(combi.second) * 4999;
}

