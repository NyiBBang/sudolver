#ifndef LOGIC_I_VALIDATOR_H
#define LOGIC_I_VALIDATOR_H

class IValidator
{
    public:
        IValidator() {}
        virtual ~IValidator() {}

        virtual bool isValid() const = 0;
        virtual bool isFullyDefined() const = 0;
};

#endif

