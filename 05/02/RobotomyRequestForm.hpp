#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string _target, std::string _name, int _requiredSignGrade, int _requiredExecGrade);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
		void doAction() const;
};

#endif