#ifndef LOGIC_I_BACKTRACKER_H
#define LOGIC_I_BACKTRACKER_H

class IBacktrackReason;

class IBacktracker
{
    public:
        IBacktracker() {}
        virtual ~IBacktracker() {}

        virtual bool mustBacktrack() const = 0;
        virtual void backtrack() = 0;
        virtual void addReason(IBacktrackReason& reason) = 0;
        virtual void removeReason(IBacktrackReason& reason) = 0;
};

#endif

