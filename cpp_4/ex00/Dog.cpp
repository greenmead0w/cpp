#include "Dog.h"

Dog::Dog(void) : Animal() {
    std::cout << "Dog class. Default constructor called\n";
    type = "I'm a dog";
}

Dog::Dog(const Dog &cpy) {
    type = cpy.type;
    std::cout << "Dog Class. Copy constructor called\n";
}

Dog &Dog::operator=(const Dog &cpy) {

    if (this != &cpy)
        type = cpy.type;

    std::cout << "Dog Class. Copy assignment operator called\n";
    return *this;

}

Dog::~Dog(void) {
    std::cout << "Dog Class. Destructor called\n";

}

void Dog::makeSound(void) const{
    std::cout << "WOOF WOOF!\n";
}