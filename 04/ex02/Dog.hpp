#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{	
	private:
		Brain *brain;
	public:
		Dog();
		Dog(const Dog &cat);
		Dog& operator=(const Dog &other);
		~Dog();
		void makeSound();
		std::string getType();
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif