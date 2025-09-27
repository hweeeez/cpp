#include "AForm.hpp"

AForm::AForm() : name("wow"), is_signed(false), grade(20)
{

}

AForm::AForm(const AForm &other) : grade(other.grade)
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

int AForm::getGrade() const
{
	return grade;
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getSigned() const
{
	return is_signed;
}

void AForm::beSigned(Bureaucrat bureaucrat)
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
	catch(const AForm::GradeTooLowException &e)
	{
		std::cerr << bureaucrat << " couldn't sign " << *this << " because " << e.what() << '\n';
	}
}

std::ostream& operator<<(std::ostream &out, const AForm& Form)
{
	out << Form.getName();
	return out;
}