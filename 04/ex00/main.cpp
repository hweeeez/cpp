#include "Animal.hpp"

int main (void)
{
	Animal *meta = new Animal();
	Animal* j = new Dog();
	Animal *i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();
}