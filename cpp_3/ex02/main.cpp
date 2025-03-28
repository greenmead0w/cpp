/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:26:08 by mzuloaga          #+#    #+#             */
/*   Updated: 2025/03/07 09:26:20 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.h"
#include "FragTrap.h"

int main(void)
{
    ClapTrap og("I'M OG");
    std::cout << "----------------\n";
    ScavTrap roomba;
    std::cout << "----------------\n";
    FragTrap ultron;
    std::cout << "-----------------\n";
    FragTrap walle(ultron);
    std::cout << "-----------------\n";
    FragTrap r2d2("r2d2");
    std::cout << "-----------------\n";
    std::cout << "ScavTrap: " << r2d2.getName() << ": ";
    std::cout << r2d2.getHitPoints() << " | " << r2d2.getEnergyPoints() << " | ";
    std::cout << r2d2.getDamage() << std::endl;
    std::cout << "--------------------\n";
    std::cout << roomba.getName() << ": ";
    std::cout << roomba.getHitPoints() << " | " << roomba.getEnergyPoints() << " | ";
    std::cout << roomba.getDamage() << std::endl;
    std::cout << "--------------------\n";
    std::cout << og.getName() << ": ";
    std::cout << og.getHitPoints() << " | " << og.getEnergyPoints() << " | ";
    std::cout << og.getDamage() << std::endl;
    std::cout << "--------------------\n";
    og.attack("ONE");
    roomba.attack("TWO");
    ultron.attack("THREE");
    std::cout << "--------------------\n";
    //og.guardGate(); //no member named like this
    roomba.guardGate();
    ultron.highFivesGuys();
    std::cout << "--------------------\n";

    return 0;
}