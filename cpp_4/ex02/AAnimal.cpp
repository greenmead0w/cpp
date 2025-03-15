#include "AAnimal.h"

AAnimal::AAnimal(void) : type("I'm a default AAnimal") {
    std::cout << "AAnimal class. Default constructor called\n";
}

AAnimal::AAnimal(const AAnimal &cpy) {
    type = cpy.type;
    std::cout << "AAnimal Class. Copy constructor called\n";
}

AAnimal &AAnimal::operator=(const AAnimal &cpy) {

    if (this != &cpy)
        type = cpy.type;

    std::cout << "AAnimal Class. Copy assignment operator called\n";
    return *this;

}

AAnimal::~AAnimal(void) {
    std::cout << "AAnimal Class. Destructor called\n";

}

std::string AAnimal::getType(void) const{
    return type;
}

void AAnimal::makeSound(void) const {
    std::cout << "*DEFAULT AAnimal SOUND*\n";
}