#include "Form.hpp"

Form::Form() : name(""), is_signed(false), requiredSignGrade(0), requiredExecGrade(0)
{

}

Form::Form(std::string _name, int _requiredSignGrade, int _requiredExecGrade) : name(_name), is_signed(false), requiredSignGrade(_requiredSignGrade), requiredExecGrade(_requiredExecGrade)
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
	std::cout << "Form Destructor" << '\n';
}

std::string Form::getName() const
{
	return name;
}

bool Form::getSigned() const
{
	return is_signed;
}

int Form::getRequiredExecGrade() const
{
	return requiredExecGrade;
}

int Form::getRequiredSignGrade() const
{
	return requiredSignGrade;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= getRequiredSignGrade())
	{
		std::cout << bureaucrat << " signed " << *this << " successfully."<< '\n';
		is_signed = true;
	}
	else
		throw GradeTooLowException();
}

void Form::doAction() const
{

}

bool Form::execute(Bureaucrat const & executor) const
{
	if (is_signed && executor.getGrade() <= getRequiredExecGrade())
	{
		std::cout << "signed: " << is_signed << '\n';
		doAction();
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream &out, const Form& Form)
{
	out << Form.getName();
	return out;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low");
}