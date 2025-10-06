#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include <string>
#include "Bureaucrat.h"

class AForm
{
	private:
		const std::string name;
		bool sign;
		const int sgrade;
		const int egrade;

	protected:
		virtual void executeAction() const = 0;

	public:
		AForm(const std::string&, int, int);
		AForm(const AForm&);
		AForm &operator=(const AForm&);
		std::string getName() const;
		bool getSign() const;
		int getSgrade() const;
		int getEgrade() const;
		std::string getTarget() const;
		virtual ~AForm();
	
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		void beSigned(const class Bureaucrat&);
		void execute(Bureaucrat const& executor) const;
};

std::ostream &operator<<(std::ostream &, AForm const &);


#endif