#include "Ice.h"


Ice::Ice(void) : AMateria("ice") {
	std::cout << "Ice class. Default constructor called\n";
}

Ice::Ice(const Ice &cpy) {
	type = cpy.getType();
	//*this = cpy
    std::cout << "Ice Class. Copy constructor called\n";
}


Ice &Ice::operator=(const Ice &cpy) {

    if (this != &cpy)
        type = cpy.getType();
    std::cout << "Ice Class. Copy assignment operator called\n";
    return *this;

}

Ice::~Ice(void) {
    std::cout << "Ice Class. Destructor called\n";

}

//deep copy via copy constructor
AMateria * Ice::clone() const { //instead of returning base class pointer I could have returned Ice * ptr
	std::cout << "Ice class. Clone() called\n";
	Ice *ptr = new Ice(*this); //could new Ice("Ice") be enough?
	return ptr;

}


void Ice::use(ICharacter& target) {

	std::cout << "* shoots an ice bolt " << target.getName() << " *" << std::endl;

}