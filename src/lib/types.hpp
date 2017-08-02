#pragma once

#include <cstdint>
#include <limits>
#include <set>
#include <stack>
#include <type_traits>
#include <unordered_set>

namespace sudo {

struct Base_grid_part {
    using Index_type = unsigned int;
    Index_type index;
};

template <typename NaturalIntegral = uint8_t, NaturalIntegral Bound = 9>
class Value {
public:
    static_assert(std::is_unsigned<NaturalIntegral>::value,
                  "NaturalIntegral needs to be an unsigned integral type.");
    using Type = NaturalIntegral;

    constexpr Value()
        : _value(std::numeric_limits<Type>::max())
    {
    }

    constexpr Value(Type value)
        : _value(value >= Bound
                     ? throw std::out_of_range("Value '" + to_string(value) +
                                               "' is not lower than bound '" +
                                               to_string(Bound) + "'")
                     : value)
    {
    }

    Value& operator=(Type value)
    {
        if (value >= Bound) {
            throw std::out_of_range("Value '" + to_string(value) +
                                    "' is not lower than bound '" +
                                    to_string(Bound) + "'");
        }
        _value = value;
        return *this;
    }

    const Type operator*() const { return _value; }

    // Regular:
    constexpr bool operator<(const Value& o) const { return _value < o._value; }

    constexpr bool operator<=(const Value& o) const
    {
        return _value <= o._value;
    }

    constexpr bool operator>(const Value& o) const { return _value > o._value; }

    constexpr bool operator>=(const Value& o) const
    {
        return _value >= o._value;
    }

    constexpr bool operator==(const Value& o) const
    {
        return _value == o._value;
    }

    constexpr bool operator!=(const Value& o) const
    {
        return _value != o._value;
    }

private:
    Type _value;
};

struct Cell : public Base_grid_part {
    using Value_type = unsigned int;
    Value_type value;
};

struct Row : public Base_grid_part {
};

struct Column : public Base_grid_part {
};

struct Square : public Base_grid_part {
};

}
