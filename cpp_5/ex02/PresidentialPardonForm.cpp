
#include "PresidentialPardonForm.h"

PresidentialPardonForm::PresidentialPardonForm(void)
	:	AForm("PresidentialPardonForm", 25, 5),
		target("Default")
{
	std::cout << "PresidentialPardonForm default constructor\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy)
	:	AForm("PresidentialPardonForm", 25, 5)
{
	this->target = cpy.target;
	std::cout << "PresidentialPardonForm copy constructor\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	:	AForm("PresidentialPardonForm", 25, 5),
		target(target)
{
	std::cout << "PresidentialPardonForm target param constructor\n";
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << "PresidentialPardonForm destructor called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy) {

    if (this != &cpy)
		this->target = cpy.target;

    return *this;
}

void PresidentialPardonForm::executeAction(void) const {

	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;

}
