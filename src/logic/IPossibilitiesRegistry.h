#ifndef LOGIC_I_POSSIBILITIES_REGISTRY_H
#define LOGIC_I_POSSIBILITIES_REGISTRY_H

#include "complex_types.h"

class IPossibilitiesRegistry
{
    public:
        IPossibilitiesRegistry() {}
        virtual ~IPossibilitiesRegistry() {}

        virtual void add(const possibility_type& poss) = 0;
        virtual void remove(const possibility_type& poss) = 0;
        virtual values_set_type valuesForCell(index_type cell) const = 0;
        virtual cells_set_type cellsForValue(value_type value) const = 0;
};

#endif

