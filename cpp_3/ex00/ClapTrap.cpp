/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:25:00 by mzuloaga          #+#    #+#             */
/*   Updated: 2025/03/07 09:25:12 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

ClapTrap::ClapTrap(void) : name("default"), hit_points(10), energy_points(10), damage(0) {
    std::cout << "Default constructor called\n";
}

ClapTrap::ClapTrap(const std::string &_name) : name(_name), hit_points(10), energy_points(10), damage(0) {
    std::cout << "Parametrized constructor called for " << name << '\n';
}

ClapTrap::ClapTrap(ClapTrap const &cpy) {
    std::cout << "Copy constructor called for " << name << '\n';
    *this = cpy;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "Destructor called for " << name << '\n';
}

ClapTrap &ClapTrap::operator=(ClapTrap const &cpy) {
    std::cout << "Copy assignment operator called for " << name << '\n';
    if (this != &cpy)
        this->hit_points = cpy.hit_points;
        this->energy_points = cpy.energy_points;
        this->name = cpy.name;
        this->damage = cpy.damage;
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
        std::cout << "ClapTrap " << name << " takes ";
        std::cout << amount << " points of damage and is destroyed\n"; 
        hit_points = 0; 
    }
    else if (hit_points > amount )
    {
        hit_points -= amount;
        std::cout << "ClapTrap " << name << " takes ";
        std::cout << amount << " points of damage. Hit points: " << hit_points << "\n";
    }
    else
        std::cout << "ClapTrap " << name << "is already destroyed\n";

    return;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energy_points > 0 && this->hit_points > 0)
    {
        energy_points--;
        hit_points += amount;
        std::cout << "ClapTrap " << name << " heals ";
        std::cout << amount << " hit points. Hit points: " << hit_points;
        std::cout << ". Energy points: " << energy_points << "\n";
    }
    else
        std::cout << "ClapTrap " << name << " has no energy or hit points left to be repaired\n";

    return;
}