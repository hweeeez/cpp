#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat Constructor" << '\n';
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &cat) : WrongAnimal(cat)
{
	std::cout << "WrongCat Copy Constructor" << '\n';
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat Copy Assignment Constructor" << '\n';
	WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor" << '\n';
}

void WrongCat::makeSound()
{
	std::cout << "meep meep meep meep" << '\n';
}