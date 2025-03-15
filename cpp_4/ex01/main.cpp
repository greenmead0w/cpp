#include "Cat.h"
#include "Dog.h"
#include "WrongCat.h"


int main() 
{
    const WrongAnimal* meta = new WrongAnimal();
    std::cout << "-----------------\n";
    // const Animal* j = new Dog();
    // std::cout << "-----------------\n";
    const WrongAnimal* i = new WrongCat();
    std::cout << "-----------------\n";
    // std::cout << j->getType() << " " << std::endl; 
    std::cout << i->getType() << " " << std::endl; 
    i->makeSound(); 
    // j->makeSound();
    meta->makeSound();
    delete meta;
    std::cout << "-----------------\n";
    delete i;
    std::cout << "-----------------\n";
    // delete j;

    return 0; 
}

//EXAMPLE OF SHALLOW COPY
// Dog dog1;
// dog1.setIdea(0, "Fetch the ball!");

// // ❌ Shallow Copy (Only Copies the Pointer)
// Dog dog2 = dog1;  // dog2.brain now points to the SAME memory as dog1.brain

// dog2.setIdea(0, "Sleep all day");

// std::cout << dog1.getIdea(0) << std::endl;  
// // ❌ Output: "Sleep all day" (Modifying dog2 affects dog1!)

// delete dog1.brain;  
// // ❌ Now dog2.brain points to deleted memory (dangling pointer!)
