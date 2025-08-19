#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal Constructor" << '\n';
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal Copy Constructor" << '\n';
}

Animal::~Animal()
{
	std::cout << "Animal Destructor" << '\n';
}

Animal& Animal::operator=(const Animal &other)
{
	std::cout << "Animal Copy Assignment Constructor" << '\n';
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

std::string Animal::getType()
{
	return type;
}

void Animal::makeSound()
{
	std::cout << "Aaaaaaa" << '\n';
}