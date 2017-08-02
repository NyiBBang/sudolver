#ifndef LOGIC_TEST_MOCK_BACKTRACK_REASON_H
#define LOGIC_TEST_MOCK_BACKTRACK_REASON_H

#include "config.h"
#include "logic/IBacktrackReason.h"

MOCK_BASE_CLASS(MockBacktrackReason, IBacktrackReason)
{
    MOCK_METHOD(check, 0);
};

#endif


