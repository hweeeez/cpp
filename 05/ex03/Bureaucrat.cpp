#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("joe"), grade(1)
{
	std::cout << "Default Constructor" << '\n';
}

Bureaucrat::Bureaucrat(const std::string _name, const int _grade) : name(_name)
{
	std::cout << "Parameterized Constructor" << '\n';
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	std::cout << "Copy Constructor" << '\n';
	grade = other.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Copy Assignment Operator" << '\n';
	if (this != &other)
	{
		grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor" << '\n';
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& Bureaucrat)
{
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade(); 
	return out;
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	else
		grade++;
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::signForm(AForm & form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " couldn't sign " << form << " because " << e.what() << '\n';
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form << '\n';
	}
	catch (std::exception &e)
	{
		std::cout << this->name << " failed to execute " << form << " because " << e.what() << '\n';
	}
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low");
}