#ifndef AFORM_HPP
#define AFORM_HPP

//#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool is_signed;
		const int requiredSignGrade;
		const int requiredExecGrade;
		virtual void doAction() const = 0;
	public:
		AForm();
		AForm(std::string _name, int _requiredSignGrade, int _requiredExecGrade);
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		~AForm();
		std::string getName() const;
		bool getSigned() const;
		int getRequiredSignGrade()const;
		int getRequiredExecGrade() const;
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
		void beSigned(const Bureaucrat& bureaucrat);
		bool execute(Bureaucrat const & executor) const;
};

std::ostream& operator << (std::ostream& out, const AForm &form);

#include "Bureaucrat.hpp"

#endif