#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0)
{
    std::cout << "Default Constructor" << '\n';
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy Constructor" << '\n';
    *this = fixed;
}

Fixed::Fixed(const int val)
{
    this->value = val << frac;
    std::cout << "Int Constructor " << value << '\n';
}

Fixed::Fixed(const float val)
{
    std::cout << "Float Constructor " << value << '\n';
    value = roundf(val * (float)(1 << frac));
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
        this->setRawBits(fixed.getRawBits());
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
    return this->value >> frac;
}

float Fixed::toFloat(void) const
{
    return (float)this->value / (float)(1 << frac);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}