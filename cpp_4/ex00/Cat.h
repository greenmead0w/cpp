
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.h"

class Cat : public Animal {
    public:
        Cat(void);
        Cat(const Cat &cpy);
        Cat &operator=(const Cat &cpy);
        ~Cat(void);

        void makeSound() const;


};

#endif