/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:41:27 by mzuloaga          #+#    #+#             */
/*   Updated: 2025/02/15 09:33:13 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> //used for cin, cout
#include <iomanip> //used for setw
#include "Phonebook.hpp"


void ft_print_according_to_index(std::string &index_str, Phonebook &phonebook)
{
    std::istringstream iss;
    int index;

    iss.str(index_str);
    if (!(iss >> index))
    {
        std::cout << "Invalid input - not a number\n";
        return;
    }
    else
    {
        if (index >= 0 && index < phonebook.pb_size)
            phonebook.print_contact(index);
        else
        {
            std::cout << "Please enter a valid index between 0 and ";
            std::cout << phonebook.pb_size - 1 << std::endl;
        }
    }
}

std::string ft_truncate(const std::string &str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;

}

void ft_print_search_headers() 
{
    std::cout << std::setw(10) << ft_truncate("index") << "|";
    std::cout << std::setw(10) << ft_truncate("first name") << "|";
    std::cout << std::setw(10) << ft_truncate("last name") << "|";
    std::cout << std::setw(10) << ft_truncate("nickname\n");
}

bool ft_is_valid_PN(std::string pn)
{
    int i(0);
    int len;

    len = pn.length();
    if (len != 9)
        return false;
    while (i < pn.length())
    {
        if (!isdigit(pn[i]))
            return false;
        i++;
    }
    return true;
}