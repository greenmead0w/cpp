#include "Cat.h"

Cat::Cat(void) : AAnimal() {
    std::cout << "Cat class. Default constructor called\n";
    type = "I'm a cat";
    brain = new Brain(); //dynamic alloc of new Brain
}

Cat::Cat(const Cat &cpy) {
    type = cpy.type;
    brain = new Brain(*cpy.brain); //dynamic alloc of new Brain
    std::cout << "Cat Class. Copy constructor called\n";
}

Cat &Cat::operator=(const Cat &cpy) {

    if (this != &cpy)
    {
        type = cpy.type;
        delete brain; //!!
        brain = new Brain(*cpy.brain); //dynamic alloc of new Brain
        int i(-1);
        while (++i < 100)
            brain->setIdea(i, cpy.brain->getIdea(i));

    }

    std::cout << "Cat Class. Copy assignment operator called\n";
    return *this;

}

Cat::~Cat(void) {
    std::cout << "Cat Class. Destructor called\n";
    delete brain; //!!

}

void Cat::makeSound(void) const{
    std::cout << "MEOOOOW!\n";
}

void Cat::setIdea(int index, const std::string &idea) {
    brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const {
    return brain->getIdea(index);
}