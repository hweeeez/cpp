#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int value;
        static const int frac = 8;
    public:
        Fixed();
        Fixed(const Fixed &fixed);
        Fixed(const int val);
        Fixed(const float val);
        ~Fixed();
        Fixed & operator = (const Fixed &fixed);
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++(int);
        Fixed operator--(int);
        Fixed operator*(const Fixed& other) const;
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        static Fixed& min(Fixed& first, Fixed& second);
        static const Fixed& min(const Fixed& first, const Fixed& second);
        static Fixed& max(Fixed& first, Fixed& second);
        static const Fixed& max(const Fixed& first, const Fixed& second);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif