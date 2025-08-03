#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Constructor" << '\n';
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	std::cout << "WrongAnimal Copy Constructor" << '\n';
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor" << '\n';
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal Copy Assignment Constructor" << '\n';
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

std::string WrongAnimal::getType()
{
	return type;
}

void WrongAnimal::makeSound()
{
	std::cout << "AAAAAAAAAAAAA" << '\n';
}