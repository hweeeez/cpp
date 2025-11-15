#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	private:
		AForm* makeRobotomyForm(std::string target);
		AForm* makeShrubberyForm(std::string target);
		AForm* makePardonForm(std::string target);
	public:
		Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);
		~Intern();
		AForm* makeForm(std::string formName, std::string formTarget);
};

#endif