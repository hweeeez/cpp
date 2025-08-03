#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &animal);
		WrongAnimal& operator=(const WrongAnimal &other);
			~WrongAnimal();
		virtual void makeSound();
		std::string getType();
};

#endif