#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const unsigned int requiredSignGrade;
		const unsigned int requiredExecGrade;
	public:
		Form();
		Form(std::string _name, int _requiredExecGrade, int _requiredSignGrade);
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();
		std::string getName() const;
		bool getSigned() const;
		unsigned int getRequiredSignGrade() const;
		unsigned int getRequiredExecGrade() const;
		class GradeTooHighException : public std::exception
		{
			public:
			virtual	const char* what() const throw(){
					return "grade was too high";
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
};

std::ostream& operator << (std::ostream& out, const Form &form);

#include "Bureaucrat.hpp"

#endif