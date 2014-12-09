#include "WholeDomainFiller.h"
#include "complex_static_data.h"
#include "IPossibilitiesRegistry.h"

WholeDomainFiller::WholeDomainFiller(IPossibilitiesRegistry& registry)
    : registry_(registry)
{}

void WholeDomainFiller::apply()
{
    for (index_type cell = 0; cell < max_cell_index; ++cell)
        for (auto value : values_set)
            registry_.add({cell, value});
}

