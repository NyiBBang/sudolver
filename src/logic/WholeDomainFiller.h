#ifndef WHOLE_DOMAIN_FILLER_H
#define WHOLE_DOMAIN_FILLER_H

#include "IApplyable.h"

class IPossibilitiesRegistry;

class WholeDomainFiller : public IApplyable
{
    public:
        WholeDomainFiller(IPossibilitiesRegistry& registry);
        virtual void apply();

    private:
        IPossibilitiesRegistry& registry_;
};

#endif

