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
    size_t e = input.find_first_not_of("0123456789");
    if (e == std::string::npos) {
        std::cout << "string '" << input << "' contains only digits\n";
    }
    if (e > 0 && e != std::string::npos) {
        if (input.find_last_of("f") == input.length() - 1)
        {
            std::cout << "float" << '\n';
        }
}

}