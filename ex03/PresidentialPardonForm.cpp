#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm(const std::string tar)
    : AForm("PresidentialPardonForm", 25, 5), target(tar)
{

}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), target(other.target)
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		target = other.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	// std::cout << "Destructor PresidentialPardonForm called\n";
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << target << " has been pardoned by Zafod Beeblebrox\n";
}