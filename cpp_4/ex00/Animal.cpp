#include "Animal.h"

Animal::Animal(void) : type("I'm a default animal") {
    std::cout << "Animal class. Default constructor called\n";
}

Animal::Animal(const Animal &cpy) {
    type = cpy.type;
    std::cout << "Animal Class. Copy constructor called\n";
}

Animal &Animal::operator=(const Animal &cpy) {

    if (this != &cpy)
        type = cpy.type;

    std::cout << "Animal Class. Copy assignment operator called\n";
    return *this;

}

Animal::~Animal(void) {
    std::cout << "Animal Class. Destructor called\n";

}

std::string Animal::getType(void) const{
    return type;
}

void Animal::makeSound(void) const {
    std::cout << "*DEFAULT ANIMAL SOUND*\n";
}