
#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    Zombie *heap_zombie;

    //heap example. zombie lives outside newZombie scope because allocated in heap
    std::cout << "Heap example:\n";
    heap_zombie = newZombie("Heap");
    heap_zombie->announce();
    delete heap_zombie;
    std::cout << "--------------------------\n";

    //stack example. zombie is dead outside randomChump
    std::cout << "Stack example:\n";
    randomChump("Stack");
    std::cout << "--------------------------\n";
    //TO BE DONE IF FEELING LIKE IT DESERVES:
    //example to see stack scope limitations
    /*
    Zombie stack_zombie;
    badRandomChump("badStack")
    stack_zombie.announce()
    */
    return 0;
}
