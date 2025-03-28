
#include "Bureaucrat.h"

int main()
{
    //correct 1
    try {
        Bureaucrat mikel("Mikel", 10);
        std::cout << mikel << std::endl;
        Form form_1;
        std::cout << form_1 << std::endl;
        mikel.signForm(form_1);
        std::cout << "[IS_SIGNED]: " << form_1.getIsSigned() << std::endl;
    } catch (std::exception &e){ //as exception is polymorphic compiler knows it needs to call derived class what function
        std::cerr << "Exception caugth: " << e.what() << std::endl;
    }

    std::cout << "\n--------------------\n";

    //correct 2
    try {
        Bureaucrat mikel("Mikel", 10);
        std::cout << mikel << std::endl;
        Form form_1("traffic fine", 100, 25);
        Form form_2(form_1);
        std::cout << form_2 << std::endl;
        Form form_3;
        form_3 = form_1;
        std::cout << form_3 << std::endl;
    } catch (std::exception &e){ 
        std::cerr << "Exception caugth: " << e.what() << std::endl;
    }

    std::cout << "\n--------------------\n";

    //incorrect 1: GradeTooLowException

    // Bureaucrat mikel("Mikel", 150);
    // Form form("launch-nuclear-weapon", 1, 1);
    // mikel.signForm(form);
    // std::cout << "is form signed? " << form.getIsSigned() << std::endl;
    // std::cout << "\n--------------------\n";

    //incorrect 2: AlreadySigned
    // Bureaucrat mikel("Mikel", 1);
    // Form form("launch-nuclear-weapon", 1, 1);
    // mikel.signForm(form);
    // std::cout << "is form signed? " << form.getIsSigned() << std::endl;
    // mikel.signForm(form);
    // std::cout << "\n--------------------\n";

    //incorrect 3: Wrong grade at object instantiation
    try {
        Bureaucrat mikel("Mikel", 5);
        std::cout << mikel << std::endl;
        Form form_1("traffic fine", -100, 25);
        std::cout << form_1 << std::endl;
    } catch (std::exception &e){ 
        std::cerr << "Exception caugth: " << e.what() << std::endl;
    }
    std::cout << "\n--------------------\n";

   
    return 0;
}