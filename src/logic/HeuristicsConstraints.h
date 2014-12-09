#ifndef LOGIC_HEURISTICS_CONSTRAINTS_H
#define LOGIC_HEURISTICS_CONSTRAINTS_H

#include "IApplyable.h"
#include "complex_types.h"
#include <vector>
#include <memory>

class IPossibilitiesRegistry;

class HeuristicsConstraints : public IApplyable
{
    public:
        HeuristicsConstraints(const grid_entity_type& grid, IPossibilitiesRegistry& registry);

        virtual void apply();

    private:
        grid_entity_type grid_;
        IPossibilitiesRegistry& registry_;
        std::vector<std::unique_ptr<IApplyable>> applyables_;
};

#endif

