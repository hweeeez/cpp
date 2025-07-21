#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
    std::cout << "Default Constructor" << '\n';
}

Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy Constructor" << '\n';
    *this = fixed;
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