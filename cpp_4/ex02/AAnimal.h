
#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal { //abstract class

    protected:
        std::string type;

    public:
        AAnimal(void);
        AAnimal(const AAnimal &cpy);
        AAnimal &operator=(const AAnimal &cpy);
        virtual ~AAnimal(void);

        std::string getType(void) const;
        virtual void makeSound() const = 0; //pure virtual funct


};

#endif