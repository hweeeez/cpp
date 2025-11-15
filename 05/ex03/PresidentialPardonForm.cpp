#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Constructor" << '\n';
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardonForm", 74, 45), target(_target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	std::cout << "PresidentialPardonForm Copy Constructor" << '\n';
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm Copy Assignment Constructor" << '\n';
	if (this != &other)
	{

	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor" << '\n';
}

std::string PresidentialPardonForm::getTarget() const
{
	return target;
}

void PresidentialPardonForm::doAction() const
{
	std::cout << getTarget() + " has been pardoned by Zaphod Beeblebrox" << '\n';
}