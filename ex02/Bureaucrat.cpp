#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : Name("Random Bureaucrat"), Grade(42) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade): Name(name), Grade(grade)
{
	std::cout << "Default Constructor called\n";
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): Name(other.Name), Grade(other.Grade)
{
	std::cout << "Copy constructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->Grade = other.Grade;
	return *this;
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "Destructor was called\n";
}

std::string Bureaucrat::getName() const
{
	return Name;
}

int Bureaucrat::getGrade() const
{
	return Grade;
}

void Bureaucrat::incrementGrade()
{
	if (Grade <= 1)
		throw GradeTooHighException();
	--Grade;
}

void Bureaucrat::decrementGrade()
{
	if (Grade >= 150)
		throw GradeTooLowException();
	++Grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << Name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e) {std::cerr << this->getName() << " could not sign " << form.getName() << ": " << e.what() << std::endl;}
}

void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << Name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}


std::ostream &operator<<(std::ostream &out, Bureaucrat const &a)
{
	out << a.getName() << ", bureuacrat grade " << a.getGrade();
	return out;
}
