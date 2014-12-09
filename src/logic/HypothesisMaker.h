#ifndef LOGIC_HYPOTHESIS_MAKER_H
#define LOGIC_HYPOTHESIS_MAKER_H

#include "IHypothesisMaker.h"
#include "IBacktracker.h"
#include "complex_types.h"
#include <vector>

class IPossibilitiesRegistry;
class IStateSaver;
class ICombinationsRegistry;

class HypothesisMaker : public IHypothesisMaker
                      , public IBacktracker
{
    public:
        HypothesisMaker(const grid_entity_type& grid, IPossibilitiesRegistry& registry,
                        IStateSaver& stateSaver, ICombinationsRegistry& triedCombRegistry);

        virtual void make();
        virtual bool mustBacktrack() const;
        virtual void backtrack();
        virtual void addReason(IBacktrackReason& reason);
        virtual void removeReason(IBacktrackReason& reason);

    private:
        grid_entity_type grid_;
        IPossibilitiesRegistry& registry_;
        IStateSaver& stateSaver_;
        ICombinationsRegistry& triedCombRegistry_;
        std::vector<IBacktrackReason*> reasons_;
};

#endif

