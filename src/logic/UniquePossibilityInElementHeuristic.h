#ifndef LOGIC_UNIQUE_POSSIBILITY_IN_ELEMENT_HEURISTIC_H
#define LOGIC_UNIQUE_POSSIBILITY_IN_ELEMENT_HEURISTIC_H

#include "IApplyable.h"

class IPossibilitiesRegistry;

class UniquePossibilityInElementHeuristic : public IApplyable
{
    public:
        UniquePossibilityInElementHeuristic(IPossibilitiesRegistry& registry);

        virtual void apply();

    private:
        IPossibilitiesRegistry& registry_;
};

#endif

