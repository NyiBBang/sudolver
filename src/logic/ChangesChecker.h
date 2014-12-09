#ifndef LOGIC_CHANGES_CHECKER_H
#define LOGIC_CHANGES_CHECKER_H

#include "IChangesChecker.h"
#include "complex_types.h"
#include <memory>

class ChangesSaver;

class ChangesChecker : public IChangesChecker
{
    public:
        ChangesChecker(const grid_entity_type& grid, const possibilities_type& poss);
        ~ChangesChecker();

        virtual void reset();
        virtual bool hasChanges() const;
        virtual bool gridHasChanges() const;

    private:
        bool reset_;
        grid_entity_type grid_;
        const possibilities_type& poss_;
        std::unique_ptr<ChangesSaver> saver_;
};

#endif

