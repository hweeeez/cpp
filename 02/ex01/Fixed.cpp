#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default Constructor" << '\n';
}

Fixed::Fixed(const Fixed &fixed) : value(fixed.value)
{
    std::cout << "Copy Constructor" << '\n';
}

Fixed::Fixed(const int val)
{
    value = val >> frac;
    std::cout << "Int Constructor " << value << '\n';
}

Fixed::Fixed(const float val)
{
    value = val / (float)(1 << frac);
}

Fixed::~Fixed()
{
    std::cout << "Destructor" << '\n';
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy Assignment Operator" << '\n';
    if (this != &fixed)
    {
        setRawBits(fixed.getRawBits());
    }
    return *this;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "Setting raw bits" << '\n';
    value = raw;
}

int Fixed::getRawBits(void) const
{
    std::cout << "Getting raw bits" << '\n';
    return value;
}

int Fixed::toInt(void) const
{
    return this->value << frac;
}

float Fixed::toFloat(void) const
{
    return (float)this->value * (float)(1 << frac);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}