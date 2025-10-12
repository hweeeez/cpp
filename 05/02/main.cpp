#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat* b = new Bureaucrat("bro", 2);
	ShrubberyCreationForm* shrub = new ShrubberyCreationForm("home", "shrubbery", 145, 137);

	std::cout << *b << '\n';
	b->signForm(*shrub);
	b->incrementGrade();
	std::cout << *b << '\n';
	b->decrementGrade();
	std::cout << *b << '\n';
	shrub->execute(*b);
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