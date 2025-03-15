
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
    public:
        WrongCat(void);
        WrongCat(const WrongCat &cpy);
        WrongCat &operator=(const WrongCat &cpy);
        ~WrongCat(void);

        void makeSound() const;


};

#endif