#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include "Aform.h"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
		virtual void action() const;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string);
		RobotomyRequestForm(const RobotomyRequestForm &);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &);
		virtual ~RobotomyRequestForm();

};

#endif