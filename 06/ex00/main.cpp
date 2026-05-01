#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	//std::cout << argv[argc - 1] << '\n';
	ScalarConverter::convert(argv[argc - 1]);
	// ScalarConverter::convert("0");
	// ScalarConverter::convert("2.2");
	// ScalarConverter::convert("2.2f");
}