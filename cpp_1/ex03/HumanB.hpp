
#include "Weapon.hpp"

#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB
{
    Weapon weapon;
    std::string name;

    public:
        HumanB(std::string name);
        void attack();
        void setWeapon(Weapon weapon);
};

#endif