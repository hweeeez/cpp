#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{	
	private:
		Brain *brain;
	public:
		Cat();
		Cat(const Cat &cat);
		Cat& operator=(const Cat &other);
		~Cat();
		void makeSound();
		std::string getType();
		void setIdea(int index, std::string idea);
		std::string getIdea(int index) const;
};

#endif