#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main (void)
{
	Animal *animals[10];

	for (int i = 0; i < 5; i++)
	{
		animals[i] = new Dog();
	}
	std::cout << '\n';
	for (int i = 5; i < 10; i++)
	{
		animals[i] = new Cat();
	}
	std::cout << '\n';
	for (int i = 0; i < 10; i++)
	{
		delete(animals[i]);
	}

	std::cout << '\n';
	Cat* cat = new Cat();
	cat->setIdea(2, "honk");
	std::cout << cat->getIdea(2) << '\n';
	std::cout << cat->getIdea(0) << '\n';
	std::cout << cat->getIdea(100) << '\n';

	std::cout << '\n';
	Cat cat2(*cat);
	delete (cat);
	std::cout << cat2.getIdea(2) << '\n';

	std::cout << '\n';
	Cat cat3;
	cat3 = cat2;
	std::cout << cat3.getIdea(2) << '\n';

	std::cout << '\n';
	Dog dog = Dog();
	dog.setIdea(2, "choo choo");
	std::cout << dog.getIdea(2) << '\n';

	return 0;
}