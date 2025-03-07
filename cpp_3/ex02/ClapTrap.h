/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 09:26:00 by mzuloaga          #+#    #+#             */
/*   Updated: 2025/03/07 09:32:05 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap {
    protected:
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

        //setters
        void setName(std::string newName);
        void setHitPoints(unsigned int hp);
        void setEnergyPoints(unsigned int ep);
        void setDamage(unsigned int damage);
        
        //getters
        std::string getName(void) const;
        unsigned int getHitPoints(void) const;
        unsigned int getEnergyPoints(void) const;
        unsigned int getDamage(void) const; 
        
};

#endif