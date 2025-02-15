/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:39:07 by mzuloaga          #+#    #+#             */
/*   Updated: 2025/02/15 09:30:06 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "utils.hpp"
#include <iostream>
#include <iomanip>


//Alternative syntax using a member initializer list:
 //Phonebook() : pb_size(0), oldest(0) {}
Phonebook::Phonebook()
{
    pb_size = 0; oldest = 0;
}

int Phonebook::get_phonebook_length()
{
    return sizeof(contact_arr) / sizeof(contact_arr[0]);
}

void Phonebook::get_phonebook_list()
{
    int i(0);

    while (i < pb_size)
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << ft_truncate(contact_arr[i].get_first_name()) << "|";
        std::cout << std::setw(10) << ft_truncate(contact_arr[i].get_last_name()) << "|";
        std::cout << std::setw(10) << ft_truncate(contact_arr[i].get_nickname());
        std::cout << std::endl;
        i++;
    } 
}

void Phonebook:: print_contact(int index)
{
    std::cout << "First name: " << contact_arr[index].get_first_name() << std::endl;
    std::cout << "Last name: " << contact_arr[index].get_last_name() << std::endl;
    std::cout << "Nickname: " << contact_arr[index].get_nickname() << std::endl;
    std::cout << "Phone number: " << contact_arr[index].get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << contact_arr[index].get_darkest_secret() << std::endl;
}

//realized after coding that "this->" can be ommited in this case
void Phonebook::add_contact_to_phonebook(Contact &contact)
{
    if (this->pb_size < this->get_phonebook_length())
    {
        this->contact_arr[this->pb_size] = contact;
        this->pb_size++;
    }
    else
        this->contact_arr[this->oldest] = contact;
    this->oldest = (this->oldest + 1) % this->get_phonebook_length();
}
