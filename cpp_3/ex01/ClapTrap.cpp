#include "ClapTrap.h"

//setters
void ClapTrap::setName(std::string newName) {
    name = newName;
    return;
}

void ClapTrap::setHitPoints(unsigned int hp) {
    hit_points = hp;
    return;
}

void ClapTrap::setEnergyPoints(unsigned int ep) {
    energy_points = ep;
    return;
}

void ClapTrap::setDamage(unsigned int newDamage) {
    damage = newDamage;
    return;
}

//getters
std::string ClapTrap::getName(void) const {
    return name;
}

unsigned int ClapTrap::getHitPoints(void) const {
    return hit_points;
}

unsigned int ClapTrap::getEnergyPoints(void) const {
    return energy_points;
}

unsigned int ClapTrap::getDamage(void) const {
    return damage;
}

/*
************
****Ex00****
************
*/

ClapTrap::ClapTrap(void) : name("MY_NAME_IS_DEFAULT"), hit_points(10), energy_points(10), damage(0) {
    std::cout << "ClapTrap. Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string &_name) : name(_name), hit_points(10), energy_points(10), damage(0) {
    std::cout << "ClapTrap. Parametrized constructor called for " << name << '\n';
}

ClapTrap::ClapTrap(ClapTrap const &cpy) {
    *this = cpy;
    std::cout << "ClapTrap. Copy constructor called for " << name << '\n';
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap. Destructor called for " << name << '\n';
}

ClapTrap &ClapTrap::operator=(ClapTrap const &cpy) {
    if (this != &cpy)
        this->hit_points = cpy.hit_points;
        this->energy_points = cpy.energy_points;
        this->name = cpy.name;
        this->damage = cpy.damage;
    std::cout << "ClapTrap. Copy assignment operator called for " << name << '\n';

    return *this;
}

void ClapTrap::attack(const std::string &target) {

    if (this->energy_points > 0 && this->hit_points > 0)
    {
        this->energy_points -=1;
        std::cout << "ClapTrap " << name << " attacks " << target;
        std::cout << " causing " << damage << " points of damage. Energy points: ";
        std::cout << energy_points << "\n";
    }
    else
        std::cout << "ClapTrap " << name << " has no energy or hit points left to attack " << target << '\n';
    
    return;

}

//not checking energy_points, as subject not explicitly stating they are needed to call function
void ClapTrap::takeDamage(unsigned int amount) {

    if (amount >= hit_points) {
        std::cout << name << " takes ";
        std::cout << amount << " points of damage and is destroyed\n"; 
        hit_points = 0; 
    }
    else if (hit_points > amount )
    {
        hit_points -= amount;
        std::cout << name << " takes ";
        std::cout << amount << " points of damage. Hit points: " << hit_points << "\n";
    }
    else
        std::cout << name << "is already destroyed\n";

    return;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energy_points > 0 && this->hit_points > 0)
    {
        energy_points--;
        hit_points += amount;
        std::cout << name << " heals ";
        std::cout << amount << " hit points. Hit points: " << hit_points;
        std::cout << ". Energy points: " << energy_points << "\n";
    }
    else
        std::cout << name << " has no energy or hit points left to be repaired\n";

    return;
}