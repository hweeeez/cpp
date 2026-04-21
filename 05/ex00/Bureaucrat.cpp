#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("joe"), grade(0)
{
	std::cout << "Default Constructor" << '\n';
}

Bureaucrat::Bureaucrat(const std::string _name, const unsigned int _grade) : name(_name)
{
	//std::cout << "Parameterized Constructor" << '\n';
	//try
	//{
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
	//}
	// catch(const Bureaucrat::GradeTooLowException& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// catch(const Bureaucrat::GradeTooHighException& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
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

unsigned int Bureaucrat::getGrade() const
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
	//try
	//{
		if (grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			grade++;
	//}
	// catch(const Bureaucrat::GradeTooLowException& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
}

void Bureaucrat::incrementGrade()
{
	//try
	//{
		if (grade - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
		else
			grade--;
	//}
	// catch(const Bureaucrat::GradeTooHighException& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low");
}