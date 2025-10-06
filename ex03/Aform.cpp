#include "Aform.h"


AForm::AForm(const std::string& n, int sg, int eg): name(n), sign(false), sgrade(sg), egrade(eg)
{
	// std::cout << "Constructor called\n";
	if (sgrade < 1 || egrade < 1)
		throw GradeTooHighException();
	if (sgrade > 150 || egrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other): name(other.name), sign(other.sign), sgrade(other.sgrade), egrade(other.egrade)
{
	// std::cout << "CopyConstructor called\n";
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->sign = other.sign;
	return *this;
}

AForm::~AForm()
{
	// std::cout << "Destructor called\n";
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getSign() const
{
	return sign;
}

int AForm::getSgrade() const
{
	return sgrade;
}

int AForm::getEgrade() const
{
	return egrade;
}

std::string AForm::getTarget() const
{
	return "";
}


void AForm::beSigned(const class Bureaucrat& b)
{
	if (b.getGrade() > sgrade)
		throw GradeTooLowException();
	sign = true;
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return "Form is not Signed";
}



void AForm::execute(Bureaucrat const &executor) const
{
	if (!sign)
		throw FormNotSignedException();
	if (executor.getGrade() > egrade)
		throw GradeTooLowException();
	executeAction(); // calls the derived class implementation
}


std::ostream& operator<<(std::ostream& out, AForm const& f)
{
    out << "Form \"" << f.getName() 
        << "\", Sign status: " << (f.getSign() ? "signed" : "not signed")
        << ", Signing grade: " << f.getSgrade()
        << ", Execution grade: " << f.getEgrade();
    return out;
}

