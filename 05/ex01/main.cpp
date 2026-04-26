#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat *c = NULL;
	Form* form1 = NULL;
	try
	{
		c = new Bureaucrat("ski", 150);
		form1 = new Form("Form", 120, 520);
		c->signForm(*form1);
		c->decrementGrade();
		std::cout << *c << '\n';

		delete c;
		delete form1;
	}
	catch(const std::exception& e)
	{
		delete c;
		delete form1;
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
	try
	{
		c = new Bureaucrat("ski", 150);
		form1 = new Form("Form", 120, 100);
		c->signForm(*form1);
		c->incrementGrade();
		std::cout << *c << '\n';

		delete c;
		delete form1;
	}
	catch(const std::exception& e)
	{
		delete c;
		delete form1;
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
	Bureaucrat* b = NULL;
	Form* form = NULL;
	try
	{
		b = new Bureaucrat("bro", 2);
		Bureaucrat e;
		e = *b;
		form = new Form("Form", 20, 20);
		std::cout << *b << '\n';
		b->signForm(*form);
		e.signForm(*form);
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
		delete form;
	}
	catch (const std::exception &e)
	{
		delete b;
		delete form;
		std::cout << e.what() << '\n';
	}
}