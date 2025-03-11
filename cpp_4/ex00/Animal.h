
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {

    protected:
        std::string type;

    public:
        Animal(void);
        Animal(const Animal &cpy);
        Animal &operator=(const Animal &cpy);
        virtual ~Animal(void);

        std::string getType(void) const;
        virtual void makeSound() const;


};

#endif