#ifndef LOGIC_I_APPLYABLE_H
#define LOGIC_I_APPLYABLE_H

class IApplyable
{
    public:
        IApplyable() {}
        virtual ~IApplyable() {}

        virtual void apply() = 0;
};

#endif

