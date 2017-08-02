#ifndef LOGIC_TEST_MOCK_VALIDATOR_H
#define LOGIC_TEST_MOCK_VALIDATOR_H

#include "config.h"
#include "logic/IValidator.h"

MOCK_BASE_CLASS(MockValidator, IValidator)
{
    MOCK_METHOD(isFullyDefined, 0);
    MOCK_METHOD(isValid, 0);
};

#endif

