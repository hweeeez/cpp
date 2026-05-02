#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>
#include <string>
//char int float double
//single digit values - convert as char or int

void convertfromint(std::string input)
{
	double res = std::strtod(input.c_str(), NULL);
	if (res >= 32 && res <= 126)
		std::cout << "char: '" << static_cast<char>(res) << "'" << '\n';
	else
		std::cout << "char: Not Displayable" << '\n';
	if (res <= INTMAX && res >= INTMIN)
		std::cout << "int: " << static_cast<int>(res) << '\n';
	else
		std::cout << "int: " << "Impossible" << '\n';
	std::cout  << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(res) << "f" << '\n';
	std::cout << "double: " << static_cast<double>(res) << '\n';
}

void convertfromfloat(std::string input)
{
	float res = std::atof(input.c_str());
	int decimalplaces = 0;
	if (input.find('.') != std::string::npos)
		decimalplaces = input.length() - input.find('.') - 2;
	if (res >= 32 && res <= 126)
	{
		std::cout << "char: '" << static_cast<char>(res) << "'" << '\n';
	}
	else
	{
		std::cout << "char: Not Displayable" << '\n';
	}
	if (res <= INTMAX && res >= INTMIN)
		std::cout << "int: " << static_cast<int>(res) << '\n';
	else
		std::cout << "int: " << "Impossible" << '\n';	
	if (decimalplaces <= 1)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << res << "f"  << '\n';
	std::cout << "double: " << static_cast<double>(res) << '\n';
}

void convertfromdouble(std::string input)
{
	double res = std::strtod(input.c_str(), NULL);
	int decimalplaces = input.length() - input.find('.') - 1;
	if (res >= 32 && res <= 126)
	{
		std::cout << "char: '" << static_cast<char>(res) << "'" << '\n';
	}
	else
	{
		std::cout << "char: Not Displayable" << '\n';
	}
	if (res <= INTMAX && res >= INTMIN)
		std::cout << "int: " << static_cast<int>(res) << '\n';
	else
		std::cout << "int: " << "Impossible" << '\n';
	if (decimalplaces == 1)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(res) << "f"  << '\n';
	std::cout << "double: " << static_cast<double>(res) << '\n';
}

void convertfromchar(std::string input)
{
	char res = input[0];
	std::cout << "char: '" << (res) << "'" << '\n';	
	std::cout << "int: " << static_cast<int>(res) << '\n';
	std::cout  << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(res) << "f"  << '\n';
	std::cout << "double: " << static_cast<double>(res) << '\n';
}

bool ischar(std::string input)
{
	if (input.length() == 1 && !isdigit(input[0]))
	{
		if (isprint(input[0]))
		{
			return true;			
		}		
	}
	return false;
}

std::string gettype(std::string input)
{
	std::string source = input;
	if (input.empty()) return "";
	if (source[0] == '-' || source[0] == '+')
	{
		source.erase(0, 1);
		if (source[0] == '-' || source[0] == '+')
		{
			return "";
		}
	}
	if (source == "inff" || source == "nanf")
	{
		return "float";
	}
	if (source == "inf" || source == "nan")
	{
		return "double";
	}
	if (std::count(input.begin(), input.end(), '.') > 1
	|| std::count(input.begin(), input.end(), 'f') > 1)
		return "";	
	if (ischar(input))
		return "char";
	size_t e = source.find_first_not_of("0123456789");
    if (e != std::string::npos) 
	{
		if (!isdigit(source[0]))
			return "";
        if (source.find_last_of("f") == source.length() - 1)
        {
			if (!isdigit(source[source.length() - 2]))
				return "";
            return "float";
        }
		else
		{
			size_t d = source.find_last_of(".");
			 if (d != std::string::npos)
			 {
				if (!isdigit(source[source.length() - 1]))
					return "";
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