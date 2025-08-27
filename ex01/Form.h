#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include "Bureaucrat.h"

class Form
{
	private:
		const std::string name;
		bool sign;
		const int sgrade;
		const int egrade;


	public:
		Form(const std::string&, int, int);
		Form(const Form&);
		Form &operator=(const Form&);
		std::string getName() const;
		bool getSign() const;
		int getSgrade() const;
		int getEgrade() const;
		~Form();
	
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
		void beSigned(const class Bureaucrat&);
};

std::ostream &operator<<(std::ostream &, Form const &);

#endif