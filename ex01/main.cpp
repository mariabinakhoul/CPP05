#include "Bureaucrat.h"
#include "Form.h"

int main()
{
    try {
        Bureaucrat boss("Maria", 5);
        Bureaucrat intern("Intern", 140);

        Form contract("TopSecretContract", 10, 20);

        std::cout << boss << std::endl;
        std::cout << intern << std::endl;
        std::cout << contract << std::endl;

        // Intern tries to sign → should throw (grade too low)
        try {
            contract.beSigned(intern);
        } catch (std::exception& e) {
            std::cerr << intern.getName() << " couldn’t sign "
                      << contract.getName() << " because: " << e.what() << std::endl;
        }

        // Boss tries to sign → should succeed
        contract.beSigned(boss);

        std::cout << contract << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
