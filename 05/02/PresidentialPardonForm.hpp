#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardenForm : public AForm
{
	private:

	public:
		PresidentialPardenForm();
		PresidentialPardenForm(std::string target);
		PresidentialPardenForm(const PresidentialPardenForm &other);
		PresidentialPardenForm& operator=(const PresidentialPardenForm &other);
		~PresidentialPardenForm();
};

#endif