#include "HeuristicsConstraints.h"
#include "WholeDomainFiller.h"
#include "UniqueValueInElementConstraint.h"
#include "FilledCellNoPossibilityConstraint.h"
#include "UniquePossibilityInCellHeuristic.h"
#include "UniquePossibilityInElementHeuristic.h"

HeuristicsConstraints::HeuristicsConstraints(const grid_entity_type& grid, IPossibilitiesRegistry& registry)
    : grid_(grid)
    , registry_(registry)
{
    applyables_.emplace_back(new WholeDomainFiller(registry_));
    applyables_.emplace_back(new UniqueValueInElementConstraint(grid_, registry_));
    applyables_.emplace_back(new FilledCellNoPossibilityConstraint(grid_, registry_));
    applyables_.emplace_back(new UniquePossibilityInElementHeuristic(registry_));
    applyables_.emplace_back(new UniquePossibilityInCellHeuristic(grid_, registry_));
}

void HeuristicsConstraints::apply()
{
    for (const auto& applyable : applyables_)
        applyable->apply();
}

