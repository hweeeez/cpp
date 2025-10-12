#include "AForm.hpp"

AForm::AForm(std::string _target, std::string _name, int _requiredSignGrade, int _requiredExecGrade) : name(_name), is_signed(false), requiredSignGrade(_requiredSignGrade), target(_target), requiredExecGrade(_requiredExecGrade)
{

}

AForm::AForm(const AForm &other) : requiredExecGrade(other.requiredExecGrade), requiredSignGrade(other.requiredSignGrade)
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
	std::cout << "Destructor" << '\n';
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getSigned() const
{
	return is_signed;
}

std::string AForm::getTarget() const
{
	return target;
}

const int AForm::getRequiredExecGrade() const
{
	return requiredExecGrade;
}

const int AForm::getRequiredSignGrade() const
{
	return requiredSignGrade;
}

void AForm::beSigned(Bureaucrat bureaucrat)
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
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << bureaucrat << " couldn't sign " << *this << " because " << e.what() << '\n';
	}
}

void AForm::doAction() const
{

}

bool AForm::execute(Bureaucrat const & executor) const
{
	if (is_signed && executor.getGrade() >= getRequiredExecGrade())
	{
		doAction();
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream &out, const AForm& Form)
{
	out << Form.getName();
	return out;
}