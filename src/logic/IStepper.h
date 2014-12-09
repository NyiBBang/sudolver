#ifndef LOGIC_I_STEPPER_H
#define LOGIC_I_STEPPER_H

class IStepper
{
    public:
        IStepper() {}
        virtual ~IStepper() {}

        virtual void step() = 0;
};

#endif

