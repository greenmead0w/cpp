
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.h"
#include <fstream>


class ShrubberyCreationForm : public AForm {

	private:
		std::string target;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &cpy);

		void executeAction(void) const;
		std::string getTarget(void) const;


};

#endif