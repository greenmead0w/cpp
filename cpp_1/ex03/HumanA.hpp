
#include "Weapon.hpp"

#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA
{
    Weapon weapon;
    std::string name;

    public:
        HumanA(std::string name, Weapon weapon);
        void attack();
};

#endif