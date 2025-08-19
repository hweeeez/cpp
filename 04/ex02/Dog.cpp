#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog Constructor" << '\n';
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog Copy Constructor" << '\n';
	brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog &other)
{
	std::cout << "Dog Copy Assignment Constructor" << '\n';
	if (this != &other)
	{
		Animal::operator=(other);
		if (brain)
			delete(brain);
		brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << '\n';
	delete brain;
}

void Dog::makeSound()
{
	std::cout << "BORK" << '\n';
}

void Dog::setIdea(int index, std::string idea)
{
	if (index < 0 || index > 99)
	{
		std::cout << "Must be >= 0 && <= 99 " << '\n';
		return ;
	}
	brain->ideas[index] = idea;
}

std::string Dog::getIdea(int index) const
{
	if (index < 0 || index > 99)
	{
		return "Must be >= 0 && <= 99 ";
	}
	return brain->ideas[index];
}