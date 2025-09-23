#include "Form.hpp"

Form::Form() : name("wow"), is_signed(false), grade(20)
{

}

Form::Form(const Form &other) : grade(other.grade)
{
	is_signed = other.is_signed;
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		is_signed = other.is_signed;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Destructor" << '\n';
}

int Form::getGrade() const
{
	return grade;
}

std::string Form::getName() const
{
	return name;
}

bool Form::getSigned() const
{
	return is_signed;
}

void Form::beSigned(Bureaucrat bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() <= getGrade())
		{
			std::cout << bureaucrat << " signed " << *this << '\n';
		}
		else
			throw GradeTooLowException();
	}
	catch(const Form::GradeTooLowException &e)
	{
		std::cerr << bureaucrat << " couldn't sign " << *this << " because " << e.what() << '\n';
	}
}

std::ostream& operator<<(std::ostream &out, const Form& Form)
{
	out << Form.getName();
	return out;
}