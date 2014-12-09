#ifndef LOGIC_I_CHANGES_CHECKER_H
#define LOGIC_I_CHANGES_CHECKER_H

class IChangesChecker
{
    public:
        IChangesChecker() {}
        virtual ~IChangesChecker() {}

        virtual void reset() = 0;
        virtual bool hasChanges() const = 0;
        virtual bool gridHasChanges() const = 0;
};

#endif

