#include "AForm.hpp"

AForm::AForm() : name(""), is_signed(false), requiredSignGrade(0), requiredExecGrade(0)
{

}

AForm::AForm(std::string _name, int _requiredSignGrade, int _requiredExecGrade) : name(_name), is_signed(false), requiredSignGrade(_requiredSignGrade), requiredExecGrade(_requiredExecGrade)
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

AForm::AForm(const AForm &other) : requiredSignGrade(other.requiredSignGrade), requiredExecGrade(other.requiredExecGrade)
{
	is_signed = other.is_signed;
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		is_signed = other.is_signed;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor" << '\n';
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getSigned() const
{
	return is_signed;
}

int AForm::getRequiredExecGrade() const
{
	return requiredExecGrade;
}

int AForm::getRequiredSignGrade() const
{
	return requiredSignGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= getRequiredSignGrade())
	{
		is_signed = true;
	}
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (is_signed && executor.getGrade() <= getRequiredExecGrade())
	{
		doAction();
	}
	else if (!is_signed)
		throw FormNotSigned();
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream &out, const AForm& AForm)
{
	out << AForm.getName();
	return out;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade Too High");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade Too Low");
}

const char *AForm::FormNotSigned::what(void) const throw()
{
	return ("Form is not signed");
}

const char *AForm::FormDoesNotExistException::what(void) const throw()
{
	return ("Form does not exist!");
}