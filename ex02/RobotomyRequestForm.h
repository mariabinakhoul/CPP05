#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include "Aform.h"

class RobotomyRequestForm
{
	private:
		std::string target;

	protected:
		virtual void executeAction() const;

	public:
		RobotomyRequestForm(const std::string);
		RobotomyRequestForm(const RobotomyRequestForm &);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &);
		virtual ~RobotomyRequestForm();

};

#endif