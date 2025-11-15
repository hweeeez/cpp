#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	AForm*	rrf;
	Bureaucrat* b = new Bureaucrat("bro", 3);

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	b->signForm(*rrf);
	rrf->execute(*b);
	rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
	b->signForm(*rrf);
	rrf->execute(*b);
	rrf = someRandomIntern.makeForm("presidential pardon", "Home");
	b->signForm(*rrf);
	rrf->execute(*b);
	b = new Bureaucrat("bro", 135);
	b->signForm(*rrf);
	rrf->execute(*b);
}