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

Form* Intern::makeShrubberyForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

Form* Intern::makePardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

Form* Intern::makeRobotomyForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

Form* Intern::makeForm(std::string formname, std::string formtarget)
{
	Form* (Intern::*FunctionArray[3])(std::string target) = { &Intern::makeRobotomyForm, &Intern::makeShrubberyForm, &Intern::makePardonForm};
    std::string nameArray[3] = { "robotomy request", "shrubbery creation", "presidential pardon"};	
    for (int i = 0; i < 3; ++i)
    {
        if (formname == nameArray[i])
            return (*this.*FunctionArray[i])(formtarget);
    }
	return NULL;
}