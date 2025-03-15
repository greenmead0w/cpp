#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.h"

class Dog : public Animal {

    public:
        Dog(void);
        Dog(const Dog &cpy);
        Dog &operator=(const Dog &cpy);
        ~Dog(void);
        void makeSound() const;

};

#endif