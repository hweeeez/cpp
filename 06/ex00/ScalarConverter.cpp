#include "ScalarConverter.hpp"
#include <string>
#include <fstream>

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{

}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
    return *this;
}

ScalarConverter::~ScalarConverter()
{

}

void ScalarConverter::convert(std::string input)
{
    //char int float double
if (input.find_first_not_of("0123456789") == std::string::npos) {
    std::cout << "string '" << s << "' contains only digits\n";
}

}