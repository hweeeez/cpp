#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Constructor" << '\n';
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

void PresidentialPardonForm::doAction() const
{
	std::cout << getTarget() + " has been pardoned by Zaphod Beeblebrox" << '\n';
}