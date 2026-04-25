#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Form*	rrf = NULL;
	Bureaucrat* b = NULL;
	try
	{
		Intern someRandomIntern;
		b = new Bureaucrat("bro", 3);

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		b->signForm(*rrf);
		rrf->execute(*b);
		delete rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
		b->signForm(*rrf);
		rrf->execute(*b);
		delete rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Home");
		b->signForm(*rrf);
		rrf->execute(*b);

		delete b;
		b = new Bureaucrat("bro", 135);
		b->signForm(*rrf);
		rrf->execute(*b);

		delete b;
		delete rrf;
	}
	catch (const std::exception &e)
	{
		delete b;
		delete rrf;
		std::cout << e.what() << '\n';
	}
}