
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

AForm* Intern::createRobotomyRqForm(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string form_type, std::string target) {
	
	std::string formTypeArr[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	//create array of pointers to functions that return new form objects
	AForm * funcPtrArr = {
		&Intern::createShrubberyForm,
        &Intern::createRobotomyForm,
        &Intern::createPresidentialPardonForm
	}

	for (int i = 0; i < 3; i++)
	{
		if (form_type == formTypeArr[i])
		{
			AForm *form = funcPtrArr[i]
			std::cout << "Intern creates " << name << " form" << std::endl;
			return form;
		}
	}
	throw MissingFormType();

}