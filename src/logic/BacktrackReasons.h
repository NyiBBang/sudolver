#ifndef LOGIC_BACKTRACK_REASONS_H
#define LOGIC_BACKTRACK_REASONS_H

#include "IBacktrackReason.h"
#include "complex_types.h"

class IValidator;
class ICombinationsRegistry;
class IPossibilitiesRegistry;

class BacktrackReasons : public IBacktrackReason
{
    public:
        BacktrackReasons(IValidator& validator, const grid_entity_type& grid,
                         ICombinationsRegistry& combRegistry, IPossibilitiesRegistry& registry);

        virtual bool check() const;
        bool checkFullInvalid() const;
        bool checkEmptyCellNoCombi() const;
        bool checkEmptyCellNoPossib() const;

    private:
        IValidator& validator_;
        grid_entity_type grid_;
        ICombinationsRegistry& combRegistry_;
        IPossibilitiesRegistry& registry_;
};

#endif

