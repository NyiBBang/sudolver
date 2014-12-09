#ifndef LOGIC_REGISTRIES_H
#define LOGIC_REGISTRIES_H

#include "IPossibilitiesRegistry.h"
#include "ICombinationsRegistry.h"

class Registries : public IPossibilitiesRegistry
                 , public ICombinationsRegistry
{
    public:
        Registries(possibilities_type& poss, combinations_type& combinations);

        virtual void add(const possibility_type& poss);
        virtual void remove(const possibility_type& poss);
        virtual values_set_type valuesForCell(index_type cell) const;
        virtual cells_set_type cellsForValue(value_type value) const;

        virtual void addCombination(combination_type combi);
        virtual void removeCombination(combination_type combi);
        virtual values_set_type combinationsValuesForCell(index_type cell) const;

    private:
        possibilities_type& poss_;
        combinations_type& combi_;
};

#endif

