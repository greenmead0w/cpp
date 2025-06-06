
#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.h"
#include "Brain.h"

class Cat : public AAnimal {

    private:
        Brain *brain;

    public:
        Cat(void);
        Cat(const Cat &cpy);
        Cat &operator=(const Cat &cpy);
        ~Cat(void);

        void makeSound() const;
        void setIdea(int index, const std::string &idea);
        std::string getIdea(int index) const;


};

#endif