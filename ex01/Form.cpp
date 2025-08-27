#include "Form.h"


Form::Form(const std::string& n, int sg, int eg): name(n), sign(sg), sgrade(sg), egrade(eg)
{
	std::cout << "Constructor called\n";
	if (sgrade < 1 || egrade < 1)
		throw GradeTooHighException();
	if (sgrade > 150 || egrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other): name(other.name), sign(other.sign), sgrade(other.sgrade), egrade(other.egrade)
{
	std::cout << "CopyConstructor called\n";
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
		this->sign = other.sign;
	return *this;
}

Form::~Form()
{
	std::cout << "Destructor called\n";
}

std::string Form::getName() const
{
	return name;
}

bool Form::getSign() const
{
	return sign;
}

int Form::getSgrade() const
{
	return sgrade;
}

int Form::getEgrade() const
{
	return egrade;
}


void Form::beSigned(const class Bureaucrat& b)
{
	if (b.getGrade() > sgrade)
		throw GradeTooLowException();
	sign = true;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

std::ostream& operator<<(std::ostream& out, Form const& f)
{
    out << "Form \"" << f.getName() 
        << "\", Sign status: " << (f.getSign() ? "signed" : "not signed")
        << ", Signing grade: " << f.getSgrade()
        << ", Execution grade: " << f.getEgrade();
    return out;
}