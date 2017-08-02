#ifndef LOGIC_TEST_MOCK_HYPOTHESIS_MAKER_H
#define LOGIC_TEST_MOCK_HYPOTHESIS_MAKER_H

#include "config.h"
#include "logic/IHypothesisMaker.h"

MOCK_BASE_CLASS(MockHypothesisMaker, IHypothesisMaker)
{
    MOCK_METHOD(make, 0);
};

#endif

