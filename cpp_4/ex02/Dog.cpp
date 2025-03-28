#include "Dog.h"

Dog::Dog(void) : AAnimal() {
    std::cout << "Dog class. Default constructor called\n";
    type = "I'm a dog";
    brain = new Brain(); //dynamic alloc of new Brain
}

Dog::Dog(const Dog &cpy) {
    type = cpy.type;
    brain = new Brain(*cpy.brain); //dynamic alloc of new Brain
    // *this = cpy; //TEST SHALLOW COPY
    std::cout << "Dog Class. Copy constructor called\n";
}

Dog &Dog::operator=(const Dog &cpy) {

    if (this != &cpy)
    {
        type = cpy.type;
        delete brain; //delete the previous version of brain_ptr for the operator calling object
        brain = new Brain(*cpy.brain); //dynamic alloc of new Brain
        int i(-1);
        while (++i < 100)
            brain->setIdea(i, cpy.brain->getIdea(i));

        // //TEST SHALLOW COPY
        // type = cpy.type;
        // brain = cpy.brain; //!!

    }

    std::cout << "Dog Class. Copy assignment operator called\n";
    return *this;

}

Dog::~Dog(void) {
    std::cout << "Dog Class. Destructor called\n";
    delete brain; //instead of explicitly calling destructor + delete, have the destructor call delete
}

void Dog::makeSound(void) const {
    std::cout << "WOOF WOOF!\n";
}

void Dog::setIdea(int index, const std::string &idea) {
    brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
    return brain->getIdea(index);
}