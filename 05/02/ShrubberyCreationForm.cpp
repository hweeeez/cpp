#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target, std::string _name, int _requiredSignGrade, int _requiredExecGrade) : AForm(_target, _name, _requiredSignGrade, _requiredExecGrade)
{
	std::cout << "ShrubberyCreationForm Constructor" << '\n';
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	std::cout << "ShrubberyCreationForm Copy Constructor" << '\n';
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm Copy Assignment Constructor" << '\n';
	if (this != &other)
	{

	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor" << '\n';
}

void ShrubberyCreationForm::doAction() const
{
	std::string text;
   
   
    //while (std::getline(rfile, text))
	text = "       _-_";
	std::cout << text << '\n';
	text = "    /~~   ~~\\";
	std::cout << text << '\n';
	text = "  /~~       ~~\\";
	std::cout << text << '\n';
	text = " {             }";
	std::cout << text << '\n';
	text = " \\  _-     -_  /";
	std::cout << text << '\n';
	text = "    ~  \\ /  ~";
	std::cout << text << '\n';
	text = "_- -   | | _- _";
	std::cout << text << '\n';
	text = "  _ -  | |   -_";
	std::cout << text << '\n';
	text = "      //  \\";
	std::cout << text << '\n';
    //rfile.close();

}