#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat* b = new Bureaucrat("bro", 2);
	Form* form = new Form("Form", 20, 20);
	std::cout << *b << '\n';
	b->signForm(form);
	b->incrementGrade();
	std::cout << *b << '\n';
	b->decrementGrade();
	std::cout << *b << '\n';

	Bureaucrat *c = new Bureaucrat("ski", 150);
	Form* form1 = new Form("Form", 120, 520);
	c->signForm(form1);
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