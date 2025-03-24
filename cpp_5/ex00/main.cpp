
#include "Bureaucrat.h"

int main()
{
    //correct 1
    try {
        Bureaucrat def;
        std::cout << def << std::endl;
        def.incrementGrade();
        std::cout << def << std::endl;
    } catch (std::exception &e){ //as exception is polymorphic compiler knows it needs to call derived class what function
        std::cerr << "Exception caugth: " << e.what() << std::endl;
    }

    std::cout << "\n--------------------\n";

    //correct 2
    try {
        Bureaucrat mikel("Mikel", 1);
        std::cout << mikel << std::endl;
        mikel.decrementGrade();
        std::cout << mikel << std::endl;
    } catch (std::exception &e){ 
        std::cerr << "Exception caugth: " << e.what() << std::endl;
    }
    std::cout << "\n--------------------\n";

    //incorrect 1: GradeTooHighException
    try {
        Bureaucrat mikel("Mikel", 1);
        std::cout << mikel << std::endl;
        mikel.incrementGrade();
        std::cout << mikel << std::endl;
    } catch (std::exception &e){ 
        std::cerr << "Exception caugth: " << e.what() << std::endl;
    }
    std::cout << "\n--------------------\n";

    //incorrect 2: GradeTooLowException
    try {
        Bureaucrat mikel("Mikel", 150);
        std::cout << mikel << std::endl;
        mikel.decrementGrade();
        std::cout << mikel << std::endl;
    } catch (std::exception &e){ 
        std::cerr << "Exception caugth: " << e.what() << std::endl;
    }
    std::cout << "\n--------------------\n";

    //incorrect 3: Wrong grade at object instantiation
    try {
        Bureaucrat mikel("Mikel", 155);
        std::cout << mikel << std::endl;
        mikel.decrementGrade();
        std::cout << mikel << std::endl;
    } catch (std::exception &e){ 
        std::cerr << "Exception caugth: " << e.what() << std::endl;
    }
    std::cout << "\n--------------------\n";

   
    return 0;
}