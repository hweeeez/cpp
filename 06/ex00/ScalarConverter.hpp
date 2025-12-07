#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <limits>

#define INTMAX std::numeric_limits<int>::max()
#define INTMIN std::numeric_limits<int>::min()
#define FLOATMAX std::numeric_limits<float>::max()
#define FLOATMIN std::numeric_limits<int>::min()
#define DOUBLEMAX std::numeric_limits<double:max()
#define DOUBLEMIN std::numeric_limits<int>::min()

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
void convertfromdouble(std::string input);
bool ischar(std::string input);

#endif