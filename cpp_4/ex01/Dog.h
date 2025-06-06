#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.h"
#include "Brain.h"

class Dog : public Animal {

    private:
        Brain *brain;

    public:
        Dog(void);
        Dog(const Dog &cpy);
        Dog &operator=(const Dog &cpy);
        ~Dog(void);

        void makeSound() const;
        void setIdea(int index, const std::string &idea);
        std::string getIdea(int index) const;

};

#endif