#include "Animal.hpp"

Animal::Animal()
{
}

Animal::Animal(const Animal &animal)
{
	type = animal.type;
}

Animal::~Animal()
{
}

std::string Animal::getType()
{
	return type;
}

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &cat) : Animal(cat)
{
	type = cat.type;
	brain = new Brain(*cat.brain);
}

Cat::~Cat()
{
	delete brain;
}

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	type = dog.type;
	brain = new Brain(*dog.brain);
}

Dog::~Dog()
{
	delete brain;
}

void Animal::makeSound()
{
	std::cout << "Aaaaaaa" << '\n';
}

void Cat::makeSound()
{
	std::cout << "MEOW" << '\n';
}

void Dog::makeSound()
{
	std::cout << "BORK" << '\n';
}