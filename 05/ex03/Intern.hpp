#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
	private:
											Form* makeRobotomyForm(std::string target);
											Form* makeShrubberyForm(std::string target);
											Form* makePardonForm(std::string target);
	public:
		Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);
		~Intern();
		Form* makeForm(std::string formName, std::string formTarget);
};

#endif