#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target, std::string _name, int _requiredSignGrade, int _requiredExecGrade) : AForm(_target, _name, _requiredSignGrade, _requiredExecGrade)
{
	std::cout << "ShrubberyCreationForm Constructor" << '\n';
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : ShrubberyCreationForm(other)
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
   
    std::ofstream wfile;
    std::string wname = getTarget() + "_shrubbery";
    wname.append(".replace");
    wfile.open((const char*)(wname.c_str()));
	if (!wfile.is_open())
	{
		std::cout << "Bad file" << '\n';
		return;
	}
    //while (std::getline(rfile, text))
	text = "       _-_\n";
	wfile << text << '\n';
	text = "    /~~   ~~\\n";
	wfile << text << '\n';
	text = "  /~~         ~~\\n";
	wfile << text << '\n';
	text = "{               }\n";
	wfile << text << '\n';
	text = " \  _-     -_  /\n";
	wfile << text << '\n';
	text = "   ~  \\ //  ~\n";
	wfile << text << '\n';
	text = "_- -   | | _- _\n";
	wfile << text << '\n';
	text = "  _ -  | |   -_\n";
	wfile << text << '\n';
	text = "      // \\\n";
	wfile << text << '\n';

    //rfile.close();
    wfile.close();
}