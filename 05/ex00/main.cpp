#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *c = NULL;
	try
	{
		c = new Bureaucrat("ski", 150);
		std::cout << *c << '\n';
		c->decrementGrade();
		std::cout << *c << '\n';

		delete c;
	}
	catch (const std::exception& e)
	{
		delete c;
		std::cout << e.what() << '\n';
	}
	Bureaucrat* b = NULL;
	try
	{
		b = new Bureaucrat("bro", 2);

		std::cout << *b << '\n';
		b->incrementGrade();
		std::cout << *b << '\n';
		b->decrementGrade();
		std::cout << *b << '\n';

		Bureaucrat d;
		d = *b;
		std::cout << d << '\n';
		d.incrementGrade();
		std::cout << d << '\n';
		d.incrementGrade();
		std::cout << d << '\n';

		delete b;
	}
	catch (const std::exception& e)
	{
		delete b;
		std::cout << e.what() << '\n';
	}

	try
	{
		Bureaucrat *e = new Bureaucrat("invalid", 156);
		std::cout << *e << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Bureaucrat *f = new Bureaucrat("invalid", 0);
		std::cout << *f << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}