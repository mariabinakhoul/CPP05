#include "ShrubberyCreationForm.h"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), target("Shrubbery Target")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137), target(target){}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

const char *ShrubberyCreationForm::FileError::what() const throw()
{
	return ("File could not be opened.");
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file;
	file.open((target + "_shrubbery").c_str());
	if (!file.is_open())
		throw FileError();
	file.close();
}