#include "Form.hpp"

Form::Form() : name("wow"), is_signed(false), requiredSignGrade(20), requiredExecGrade(20)
{

}

Form::Form(std::string _name, int _requiredSignGrade, int _requiredExecGrade) : name(_name), is_signed(false), requiredSignGrade(_requiredSignGrade), requiredExecGrade(_requiredExecGrade)
{
	try
	{
		if (_requiredSignGrade > 150 || _requiredExecGrade > 150)
		{
			throw GradeTooLowException();
		}
		else if (_requiredSignGrade < 1 || _requiredExecGrade < 1)
		{
			throw GradeTooHighException();
		}
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

Form::Form(const Form &other) : requiredSignGrade(other.requiredSignGrade), requiredExecGrade(other.requiredExecGrade)
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

unsigned int Form::getRequiredExecGrade() const
{
	return requiredExecGrade;
}

unsigned int Form::getRequiredSignGrade() const
{
	return requiredSignGrade;
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
		if (bureaucrat.getGrade() <= getRequiredSignGrade())
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