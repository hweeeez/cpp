#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : AForm("ShrubberyCreationForm", 145, 137), target(_target)
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

std::string ShrubberyCreationForm::getTarget() const
{
	return target;
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