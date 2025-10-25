#include "RobotomyRequestForm.hpp"
#include <stdlib.h> 

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Constructor" << '\n';
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	std::cout << "RobotomyRequestForm Copy Constructor" << '\n';
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm Copy Assignment Constructor" << '\n';
	if (this != &other)
	{

	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor" << '\n';
}

void RobotomyRequestForm::doAction() const
{
	std::cout << "vvvvvvrrrrrrrrrrrrrrrrrrrrr" << '\n';
	int rng = rand() / RAND_MAX;
	if (rng == 0)
	{
		std::cout << "Robotomizaton Failed." << '\n';
	}
	else
	{
		std::cout << getTarget() + " has been robotomized." << '\n';
	}
}