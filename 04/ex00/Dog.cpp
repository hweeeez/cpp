#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Constructor" << '\n';
	type = "Dog";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog Copy Constructor" << '\n';
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog Copy Assignment Constructor" << '\n';
	Animal::operator=(other);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << '\n';
}

void Dog::makeSound()
{
	std::cout << "BORK" << '\n';
}