#include "StateSaver.h"

StateSaver::StateSaver(const grid_entity_type& grid, combinations_type& combinations, stack_type& stack)
    : grid_(grid)
    , combi_(combinations)
    , stack_(stack)
{}

void StateSaver::save() const
{
    stack_.push(std::make_pair(*grid_, combi_));
    combi_.clear();
}

void StateSaver::restore() const
{
    if (stack_.size() == 0) return;
    const auto& top = stack_.top();
    grid_->operator=(top.first);
    combi_ = top.second;
    stack_.pop();
}

