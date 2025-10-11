#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
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

void ShrubberyCreationForm::doAction()
{
	std::string text;
   
    std::ofstream wfile;
    std::string wname = getTarget() + "_shrubbery";
	std::ifstream rfile("treeart.txt");
	if (!rfile.good())
	{
		std::cout << "Bad file" << '\n';
		return;
	}
    //rfile.open(argv[1]);
    wname.append(".replace");
    wfile.open((const char*)(wname.c_str()));
	if (!wfile.is_open())
	{
		std::cout << "Bad file" << '\n';
		return;
	}
    while (std::getline(rfile, text))
    {

        wfile << text << '\n';
    }
    rfile.close();
    wfile.close();
}