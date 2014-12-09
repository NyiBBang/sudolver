#ifndef LOGIC_TEST_MOCK_CHANGES_CHECKER_H
#define LOGIC_TEST_MOCK_CHANGES_CHECKER_H

#include "config.h"
#include "logic/IChangesChecker.h"

MOCK_BASE_CLASS(MockChangesChecker, IChangesChecker)
{
    MOCK_METHOD(reset, 0);
    MOCK_METHOD(hasChanges, 0);
    MOCK_METHOD(gridHasChanges, 0);
};

#endif


