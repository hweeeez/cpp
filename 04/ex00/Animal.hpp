#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal &animal);
		~Animal();
		virtual void makeSound();
		std::string getType();
};

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &dog);
		~Dog();
		virtual void makeSound();
		std::string getType();
};

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &dog);
		~Cat();
		void makeSound();
		std::string getType();
};

#endif