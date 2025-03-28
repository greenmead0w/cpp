
#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

class Intern {

	private:
		AForm *createShrubberyForm(std::string target);
		AForm *createRobotomyRequestForm(std::string target);
		AForm *createPresidentialPardonForm(std::string target);

	public:
		Intern(void);
		Intern(const Intern &cpy);
		Intern(std::string target);
		~Intern(void);
		Intern &operator=(const Intern &cpy);

		AForm *makeForm(std::string form_type, std::string target);

		class MissingFormType : public std::exception {
			public:
				const char* what() const throw();
		}
	

};

#endif