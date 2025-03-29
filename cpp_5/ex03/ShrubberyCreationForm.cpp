
#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:	AForm("ShrubberyCreationForm", 145, 137),
		target("Default")
{
	std::cout << "ShrubberyCreationForm default constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy)
	:	AForm("ShrubberyCreationForm", 145, 137)
{
	this->target = cpy.target;
	std::cout << "ShrubberyCreationForm copy constructor\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:	AForm("ShrubberyCreationForm", 145, 137),
		target(target)
{
	std::cout << "ShrubberyCreationForm target param constructor\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy) {

    if (this != &cpy)
		this->target = cpy.target;

    return *this;
}

void ShrubberyCreationForm::executeAction(void) const {

	try {
	    std::ofstream outfile((this->target + "_shrubbery").c_str()); //converting to const char * via c_str() because ofstream doesn't accept std::string as param	
		if (!outfile)
			throw std::string("Error: Could not create file " + this->target + "_shrubbery");
		
		outfile << "      /\\      \n";
		outfile << "     /\\*\\     \n";
		outfile << "    /\\O\\*\\    \n";
		outfile << "   /*/\\/\\/\\   \n";
		outfile << "  /\\O\\/\\*\\/\\  \n";
		outfile << " /\\*\\/\\*\\/\\/\\ \n";
		outfile << "/\\O\\/\\/*/\\/O/\\\n";
		outfile << "      ||      \n";
		outfile << "      ||      \n";
		outfile << "      ||      \n";

		outfile.close();

	} catch (const std::string& e){
		std::cerr << e << std::endl;
	}
    std::cout << "Shrubbery created at " << this->target << "_shrubbery\n";
	
}