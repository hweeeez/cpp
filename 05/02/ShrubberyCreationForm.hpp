#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target, std::string name, int _requiredSignGrade, int _requiredExecGrade);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
		void doAction() const;
};

#endif