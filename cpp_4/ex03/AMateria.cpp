#include "AMateria.h"


AMateria::AMateria(void) : type("Default") {
	std::cout << "AMateria class. Default constructor called\n";
}

AMateria::AMateria(const AMateria &cpy) {
    std::cout << "AMateria Class. Copy constructor called\n";
}

AMateria::AMateria(std::string const & type) : type(type) {
	std::cout << "AMateria Class. Parametrized constructor called\n";

}

AMateria &AMateria::operator=(const AMateria &cpy) {

    if (this != &cpy)
        type = cpy.getType();
    std::cout << "AMateria Class. Copy assignment operator called\n";
    return *this;

}

AMateria::~AMateria(void) {
    std::cout << "AMateria Class. Destructor called\n";

}

std::string const & getType() const {
	return type;
}

virtual void use(ICharacter& target) {

std::cout << "AMateria use() -- DEFAULT\n";
//TO BE DONE ?

}