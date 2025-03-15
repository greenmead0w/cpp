#include "Cat.h"

Cat::Cat(void) : Animal() {
    std::cout << "Cat class. Default constructor called\n";
    type = "I'm a cat";
}

Cat::Cat(const Cat &cpy) {
    type = cpy.type;
    std::cout << "Cat Class. Copy constructor called\n";
}

Cat &Cat::operator=(const Cat &cpy) {

    if (this != &cpy)
        type = cpy.type;

    std::cout << "Cat Class. Copy assignment operator called\n";
    return *this;

}

Cat::~Cat(void) {
    std::cout << "Cat Class. Destructor called\n";

}

void Cat::makeSound(void) const{
    std::cout << "MEOOOOW!\n";
}