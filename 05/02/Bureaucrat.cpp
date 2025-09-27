#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("joe"), grade(0)
{
	std::cout << "Default Constructor" << '\n';
}

Bureaucrat::Bureaucrat(const std::string _name, const int _grade) : name(_name)
{
	std::cout << "Parameterized Constructor" << '\n';
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
	try
	{
		if (grade + 1 > 150)
			throw GradeTooHighException();
		else
			grade++;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "Grade Too High" << '\n';
	}
	
}

void Bureaucrat::incrementGrade()
{
	try
	{
		if (grade - 1 < 1)
			throw GradeTooLowException();
		else
			grade--;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "Grade Too Low" << '\n';
	}
}

void Bureaucrat::signForm(AForm & form) const
{
	form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const & form) const
{
	std::cout << this->name << " executed " << form << '\n';
}