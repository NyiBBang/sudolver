#ifndef LOGIC_UNIQUE_POSSIBILITY_IN_CELL_HEURISTIC_H
#define LOGIC_UNIQUE_POSSIBILITY_IN_CELL_HEURISTIC_H

#include "IApplyable.h"
#include "complex_types.h"

class IPossibilitiesRegistry;

class UniquePossibilityInCellHeuristic : public IApplyable
{
    public:
        UniquePossibilityInCellHeuristic(const grid_entity_type& grid, IPossibilitiesRegistry& registry);

        virtual void apply();

    private:
        grid_entity_type grid_;
        IPossibilitiesRegistry& registry_;
};

#endif

