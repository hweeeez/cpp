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
	std::string filename = (target + std::string("_shrubbery"));
	std::ofstream file(filename.c_str());
   
	text = "       _-_";
	file << text << '\n';
	text = "    /~~   ~~\\";
	file << text << '\n';
	text = "  /~~       ~~\\";
	file << text << '\n';
	text = " {             }";
	file << text << '\n';
	text = " \\  _-     -_  /";
	file << text << '\n';
	text = "    ~  \\ /  ~";
	file << text << '\n';
	text = "_- -   | | _- _";
	file << text << '\n';
	text = "  _ -  | |   -_";
	file << text << '\n';
	text = "      //  \\";
	file << text << '\n';
    file.close();
}