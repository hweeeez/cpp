#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>


class ScalarConverter
{
	private:
	
	public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter& operator=(const ScalarConverter &other);
    virtual ~ScalarConverter() = 0;
    static void convert(std::string input);
};

std::string gettype(std::string input);
void convertfromint(std::string input);
void convertfromfloat(std::string input);

#endif