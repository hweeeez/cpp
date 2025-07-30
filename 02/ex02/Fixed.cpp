#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0)
{
    //std::cout << "Default Constructor" << '\n';
}

Fixed::Fixed(const Fixed &fixed)
{
    //std::cout << "Copy Constructor" << '\n';
    *this = fixed;
}

Fixed::Fixed(const int val)
{
    this->value = val << frac;
}

Fixed::Fixed(const float val)
{
    value = static_cast<int> (roundf(val * (1 << frac)));
}

Fixed::~Fixed()
{
    //std::cout << "Destructor" << '\n';
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
    //std::cout << "Copy Assignment Operator" << '\n';
    if (this != &fixed)
    {
        this->setRawBits(fixed.getRawBits());
    }
    return *this;
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "Setting raw bits" << '\n';
    value = raw;
}

int Fixed::getRawBits(void) const
{
    //std::cout << "Getting raw bits" << '\n';
    return value;
}

int Fixed::toInt(void) const
{
    return this->value >> frac;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->value / (1 << frac));
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

Fixed& Fixed::operator++()
{
    this->value += 1;
    return *this;
}

Fixed& Fixed::operator--()
{
    this->value -= 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed old(*this);
    this->value += 1;
    return old;
}

Fixed Fixed::operator--(int)
{
    Fixed old(*this);
    this->value -= 1;
    return old;
}

bool Fixed::operator>(const Fixed& other) const
{
    return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->getRawBits() != other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->getRawBits() == other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other)const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other)const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other)const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
    if (first.getRawBits() > second.getRawBits())
        return second;
    return first;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
    if (first.getRawBits() > second.getRawBits())
        return second;
    return first;
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
    if (first.getRawBits() > second.getRawBits())
        return first;
    return second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
    if (first.getRawBits() > second.getRawBits())
        return first;
    return second;
}
