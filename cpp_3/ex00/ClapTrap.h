

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap {
    private:
        std::string name;
        unsigned int hit_points;
        unsigned int energy_points;
        unsigned int damage;
        
    public:
        ClapTrap(const std::string &_name);
        ClapTrap(ClapTrap const &cpy);
        ~ClapTrap(void);
        ClapTrap &operator=(ClapTrap const &cpy);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif