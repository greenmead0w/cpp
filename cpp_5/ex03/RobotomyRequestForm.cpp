
#include "RobotomyRequestForm.h"

RobotomyRequestForm::RobotomyRequestForm(void)
	:	AForm("RobotomyRequestForm", 72, 45),
		target("Default")
{
	std::cout << "RobotomyRequestForm default constructor\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy)
	:	AForm("RobotomyRequestForm", 72, 45),
{
	this->target = cpy.target;
	std::cout << "RobotomyRequestForm copy constructor\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:	AForm("RobotomyRequestForm", 72, 45),
		target(target)
{
	std::cout << "RobotomyRequestForm target param constructor\n";
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << "RobotomyRequestForm destructor called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy) {

    if (this != &cpy)
        this->is_signed = cpy.is_signed;
		this->target = cpy.target;

    return *this;
}

void RobotomyRequestForm::executeAction(void) const {

	std::cout << "BRRRRRZZZZZZZZZZZT! VVVVRRRRRRRR! KRRRRKKKKKK!\n---------------------\n"
	if (std::srand() % 2 == 0)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy on " << target << " has failed" << std::endl;
	
}
