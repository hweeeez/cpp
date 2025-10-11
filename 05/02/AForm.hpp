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
		const int grade;
		const int requiredSignGrade;
		const int requiredExecGrade;
		std::string target;
	public:
		AForm();
		AForm(std::string target);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		~AForm();
		std::string getName() const;
		bool getSigned() const;
		int getGrade() const;
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
		virtual void execute(Bureaucrat const & executor);
		virtual void doAction() = 0;
		std::string getTarget() const;
};

std::ostream& operator << (std::ostream& out, const AForm &form);

#endif