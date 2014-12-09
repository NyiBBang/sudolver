#include "HypothesisMaker.h"
#include "IPossibilitiesRegistry.h"
#include "IStateSaver.h"
#include "IBacktrackReason.h"
#include "ICombinationsRegistry.h"

HypothesisMaker::HypothesisMaker(const grid_entity_type& grid, IPossibilitiesRegistry& registry,
                                 IStateSaver& stateSaver, ICombinationsRegistry& triedCombRegistry)
    : grid_(grid)
    , registry_(registry)
    , stateSaver_(stateSaver)
    , triedCombRegistry_(triedCombRegistry)
{}

void HypothesisMaker::make()
{
    for (index_type cell = 0; cell < max_cell_index; ++cell)
    {
        if ((*grid_)[cell] != 0) continue;
        auto values = registry_.valuesForCell(cell);
        if (values.size() > 0)
        {
            auto triedValues = triedCombRegistry_.combinationsValuesForCell(cell);
            for (auto value : values)
            {
                if (triedValues.count(value) == 0)
                {
                    triedCombRegistry_.addCombination({cell, value});
                    stateSaver_.save();
                    (*grid_)[cell] = value;
                    return;
                }
            }
        }
    }
}

bool HypothesisMaker::mustBacktrack() const
{
    for (const auto reason : reasons_)
        if (reason->check())
            return true;
    return false;
}

void HypothesisMaker::backtrack()
{
    stateSaver_.restore();
}

void HypothesisMaker::addReason(IBacktrackReason& reason)
{
    reasons_.push_back(&reason);
}

void HypothesisMaker::removeReason(IBacktrackReason& reason)
{
    reasons_.erase(std::remove(reasons_.begin(), reasons_.end(), &reason),
                   reasons_.end());
}

