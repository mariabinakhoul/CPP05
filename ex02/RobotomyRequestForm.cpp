#include "RobotomyRequestForm.h"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request Form", 72, 45), target("Robotomy Target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request Form", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other) : AForm (other), target(other.target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}


void RobotomyRequestForm::action() const
{
	std::srand(std::time(0));
	int randomValue = std::rand() % 2;
	
	if (randomValue == 0)
	{
		std::cout << "BEEP BEEP BEEPPPPP BEEEEEP \n";
		std::cout << "Robotomy request approved Mr. "<< target << std::endl;
	}
	else
		std::cout << "Robotomy request denied \n";
}
