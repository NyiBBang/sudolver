#include "ChangesChecker.h"

class ChangesSaver
{
    public:
        ChangesSaver(const grid_value_type& agrid, const possibilities_type& aposs)
            : grid(agrid), poss(aposs) {}

        grid_value_type grid;
        possibilities_type poss;
};

ChangesChecker::ChangesChecker(const grid_entity_type& grid, const possibilities_type& poss)
    : reset_(false)
    , grid_(grid)
    , poss_(poss)
{}

ChangesChecker::~ChangesChecker()
{}

void ChangesChecker::reset()
{
    saver_.reset(new ChangesSaver(*grid_, poss_));
}

bool ChangesChecker::hasChanges() const
{
    return !saver_ or saver_->grid != *grid_ or saver_->poss != poss_;
}

bool ChangesChecker::gridHasChanges() const
{
    return saver_->grid != *grid_;
}

