#include "Zombie.hpp"
#include <string>

void randomChump(std::string name)
{
    Zombie stack_zombie = Zombie(name);
    stack_zombie.announce();
    //destructor is called automatically when an object goes out
    //of scope
}