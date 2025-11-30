#include "ScalarConverter.hpp"
#include <string>
#include <fstream>

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{

	}
    return *this;
}

ScalarConverter::~ScalarConverter()
{

}

void ScalarConverter::convert(std::string input)
{
    //char int float double //need to skip signs first

	std::string type = gettype(input);
	if (type == "")
	{
		std::cout << "invalid type" << '\n';
	}
	else{
		std::cout << type << '\n';
		if (type == "int")
			convertfromint(input);
		if (type == "float")
			convertfromfloat(input);
		if (type == "double")
			convertfromdouble(input);
	}

}