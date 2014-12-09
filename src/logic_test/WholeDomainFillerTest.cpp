#include "config.h"
#include "MockPossibilitiesRegistry.h"
#include "logic/WholeDomainFiller.h"
#include "logic/complex_static_data.h"

BOOST_AUTO_TEST_CASE(whole_domain_filler_fills_possibilities_for_each_cell_with_all_possibilities)
{
    MockPossibilitiesRegistry registry;
    WholeDomainFiller filler(registry);
    for (index_type cell = 0; cell < max_cell_index; ++cell)
        for (auto value : values_set)
            MOCK_EXPECT(registry.add).once().with(possibility_type{cell, value});
    filler.apply();
}

