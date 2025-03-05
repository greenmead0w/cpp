
#include "ScavTrap.h"

ScavTrap::ScavTrap(void) : ClapTrap(){
    std::cout << "ScavTrap. Default constructor called\n";
    setName("default");
    setHitPoints(100);
    setEnergyPoints(50);
    setDamage(20);
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "ScavTrap. Parametrized constructor called for " << name << '\n';

    setName(name);
    setHitPoints(100);
    setEnergyPoints(50);
    setDamage(20);
}

ScavTrap &ScavTrap::operator=(const ScavTrap &cpy) {

    std::cout << "ScavTrap. Assignment operator called for " << getName() << '\n';
    if (this != &cpy)
    {
        setName(getName());
        setHitPoints(getHitPoints());
        setEnergyPoints(getEnergyPoints());
        setDamage(getDamage());
    }
    return *this;
}

ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy) {
    *this = cpy;

    std::cout << "ScavTrap. Copy constructor called for " << getName() << '\n';
}

void ScavTrap::attack(const std::string &target) {

    std::cout << "ScavTrap child of parent ";
    ClapTrap::attack(target);

}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode\n";
}