

#include "FragTrap.h"

FragTrap::FragTrap(void) : ClapTrap(){
    std::cout << "FragTrap. Default constructor called\n";

    setHitPoints(100);
    setEnergyPoints(100);
    setDamage(30);
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "FragTrap. Parametrized constructor called for " << name << '\n';

    setHitPoints(100);
    setEnergyPoints(100);
    setDamage(30);
}

FragTrap &FragTrap::operator=(const FragTrap &cpy) {

    std::cout << "FragTrap. Assignment operator called for " << getName() << '\n';
    if (this != &cpy)
    {
        setName(cpy.getName());
        setHitPoints(cpy.getHitPoints());
        setEnergyPoints(cpy.getEnergyPoints());
        setDamage(cpy.getDamage());
    }
    return *this;
}

FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap(cpy) {
    *this = cpy;
    std::cout << "FragTrap. Copy constructor called for " << getName() << '\n';
}

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap. Destructor called for " << getName() << '\n';
}


void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << getName() << " raises its hand for a high five! \n";
}