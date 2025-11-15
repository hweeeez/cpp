#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern& Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
	
	}
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor" << '\n';
}

AForm* Intern::makeShrubberyForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makePardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeRobotomyForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(std::string formname, std::string formtarget)
{
	AForm* (Intern::*FunctionArray[3])(std::string target) = { &Intern::makeRobotomyForm, &Intern::makeShrubberyForm, &Intern::makePardonForm};
    std::string nameArray[3] = { "robotomy request", "shrubbery creation", "presidential pardon"};	
    for (int i = 0; i < 4; ++i)
    {
        if (formname == nameArray[i])
            return (*this.*FunctionArray[i])(formtarget);
    }
	return NULL;
}