#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>

class ScalarConverter
{
    public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter& operator=(const ScalarConverter &other);
    virtual ~ScalarConverter() = 0;
    static void convert(std::string input);
};

#endif;