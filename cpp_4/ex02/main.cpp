#include "Cat.h"
#include "Dog.h"

#define SIZE 6


//Compiler throws Abstract class error
int main() 
{
    AAnimal test;
    return 0;

}

// int main() 
// {
//     AAnimal *animals[SIZE];

//     for (int i = 0; i < SIZE/2; i++)
//     {
//         animals[i] = new Dog();
//         std::cout << "-----------------\n";
//     }

//     for (int i = 3; i < SIZE; i++)
//     {
//         animals[i] = new Cat();
//         std::cout << "-----------------\n";
//     }

//     std::cout << "ANIMALS HAVE BEEN CREATED\n";
//     std::cout << "-----------------\n";
//     /*
//     Animal class has no brain attribute, so compiler throws error when trying to do this:
//     animals[2]->setIdea(0, "idea")
//     what I have to do is downcast Animal * to Dog * ptr
//     */
//     static_cast<Dog*>(animals[2])->setIdea(0, "I want to catch a frisbee");
//     std::cout << static_cast<Dog*>(animals[2])->getIdea(0) << std::endl;

//     std::cout << static_cast<Cat*>(animals[3])->getIdea(50) << std::endl;

//     std::cout << "-----------------\n";

//     for (int i = 0; i < SIZE; i++)
//     {
//         delete animals[i];
//         std::cout << "-----------------\n";
//     }

//     return 0;

// }


// //deep copy vs shallow copy example
// int main() 
// {

//     Dog dog1;
//     Dog dog2;
//     Dog dog3;

//     dog1.setIdea(0, "im the FIRST dog");
//     dog2.setIdea(0, "im the SECOND dog");

//     std::cout << dog1.getIdea(0) << std::endl;
//     std::cout << "-----------------\n";
//     std::cout << dog2.getIdea(0) << std::endl;
//     std::cout << "-----------------\n";
//     std::cout << dog3.getIdea(0) << std::endl;
//     std::cout << "-----------------\n"; 

//     dog3 = dog2;

//     std::cout << "-----------------\n";
//     std::cout << dog3.getIdea(0) << std::endl;
//     std::cout << "-----------------\n";
//     dog2.setIdea(0, "Don't copy me!"); //if deep copy this does not modify dog3
//     std::cout << dog3.getIdea(0) << std::endl;
//     std::cout << "-----------------\n";

//     return 0; 
// }