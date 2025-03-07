/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:24:54 by mzuloaga          #+#    #+#             */
/*   Updated: 2025/03/07 09:25:10 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.h"

int main(void)
{
    ClapTrap robot("CPP-03");

    robot.attack("Enemy Bot");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(10);
    robot.attack("Another Bot");
    robot.beRepaired(5);

    return 0;
}