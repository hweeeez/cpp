#ifndef AFORM_HPP
#define AFORM_HPP

//#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <cstring>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int requiredSignGrade;
		const int requiredExecGrade;
		virtual void doAction() const = 0;
	public:
		Form();
		Form(std::string _name, int _requiredSignGrade, int _requiredExecGrade);
		Form(const Form &other);
		Form& operator=(const Form &other);
		virtual ~Form();
		std::string getName() const;
		bool getSigned() const;
		int getRequiredSignGrade()const;
		int getRequiredExecGrade() const;
		class GradeTooHighException : public std::exception
		{
			public:
			virtual	const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
			virtual	const char* what() const throw();
		};
		void beSigned(const Bureaucrat& bureaucrat);
		bool execute(Bureaucrat const & executor) const;
};

std::ostream& operator << (std::ostream& out, const Form &form);

#include "Bureaucrat.hpp"

#endif