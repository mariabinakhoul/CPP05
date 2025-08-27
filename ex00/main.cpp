#include "Bureaucrat.h"

int main()
{
	try {
		Bureaucrat b("Maria", 149);
		std::cout << b << std::endl;

		// b.incrementGrade();
		// b.incrementGrade();
		b.decrementGrade();
		std::cout << b << std::endl;
		b.decrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}