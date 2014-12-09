#ifndef VALIDATOR_H
#define VALIDATOR_H

#include "IValidator.h"
#include "complex_types.h"

class Validator : public IValidator
{
    public:
        Validator(const grid_entity_type& grid);

    public:
        virtual bool isValid() const;
        virtual bool isFullyDefined() const;

    private:
        grid_entity_type grid_;
};

#endif

