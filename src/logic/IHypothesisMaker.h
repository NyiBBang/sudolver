#ifndef LOGIC_I_HYPOTHESIS_MAKER_H
#define LOGIC_I_HYPOTHESIS_MAKER_H

class IHypothesisMaker
{
    public:
        IHypothesisMaker() {}
        virtual ~IHypothesisMaker() {}

        virtual void make() = 0;
};

#endif

