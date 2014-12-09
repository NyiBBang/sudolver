#ifndef LOGIC_I_STATE_SAVER_H
#define LOGIC_I_STATE_SAVER_H

class IStateSaver
{
    public:
        IStateSaver() {}
        virtual ~IStateSaver() {}

        virtual void save() const = 0;
        virtual void restore() const = 0;
};

#endif

