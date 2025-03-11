#include "WrongCat.h"

WrongCat::WrongCat(void) : WrongAnimal() {
    std::cout << "WrongCat class. Default constructor called\n";
    type = "I'm a WrongCat";
}

WrongCat::WrongCat(const WrongCat &cpy) {
    type = cpy.type;
    std::cout << "WrongCat Class. Copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &cpy) {

    if (this != &cpy)
        type = cpy.type;

    std::cout << "WrongCat Class. Copy assignment operator called\n";
    return *this;

}

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat Class. Destructor called\n";

}

void WrongCat::makeSound(void) const{
    std::cout << "MEOOOOW!\n";
}