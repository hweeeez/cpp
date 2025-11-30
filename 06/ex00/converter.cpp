#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>
#include <bits/stdc++.h>
#include <string>

void convertfromint(std::string input)
{
	long res = std::atol(input.c_str());
	if (res >= 0 && res <= 127 && isprint(res))
	{
		std::cout << "char: '" << static_cast<char>(res) << "'" << '\n';
	}
	else
	{
		std::cout << "Not Displayable" << '\n';
	}
	if (res <= INTMAX && res >= INTMIN)
		std::cout << "int: " << static_cast<int>(res) << '\n';
	std::cout << "float: " << static_cast<float>(res) << ".0f" << '\n';
	std::cout << "double: " << static_cast<double>(res) << ".0" << '\n';
}

void convertfromfloat(std::string input)
{
	float res = std::atof(input.c_str());
	if (res >= 0 && res <= 127 && isprint(res))
	{
		std::cout << "char: '" << static_cast<char>(res) << "'" << '\n';
	}
	else
	{
		std::cout << "Not Displayable" << '\n';
	}
	std::cout << "int: " << static_cast<int>(res) << '\n';
	std::cout << "float: " << res << "f"  << '\n';
	std::cout << "double: " << static_cast<double>(res) << '\n';
}

void convertfromdouble(std::string input)
{
	float res = std::atof(input.c_str());
	if (res >= 0 && res <= 127 && isprint(res))
	{
		std::cout << "char: '" << static_cast<char>(res) << "'" << '\n';
	}
	else
	{
		std::cout << "Not Displayable" << '\n';
	}
	std::cout << "int: " << static_cast<int>(res) << '\n';
	std::cout << "float: " << static_cast<float>(res) << "f"  << '\n';
	std::cout << "double: " << (res) << '\n';
}

std::string gettype(std::string input)
{
	std::string source = input;
	if (source[0] == '-' || source[0] == '+')
	{
		source.erase(0, 1);
		if (source[0] == '-' || source[0] == '+')
		{
			return "";
		}
	}
	if (source.find("inf") != std::string::npos || source.find("nan") != std::string::npos)
	{ 
		if (source.find_last_of("f") == source.length() - 1)
			return "float";
		return "double";
	}
	if (source.length() == 1)
	{
		//this is a character
		if (isprint(source[0]))
		{
			if (isdigit(source[0]))
			{
				return "int";
			}
			else{
				return "char";
			}
		}
		else{
			std::cout << "This is not a displayable character!" << '\n';
			return NULL;
		}
	}
	size_t e = source.find_first_not_of("0123456789");
    if (e > 0 && e != std::string::npos) 
	{
        if (source.find_last_of("f") == source.length() - 1)
        {
            return "float";
        }
		else
		{
			size_t d = source.find_last_of(".");
			 if (d > 0 && d != std::string::npos)
			 {
				return "double";
			 }
		}
	}
	else if (e == std::string::npos)
	{
		return "int";
	}
	return "";
}