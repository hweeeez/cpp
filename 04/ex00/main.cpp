#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main (void)
{
	Animal *meta = new Animal();
	Animal* j = new Dog();
	Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	j->makeSound();
	i->makeSound();
	meta->makeSound();

	WrongAnimal *wrongmeta = new WrongAnimal();
	WrongAnimal* wrongcat = new WrongCat();
	std::cout << wrongcat->getType() << std::endl;
	wrongcat->makeSound();
	wrongmeta->makeSound();
}