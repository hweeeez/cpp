#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor" << '\n';
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy Constructor" << '\n';
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}
}

Brain& Brain::operator=(const Brain &other)
{
	std::cout << "Brain Copy Assignment Constructor" << '\n';
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor" << '\n';
}