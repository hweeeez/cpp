#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string _type);
		Animal(const Animal &animal);
		Animal &operator=(const Animal &other);
		virtual ~Animal();
		virtual void makeSound() = 0;
		std::string getType();
};

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &dog);
		~Dog();
		virtual void makeSound();
		std::string getType();
};

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &dog);
		~Cat();
		void makeSound();
		std::string getType();
};

#endif
