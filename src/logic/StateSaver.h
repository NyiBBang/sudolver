#ifndef LOGIC_STATE_SAVER_H
#define LOGIC_STATE_SAVER_H

#include "IStateSaver.h"
#include "complex_types.h"

class StateSaver : public IStateSaver
{
    public:
        StateSaver(const grid_entity_type& grid, combinations_type& combinations, stack_type& stack);

        virtual void save() const;
        virtual void restore() const;

    private:
        grid_entity_type grid_;
        combinations_type& combi_;
        stack_type& stack_;
};

#endif

