#ifndef LOGIC_I_BACKTRACK_REASON_H
#define LOGIC_I_BACKTRACK_REASON_H

class IBacktrackReason
{
    public:
        IBacktrackReason() {}
        virtual ~IBacktrackReason() {}

        virtual bool check() const = 0;
};

#endif

