#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>

void convertfromint(std::string input)
{
	std::stringstream ss(input);
	int res;
	ss >> res;
	if (res >= 0 && res <= 127 && isprint(res))
	{
		std::cout << "char: '" << static_cast<char>(res) << "'" << '\n';
	}
	else
	{
		std::cout << "Not Displayable" << '\n';
	}
	std::cout << "int: " << (res) << '\n';
	std::cout << "float: " << static_cast<float>(res) << ".0f" << '\n';
	std::cout << "double: " << static_cast<double>(res) << ".0" << '\n';
}

void convertfromfloat(std::string input)
{
	std::stringstream ss(input);
	float res;
	ss >> res;
	input.erase(input.length() - 1);
	int pres = input.substr(input.find(".") + 1, input.length() - 1).length();
	if (res >= 0 && res <= 127 && isprint(res))
	{
		std::cout << "char: '" << static_cast<char>(res) << "'" << '\n';
	}
	else
	{
		std::cout << "Not Displayable" << '\n';
	}
	std::cout << "int: " << static_cast<int>(res) << '\n';
	std::cout << "float: " << std::fixed << std::setprecision(pres) << (res)<< "f"  << '\n';
	std::cout << "double: "<< std::fixed << std::setprecision(pres)  << static_cast<double>(res) << '\n';
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
		return "pseudoliteral";
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