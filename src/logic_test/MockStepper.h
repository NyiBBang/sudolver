#ifndef LOGIC_TEST_MOCK_STEPPER_H
#define LOGIC_TEST_MOCK_STEPPER_H

#include "config.h"
#include "logic/IStepper.h"

MOCK_BASE_CLASS(MockStepper, IStepper)
{
    MOCK_METHOD(step, 0);
};

#endif


