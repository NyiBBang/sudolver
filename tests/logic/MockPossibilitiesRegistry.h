#ifndef LOGIC_TEST_MOCK_POSSIBILITIES_REGISTRY_H
#define LOGIC_TEST_MOCK_POSSIBILITIES_REGISTRY_H

#include "config.h"
#include "logic/IPossibilitiesRegistry.h"

MOCK_BASE_CLASS(MockPossibilitiesRegistry, IPossibilitiesRegistry)
{
    MOCK_METHOD(add, 1);
    MOCK_METHOD(remove, 1);
    MOCK_METHOD(valuesForCell, 1);
    MOCK_METHOD(cellsForValue, 1);
};

#endif

