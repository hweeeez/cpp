#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	std::cout << "Destructor" << '\n';
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
	//try
	{
		if (grade - 1 < 1)
			throw GradeTooHighException();
		else
			grade--;
	}
	// catch(const Bureaucrat::GradeTooLowException& e)
	// {
	// 	std::cerr << "Grade Too Low" << '\n';
	// }
}

void Bureaucrat::signForm(Form *form) const
{
	form->beSigned(*this);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low");
}