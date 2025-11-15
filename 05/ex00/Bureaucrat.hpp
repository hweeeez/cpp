#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		unsigned int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string _name, const unsigned int _grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();
		std::string getName() const;
		unsigned int getGrade() const;
		void incrementGrade();
		void decrementGrade();
	    class GradeTooHighException : public std::exception
		{

		};
		class GradeTooLowException: public std::exception
		{

		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif