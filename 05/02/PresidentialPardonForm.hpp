#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string _target, std::string _name, int _requiredSignGrade, int _requiredExecGrade);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();
		void doAction() const;
};

#endif