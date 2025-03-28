
#include "Cure.h"


Cure::Cure(void) : AMateria("cure") {
	std::cout << "Cure class. Default constructor called\n";
}

Cure::Cure(const Cure &cpy) {
	type = cpy.getType();
	//*this = cpy
    std::cout << "Cure Class. Copy constructor called\n";
}


Cure &Cure::operator=(const Cure &cpy) {

    if (this != &cpy)
        type = cpy.getType();
    std::cout << "Cure Class. Copy assignment operator called\n";
    return *this;

}

Cure::~Cure(void) {
    std::cout << "Cure Class. Destructor called\n";

}

//deep copy via copy constructor
AMateria * Cure::clone() const { //instead of returning base class pointer I could have returned Cure * ptr
	std::cout << "Cure class. Clone() called\n";
	Cure *ptr = new Cure(*this); //could new Cure("cure") be enough?
	return ptr;

}


void Cure::use(ICharacter& target) {

	std::cout << "* heals " << target.getName() << "'s wound *" << std::endl;

}
