
#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include "Intern.h"

int main()
{
    //Correct 1
    try {
        Intern mikel;
        Bureaucrat boss("Mr.", 10);
        AForm *shrub = mikel.makeForm("shrubbery creation", "yeahbabay");
        std::cout << *shrub << std::endl;
        boss.signForm(*shrub);
        std::cout << "[IS_SIGNED]: " << shrub->getIsSigned() << std::endl;
        boss.executeForm(*shrub);
        delete shrub; //!!
    } catch (std::exception &e){ 
        std::cerr << "Exception caugth: " << e.what() << std::endl;
    }

    std::cout << "\n--------------------\n";

    

    //incorrect 1 -- missing form type
    // try {
    //     Intern mikel;
    //     Bureaucrat boss("Mr.", 10);
    //     AForm *shrub = mikel.makeForm("shrubbery form", "yeahbabay");
    //     std::cout << *shrub << std::endl;
    //     boss.signForm(*shrub);
    //     std::cout << "[IS_SIGNED]: " << shrub->getIsSigned() << std::endl;
    //     boss.executeForm(*shrub);
    // } catch (std::exception &e){ 
    //     std::cerr << "Exception caugth: " << e.what() << std::endl;
    // }

    // std::cout << "\n--------------------\n";
   
    return 0;
}