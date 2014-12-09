#ifndef LOGIC_TEST_MOCK_STATE_SAVER_H
#define LOGIC_TEST_MOCK_STATE_SAVER_H

#include "config.h"
#include "logic/IStateSaver.h"

MOCK_BASE_CLASS(MockStateSaver, IStateSaver)
{
    MOCK_METHOD(save, 0);
    MOCK_METHOD(restore, 0);
};

#endif

