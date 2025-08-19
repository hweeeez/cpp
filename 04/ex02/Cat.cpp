#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Constructor" << '\n';
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat Copy Constructor" << '\n';
	brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat &other)
{
	std::cout << "Cat Copy Assignment Constructor" << '\n';
	if (this != &other)
	{
		type = other.type;
		if (brain)
			delete(brain);
		brain = new Brain(*other.brain);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << '\n';
	delete brain;
}

void Cat::makeSound()
{
	std::cout << "MEOW" << '\n';
}

void Cat::setIdea(int index, std::string idea)
{
	if (index < 0 || index > 99)
	{
		std::cout << "Must be >= 0 && <= 99 " << '\n';
		return ;
	}
	brain->ideas[index] = idea;
}

std::string Cat::getIdea(int index) const
{
	if (index < 0 || index > 99)
	{
		return "Must be >= 0 && <= 99 ";
	}
	return brain->ideas[index];
}