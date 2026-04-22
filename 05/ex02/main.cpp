#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try
	{
		Bureaucrat* b = new Bureaucrat("bro", 3);
		ShrubberyCreationForm* shrub = new ShrubberyCreationForm("home");

		std::cout << *b << '\n';
		b->signForm(*shrub);
		shrub->execute(*b);

		PresidentialPardonForm* p = new PresidentialPardonForm("Big Boi");
		b->signForm(*p);
		p->execute(*b);

		RobotomyRequestForm* r = new RobotomyRequestForm("bobbo");
		b->signForm(*r);
		r->execute(*b);
		
		delete b;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';	
	}
}