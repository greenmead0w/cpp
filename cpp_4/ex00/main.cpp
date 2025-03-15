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


// int main() 
// {
//     const Animal* meta = new Animal();
//     std::cout << "-----------------\n";
//     const Animal* j = new Dog();
//     std::cout << "-----------------\n";
//     const Animal* i = new Cat();
//     std::cout << "-----------------\n";
//     std::cout << j->getType() << " " << std::endl; 
//     std::cout << i->getType() << " " << std::endl; 
//     i->makeSound(); //will output the cat sound! 
//     j->makeSound();
//     meta->makeSound();
//     delete meta;
//     std::cout << "-----------------\n";
//     delete i;
//     std::cout << "-----------------\n";
//     delete j;

//     return 0; 
// }