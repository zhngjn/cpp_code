#include <stdexcept>

#include "kleene3.hpp"

namespace algo
{
namespace logic 
{
namespace
{
constexpr std::uint8_t False = 0;
constexpr std::uint8_t Unknown = 1;
constexpr std::uint8_t True = 2;

std::uint8_t and_table[3][3] = 
{
    {False, False, False},
    {False, Unknown, Unknown},
    {False, Unknown, True},
};

std::uint8_t or_table[3][3] = 
{
    {False, Unknown, True},
    {Unknown, Unknown, True},
    {True, True, True},
};

std::uint8_t not_table[3] = 
{
    True, Unknown, False
};

std::uint8_t toInt(const K3VL& k3) 
{
    if (k3 == K3VL::False) return 0;
    else if (k3 == K3VL::Unknown) return 1;
    else if (k3 == K3VL::True) return 2;
    else throw std::runtime_error("Invalid K3VL in toInt");
}

K3VL fromInt(std::uint8_t v) 
{
    if (v == 0) return K3VL::False;
    else if (v == 1) return K3VL::Unknown;
    else if (v == 2) return K3VL::True;
    else throw std::runtime_error("Invalid value for K3VL in fromInt");
}

} // namespace

K3VL K3VL::False{K3VL::Value::FALSE};
K3VL K3VL::Unknown{K3VL::Value::UNKNOWN};
K3VL K3VL::True{K3VL::Value::TRUE};
    
K3VL K3VL::operator&&(const K3VL& other) const
{
    return fromInt(and_table[toInt(*this)][toInt(other)]);
}

K3VL K3VL::operator||(const K3VL& other) const
{
    return fromInt(or_table[toInt(*this)][toInt(other)]);
}

K3VL K3VL::operator!() const
{
    return fromInt(not_table[toInt(*this)]);
}

} // namespace logic
} // namespace algo