#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "Aform.h"

class ShrubberyCreationForm : public AForm
{
	private:
		virtual void executeAction() const;
		std::string target;


	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string);
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
		virtual ~ShrubberyCreationForm();

		class FileError: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

#endif