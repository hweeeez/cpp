#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat* b = new Bureaucrat("bro", 2);

	std::cout << *b << '\n';
	b->incrementGrade();
	std::cout << *b << '\n';
	b->decrementGrade();
	std::cout << *b << '\n';

	Bureaucrat *c = new Bureaucrat("ski", 150);
	c->decrementGrade();
	std::cout << *c << '\n';

	Bureaucrat d;
	d = *b;
	std::cout << d << '\n';
	d.incrementGrade();
	std::cout << d << '\n';
	d.incrementGrade();
	std::cout << d << '\n';

	delete b;
	delete c;
}