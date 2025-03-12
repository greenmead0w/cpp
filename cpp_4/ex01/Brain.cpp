#include "Brain.h"

/*
I could have the constructor only display the cout message and
std::string ideas would be automatically inited by the string Class 
constructor to empty strings. 

This doesn't happen with primitive types like int, char, etc.

Anyways decided to init every string with value "default"
*/
Brain::Brain(void) {
    
    std::cout << "Brain default constructor called\n";
    
    int i(-1);
    while (++i < 100)
        ideas[i] = "default";

}

Brain::Brain(const Brain &cpy) {
    //shallow copy, no pointers so no issues here
    *this = copy;
    std::cout << "Brain copy constructor called\n";

}

Brain::~Brain(void) {
    std::cout << "Brain destructor called\n";

}

Brain &Brain::operator=(const Brain &cpy) {
    std::cout << "Brain copy assignment operator called\n";
    if (this != &cpy)
    {
        int i(-1);
        while(++i < 100)
            ideas[i] = cpy.ideas[i];
    }

    return *this //returning a reference and not a mem address
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}

void Brain::setIdea(int index, const std::string &idea) {
    if (index >= 0 && index < 100)
        ideas[index] = idea;

}