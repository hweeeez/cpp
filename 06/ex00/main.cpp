#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	//std::cout << argv[argc - 1] << '\n';
	if (argc != 2)
	{
		std::cout << "Wrong Input!" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[argc - 1]);

	return 0;
}