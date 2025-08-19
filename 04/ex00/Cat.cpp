#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Constructor" << '\n';
	type = "Cat";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat Copy Constructor" << '\n';
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat Copy Assignment Constructor" << '\n';
	Animal::operator=(other);
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << '\n';
}

void Cat::makeSound()
{
	std::cout << "MEOW" << '\n';
}