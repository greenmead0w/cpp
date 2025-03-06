
#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap : public ClapTrap {
    
    public:
        ScavTrap(void);
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &cpy);
        ~ScavTrap(void);
        ScavTrap &operator=(const ScavTrap &cpy);
        void attack(const std::string &target);
        void guardGate();


};

#endif 

