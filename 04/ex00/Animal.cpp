#include "Animal.hpp"

Animal::Animal()
{
}

// Animal::Animal(const Animal &animal)
// {
// 	std::cout << "Copy Constructor" << '\n';
// }

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
}

// Cat::Cat(const Cat &cat)
// {
	
// }

Cat::~Cat()
{

}

Dog::Dog()
{
	type = "Dog";
}

// Dog::Dog(const Dog &dog)
// {

// }

Dog::~Dog()
{

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