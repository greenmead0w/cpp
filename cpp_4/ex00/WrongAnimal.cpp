#include "WrongAnimal.h"

WrongAnimal::WrongAnimal(void) : type("I'm a default WrongAnimal") {
    std::cout << "WrongAnimal class. Default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &cpy) {
    type = cpy.type;
    std::cout << "WrongAnimal Class. Copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &cpy) {

    if (this != &cpy)
        type = cpy.type;

    std::cout << "WrongAnimal Class. Copy assignment operator called\n";
    return *this;

}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal Class. Destructor called\n";

}

std::string WrongAnimal::getType(void) const{
    return type;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "*DEFAULT WrongAnimal SOUND*\n";
}