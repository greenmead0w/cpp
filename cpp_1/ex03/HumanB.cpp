
#include "HumanB.hpp"
#include <iostream>

void HumanB::attack(void)
{
    std::cout << name << " attacks with their ";
    std::cout << weapon.getType() << std::endl;
}

HumanB::HumanB(std::string name)
{
    this->name = name;
}

void HumanB::setWeapon(Weapon weapon)
{
    this->weapon = weapon;
}