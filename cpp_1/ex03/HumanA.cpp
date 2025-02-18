
#include "HumanA.hpp"
#include <iostream>

void HumanA::attack(void)
{
    std::cout << name << " attacks with their ";
    std::cout << weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon weapon)
{
    this->name = name;
    this->weapon = weapon;
}
