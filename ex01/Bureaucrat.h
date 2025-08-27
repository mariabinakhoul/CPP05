#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		const std::string Name;
		int Grade;

	public:
		Bureaucrat(const std::string&, int);
		Bureaucrat(const Bureaucrat&);
		Bureaucrat &operator=(const Bureaucrat&);
		~Bureaucrat();
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

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
};

std::ostream &operator<<(std::ostream &, Bureaucrat const &);


#endif