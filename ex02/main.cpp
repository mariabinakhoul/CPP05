#include "Bureaucrat.h"
#include "Aform.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <iostream>

int main()
{
	ShrubberyCreationForm Robo_form("I am a robo form");
	Bureaucrat Mr_Robo("Mr_Robo", 45);

	Mr_Robo.executeForm(Robo_form);
	Mr_Robo.signForm(Robo_form);
	Mr_Robo.executeForm(Robo_form);
	Mr_Robo.executeForm(Robo_form);
	Mr_Robo.executeForm(Robo_form);
}

