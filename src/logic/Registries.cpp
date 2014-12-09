#include "Registries.h"

Registries::Registries(possibilities_type& poss, combinations_type& combinations)
    : poss_(poss)
    , combi_(combinations)
{}

void Registries::add(const possibility_type& poss)
{
    poss_.insert(poss);
}

void Registries::remove(const possibility_type& poss)
{
    poss_.erase(poss);
}

values_set_type Registries::valuesForCell(index_type cell) const
{
    values_uset_type res;
    for (const auto& poss : poss_)
        if (poss.first == cell)
            res.insert(poss.second);
    return values_set_type(res.begin(), res.end());
}

cells_set_type Registries::cellsForValue(value_type value) const
{
    cells_uset_type res;
    for (const auto& poss : poss_)
        if (poss.second == value)
            res.insert(poss.first);
    return cells_set_type(res.begin(), res.end());
}

void Registries::addCombination(combination_type combi)
{
    combi_.insert(combi);
}

void Registries::removeCombination(combination_type combi)
{
    combi_.erase(combi);
}

values_set_type Registries::combinationsValuesForCell(index_type cell) const
{
    values_uset_type res;
    for (const auto& combi : combi_)
        if (combi.first == cell)
            res.insert(combi.second);
    return values_set_type(res.begin(), res.end());
}
