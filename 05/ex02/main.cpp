#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat* b = NULL;
	PresidentialPardonForm* p = NULL;
	ShrubberyCreationForm* shrub = NULL;
	RobotomyRequestForm* r = NULL;
	try
	{
		b = new Bureaucrat("bro", 3);
		shrub = new ShrubberyCreationForm("home");

		std::cout << *b << '\n';
		b->signForm(*shrub);
		shrub->execute(*b);

		p = new PresidentialPardonForm("Big Boi");
		b->signForm(*p);
		p->execute(*b);

		r = new RobotomyRequestForm("bobbo");
		b->signForm(*r);
		r->execute(*b);
		
		delete b;
		delete p;
		delete r;
		delete shrub;
	}
	catch (const std::exception &e)
	{
		delete p;
		delete r;
		delete b;
		delete shrub;
		std::cout << e.what() << '\n';	
	}
}