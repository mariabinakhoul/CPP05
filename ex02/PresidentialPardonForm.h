#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "Aform.h"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;

	protected:
		virtual void executeAction() const;

	public:
		PresidentialPardonForm(const std::string);
		PresidentialPardonForm(const PresidentialPardonForm &);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &);
		virtual ~PresidentialPardonForm();

};

#endif