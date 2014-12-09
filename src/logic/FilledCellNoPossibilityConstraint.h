#ifndef FILLED_CELL_NO_POSSIBILITY_CONSTRAINT_H
#define FILLED_CELL_NO_POSSIBILITY_CONSTRAINT_H

#include "IApplyable.h"
#include "complex_types.h"

class IPossibilitiesRegistry;

class FilledCellNoPossibilityConstraint : public IApplyable
{
    public:
        FilledCellNoPossibilityConstraint(const grid_entity_type& grid, IPossibilitiesRegistry& registry);

        virtual void apply();

    private:
        grid_entity_type grid_;
        IPossibilitiesRegistry& registry_;
};

#endif

