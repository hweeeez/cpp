#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	AForm*	rrf = NULL;
	Bureaucrat* b = NULL;
	Intern someRandomIntern;
	try
	{
		b = new Bureaucrat("bro", 3);

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		b->signForm(*rrf);
		rrf->execute(*b);
		b->executeForm(*rrf);
		delete rrf;
		delete b;
	}
	catch (const std::exception &e)
	{
		delete b;
		delete rrf;
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
	try
	{
		b = new Bureaucrat("bro", 3);
		rrf = someRandomIntern.makeForm("shrubbery creation", "office");
		b->signForm(*rrf);
		b->executeForm(*rrf);
		delete rrf;
		delete b;
	}
	catch (const std::exception &e)
	{
		delete b;
		delete rrf;
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
	try
	{
		b = new Bureaucrat("bro", 3);
		rrf = someRandomIntern.makeForm("presidential pardon", "Upin");
		b->signForm(*rrf);
		rrf->execute(*b);
		delete rrf;
		delete b;
	}
	catch (const std::exception &e)
	{
		delete b;
		delete rrf;
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
	try
	{
		b = new Bureaucrat("bro", 135);
		rrf = someRandomIntern.makeForm("presidential pardon", "Ipin");
		b->signForm(*rrf);
		rrf->execute(*b);

		delete rrf;
		delete b;
	}
	catch (const std::exception &e)
	{
		delete b;
		delete rrf;
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
	try
	{
		rrf = someRandomIntern.makeForm("asdasdfdk", "wee");
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}
}