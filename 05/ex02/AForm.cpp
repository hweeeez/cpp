#include "AForm.hpp"

AForm::AForm() : name(""), is_signed(false), requiredSignGrade(0), requiredExecGrade(0)
{

}

AForm::AForm(std::string _name, int _requiredSignGrade, int _requiredExecGrade) : name(_name), is_signed(false), requiredSignGrade(_requiredSignGrade), requiredExecGrade(_requiredExecGrade)
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
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << "Grade is too low." << e.what() << '\n';
	}
	catch(const AForm::GradeTooHighException &e)
	{
		std::cerr << "Grade is too high." << e.what() << '\n';
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
	try
	{
		if (bureaucrat.getGrade() <= getRequiredSignGrade())
		{
			std::cout << bureaucrat << " signed " << *this << " successfully."<< '\n';
			is_signed = true;
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
	if (is_signed && executor.getGrade() <= getRequiredExecGrade())
	{
		std::cout << "signed: " << is_signed << '\n';
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