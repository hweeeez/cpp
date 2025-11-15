#include "RobotomyRequestForm.hpp"
#include <stdlib.h> 
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Constructor" << '\n';
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	std::cout << "RobotomyRequestForm Copy Constructor" << '\n';
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("RobotomyRequestForm", 25, 5), target(_target)
{

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

std::string RobotomyRequestForm::getTarget() const
{
	return target;
}

void RobotomyRequestForm::doAction() const
{
	std::cout << "vvvvvvrrrrrrrrrrrrrrrrrrrrr" << '\n';
	std::srand(std::time(0));
	int rng = std::rand() % 2;
	if (rng == 0)
	{
		std::cout << "Robotomizaton Failed." << '\n';
	}
	else
	{
		std::cout << getTarget() + " has been robotomized." << '\n';
	}
}