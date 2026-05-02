#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <limits>
#include <algorithm>
#include <cstdlib>

#define INTMAX std::numeric_limits<int>::max()
#define INTMIN std::numeric_limits<int>::min()
#define FLOATMAX std::numeric_limits<float>::max()
#define FLOATMIN std::numeric_limits<float>::min()
#define DOUBLEMAX std::numeric_limits<double>::max()
#define DOUBLEMIN std::numeric_limits<double>::min()

class ScalarConverter
{
	private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);	
    ScalarConverter& operator=(const ScalarConverter &other);
	public:
    ~ScalarConverter();
    static void convert(std::string input);
};

std::string gettype(std::string input);
void convertfromint(std::string input);
void convertfromfloat(std::string input);
void convertfromdouble(std::string input);
void convertfromchar(std::string input);
bool ischar(std::string input);

#endif