#ifndef LOGIC_TEST_MOCK_BACKTRACKER_H
#define LOGIC_TEST_MOCK_BACKTRACKER_H

#include "config.h"
#include "logic/IBacktracker.h"

MOCK_BASE_CLASS(MockBacktracker, IBacktracker)
{
    MOCK_METHOD(mustBacktrack, 0);
    MOCK_METHOD(backtrack, 0);
    MOCK_METHOD(addReason, 1);
    MOCK_METHOD(removeReason, 1);
};

#endif


