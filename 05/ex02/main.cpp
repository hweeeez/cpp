#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat* b = NULL;
	Bureaucrat* c = NULL;
	PresidentialPardonForm* p = NULL;
	ShrubberyCreationForm* shrub = NULL;
	RobotomyRequestForm* r = NULL;
	try
	{
		b = new Bureaucrat("bob", 55);
		shrub = new ShrubberyCreationForm("home");

		b->signForm(*shrub);
		shrub->execute(*b);

		p = new PresidentialPardonForm("Boi");
		b->signForm(*p);
		b->executeForm(*p);

		delete b;
		delete p;
		delete shrub;
	}
	catch (const std::exception &e)
	{
		delete p;
		delete b;
		delete shrub;
		std::cout << e.what() << '\n';	
	}
	std::cout << '\n';
	try
	{
		b = new Bureaucrat("wee", 3);
		c = new Bureaucrat("woo", 1);
		r = new RobotomyRequestForm("bobbo");
		b->signForm(*r);
		r->execute(*b);

		c->signForm(*r);
		r->execute(*c);
		delete r;
		delete b;
		delete c;
	}
	catch (const std::exception &e)
	{
		delete r;
		delete b;
		delete c;
		std::cout << e.what() << '\n';
	}
}