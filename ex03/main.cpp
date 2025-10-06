#include "Intern.h"

int main() {
    Intern intern;        // one intern is enough, but you can use two if you want
    AForm* form1;
    AForm* form2;

    form1 = intern.makeForm("coffee making", "Bob"); // invalid form
    form2 = intern.makeForm("presidential pardon", "Luke"); // valid form

    if (form1)
        std::cout << *form1 << std::endl;
    if (form2)
        std::cout << *form2 << std::endl;

    delete form1;
    delete form2;
}
