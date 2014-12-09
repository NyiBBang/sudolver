#ifndef LOGIC_I_COMBINATIONS_REGISTRY_H
#define LOGIC_I_COMBINATIONS_REGISTRY_H

#include "complex_types.h"

class ICombinationsRegistry
{
    public:
        ICombinationsRegistry() {}
        virtual ~ICombinationsRegistry() {}

        virtual void addCombination(combination_type combi) = 0;
        virtual void removeCombination(combination_type combi) = 0;
        virtual values_set_type combinationsValuesForCell(index_type cell) const = 0;
};

#endif

