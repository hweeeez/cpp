#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat* b = new Bureaucrat("bro", 3);
	ShrubberyCreationForm* shrub = new ShrubberyCreationForm("home", "shrubbery", 145, 137);

	std::cout << *b << '\n';
	b->signForm(*shrub);
	shrub->execute(*b);

	PresidentialPardonForm* p = new PresidentialPardonForm("Big Boi", "ass", 74, 45);
	b->signForm(*p);
	p->execute(*b);

	RobotomyRequestForm* r = new RobotomyRequestForm("bobbo", "bee", 25, 5);
	b->signForm(*r);
	r->execute(*b);
	// Bureaucrat *c = new Bureaucrat("ski", 150);
	// c->signForm();
	// c->decrementGrade();
	// std::cout << *c << '\n';

	// Bureaucrat d;
	// d = *b;
	// std::cout << d << '\n';
	// d.incrementGrade();
	// std::cout << d << '\n';
	// d.incrementGrade();
	// std::cout << d << '\n';

	//delete b;
	//delete c;
}