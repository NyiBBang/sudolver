#include "BacktrackReasons.h"
#include "IValidator.h"
#include "ICombinationsRegistry.h"
#include "IPossibilitiesRegistry.h"

BacktrackReasons::BacktrackReasons(IValidator& validator, const grid_entity_type& grid,
                                   ICombinationsRegistry& combRegistry, IPossibilitiesRegistry& registry)
    : validator_(validator)
    , grid_(grid)
    , combRegistry_(combRegistry)
    , registry_(registry)
{}

bool BacktrackReasons::check() const
{
    return checkFullInvalid() or checkEmptyCellNoCombi() or checkEmptyCellNoPossib();
}

bool BacktrackReasons::checkFullInvalid() const
{
    return validator_.isFullyDefined() and !validator_.isValid();
}

bool BacktrackReasons::checkEmptyCellNoCombi() const
{
    for (index_type cell = 0; cell < max_cell_index; ++cell)
    {
        if ((*grid_)[cell] != 0) continue;
        values_set_type values = registry_.valuesForCell(cell);
        values_set_type triedCombis = combRegistry_.combinationsValuesForCell(cell);
        bool notTriedCombi = false;
        for (auto value : values)
        {
            if (triedCombis.find(value) == triedCombis.end())
                notTriedCombi = true;
        }
        if (!notTriedCombi) return true;
    }
    return false;
}

bool BacktrackReasons::checkEmptyCellNoPossib() const
{
    for (index_type cell = 0; cell < max_cell_index; ++cell)
    {
        if ((*grid_)[cell] != 0) continue;
        if (registry_.valuesForCell(cell).empty()) return true;
    }
    return false;
}

