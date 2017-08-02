#ifndef LOGIC_TEST_MOCK_COMBINATIONS_REGISTRY_H
#define LOGIC_TEST_MOCK_COMBINATIONS_REGISTRY_H

#include "config.h"
#include "logic/ICombinationsRegistry.h"

MOCK_BASE_CLASS(MockCombinationsRegistry, ICombinationsRegistry)
{
    MOCK_METHOD(addCombination, 1);
    MOCK_METHOD(removeCombination, 1);
    MOCK_METHOD(combinationsValuesForCell, 1);
};

#endif


