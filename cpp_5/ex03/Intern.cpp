
#include "Intern.h"

Intern::Intern(void)
{
	std::cout << "Intern default constructor\n";
}

Intern::Intern(const Intern &cpy)
{
	(void)cpy; //no data members, so nothing to copy
	std::cout << "Intern copy constructor\n";
}

Intern::~Intern(void) {
    std::cout << "Intern destructor called\n";
}

Intern &Intern::operator=(const Intern &cpy) {
	(void)cpy; //no data members, so nothing to assign
    return *this;
}

AForm* Intern::createShrubberyForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

const char* Intern::MissingFormType::what() const throw() {
    return "No form type found";
}

AForm *Intern::makeForm(std::string form_type, std::string target) {
	
	std::string formTypeArr[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *form = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (form_type == formTypeArr[i])
		{
			switch(i) 
			{
                case 0: form = this->createShrubberyForm(target); break;
                case 1: form = this->createRobotomyForm(target); break;
                case 2: form = this->createPresidentialPardonForm(target); break;
            }
            std::cout << "Intern creates " << form_type << " form" << std::endl;
            return form;
		}
	}
	throw MissingFormType();

}