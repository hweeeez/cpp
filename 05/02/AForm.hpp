#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string name;
		bool is_signed;
		const int requiredSignGrade;
		const int requiredExecGrade;
		std::string target;
	public:
		AForm();
		AForm(std::string _target, std::string _name, int _requiredSignGrade, int _requiredExecGrade);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		~AForm();
		std::string getName() const;
		bool getSigned() const;
		const int getRequiredSignGrade() const;
		const int getRequiredExecGrade() const;
		class GradeTooHighException : public std::exception
		{
			public:
			virtual	const char* what() const throw(){
					return "grade was too low";
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
			virtual	const char* what() const throw(){
					return "grade was too low";
				}
		};
		void beSigned(Bureaucrat bureaucrat);
		virtual bool execute(Bureaucrat const & executor) const;
		virtual void doAction() const = 0;
		std::string getTarget() const;
};

std::ostream& operator << (std::ostream& out, const AForm &form);

#endif