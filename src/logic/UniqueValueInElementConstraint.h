#ifndef UNIQUE_VALUE_IN_ELEMENT_CONSTRAINT_H
#define UNIQUE_VALUE_IN_ELEMENT_CONSTRAINT_H

#include "IApplyable.h"
#include "complex_types.h"

class IPossibilitiesRegistry;

class UniqueValueInElementConstraint : public IApplyable
{
    public:
        UniqueValueInElementConstraint(const grid_entity_type& grid, IPossibilitiesRegistry& registry);

        virtual void apply();

    private:
        grid_entity_type grid_;
        IPossibilitiesRegistry& registry_;
};

#endif

