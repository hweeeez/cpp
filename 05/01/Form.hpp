#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool is_signed;
		const int grade;
	public:
		Form();
		Form(const Form &other);
		Form& operator=(const Form &other);
		~Form();
		std::string getName() const;
		bool getSigned() const;
		int getGrade() const;
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

#endif