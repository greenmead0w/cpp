/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:26:13 by mzuloaga          #+#    #+#             */
/*   Updated: 2025/03/07 09:26:24 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.h"

//call for default constructor in base class can be ommitted(?)
ScavTrap::ScavTrap(void) : ClapTrap(){
    std::cout << "ScavTrap. Default constructor called\n";

    // setName("default");
    setHitPoints(100);
    setEnergyPoints(50);
    setDamage(20);
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
    std::cout << "ScavTrap. Parametrized constructor called for " << name << '\n';

    // setName(name);
    setHitPoints(100);
    setEnergyPoints(50);
    setDamage(20);
}

ScavTrap &ScavTrap::operator=(const ScavTrap &cpy) {

    std::cout << "ScavTrap. Assignment operator called for " << getName() << '\n';
    if (this != &cpy)
    {
        setName(cpy.getName());
        setHitPoints(cpy.getHitPoints());
        setEnergyPoints(cpy.getEnergyPoints());
        setDamage(cpy.getDamage());
    }
    return *this;
}

ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy) {
    *this = cpy;
    std::cout << "ScavTrap. Copy constructor called for " << getName() << '\n';
}

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap. Destructor called for " << getName() << '\n';
}

void ScavTrap::attack(const std::string &target) {

    std::cout << "[ScavTrap " << getName() << "] ";
    ClapTrap::attack(target);

}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode\n";
}