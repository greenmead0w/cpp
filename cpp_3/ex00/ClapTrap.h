/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:24:33 by mzuloaga          #+#    #+#             */
/*   Updated: 2025/03/07 09:24:38 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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
        ClapTrap(void);
        ClapTrap(const std::string &_name);
        ClapTrap(ClapTrap const &cpy);
        ~ClapTrap(void);
        ClapTrap &operator=(ClapTrap const &cpy);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif