
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.h"
#include <cstdlib>

class RobotomyRequestForm : public AForm {

	private:
		std::string target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &cpy);

		void executeAction(void) const;
		std::string getTarget(void) const;


};

#endif