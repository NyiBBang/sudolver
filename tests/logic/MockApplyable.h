#ifndef LOGIC_TEST_MOCK_APPLYABLE_H
#define LOGIC_TEST_MOCK_APPLYABLE_H

#include "config.h"
#include "logic/IApplyable.h"

MOCK_BASE_CLASS(MockApplyable, IApplyable)
{
    MOCK_METHOD(apply, 0);
};

#endif

