
#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

int main()
{
    //Correct 1
    try {
        Bureaucrat mikel("Mikel", 10);
        ShrubberyCreationForm shrub("tree");
        std::cout << shrub << std::endl;
        mikel.signForm(shrub);
        std::cout << "[IS_SIGNED]: " << shrub.getIsSigned() << std::endl;
        mikel.executeForm(shrub);
    } catch (std::exception &e){ 
        std::cerr << "Exception caugth: " << e.what() << std::endl;
    }

    std::cout << "\n--------------------\n";

    //Correct 2
    // try {
    //     Bureaucrat mikel("Mikel", 10);
    //     RobotomyRequestForm robo("roboto");
    //     std::cout << robo << std::endl;
    //     mikel.signForm(robo);
    //     std::cout << "[IS_SIGNED]: " << robo.getIsSigned() << std::endl;
    //     std::cout << "--------------------\n";
    //     mikel.executeForm(robo);
    // } catch (std::exception &e){ 
    //     std::cerr << "Exception caugth: " << e.what() << std::endl;
    // }

    // std::cout << "\n--------------------\n";

    //Correct 3
    // try {
    //     Bureaucrat mikel("Mikel", 1);
    //     PresidentialPardonForm presi;
    //     std::cout << robo << std::endl;
    //     mikel.signForm(robo);
    //     std::cout << "[IS_SIGNED]: " << robo.getIsSigned() << std::endl;
    //     std::cout << "--------------------\n";
    //     mikel.executeForm(robo);
    // } catch (std::exception &e){ 
    //     std::cerr << "Exception caugth: " << e.what() << std::endl;
    // }

    // std::cout << "\n--------------------\n";

    //incorrect 1 - execute form before signing
    // try {
    //     Bureaucrat mikel("Mikel", 10);
    //     ShrubberyCreationForm shrub("tree");
    //     std::cout << shrub << std::endl;
    //     mikel.executeForm(shrub);
    // } catch (std::exception &e) {
    //     std::cerr << "Exception caugth: " << e.what() << std::endl;       
    // }
    // std::cout << "\n--------------------\n";

    //incorrect 2 -- presidential pardon, have permits to sign, not to execute
    // try {
    //     Bureaucrat mikel("Mikel", 10);
    //     PresidentialPardonForm presi;
    //     std::cout << presi << std::endl;
    //     mikel.signForm(presi);
    //     mikel.executeForm(presi);
    // } catch (std::exception &e) {
    //     std::cerr << "Exception caugth: " << e.what() << std::endl;
    // }
    //  std::cout << "\n--------------------\n";

    //incorrect 3 -- document already signed
    // try {
    //     Bureaucrat mikel("Mikel", 10);
    //     Bureaucrat b;
    //     RobotomyRequestForm robo;
    //     std::cout << robo << std::endl;
    //     mikel.signForm(robo);
    //     b.signForm(robo);
    //     mikel.executeForm(robo);
    // } catch (std::exception &e) {
    //     std::cerr << "Exception caugth: " << e.what() << std::endl;
    // }
   
    return 0;
}