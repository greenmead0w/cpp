/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:39:03 by mzuloaga          #+#    #+#             */
/*   Updated: 2025/02/15 09:29:43 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {
    Contact contact_arr[8];
 public:
    int oldest; //oldest contact index, to be replaced if pb_size == 8
    int pb_size; //counter for amount of contacts in phonebook
    int get_phonebook_length();
    Phonebook(); //constructor
    void get_phonebook_list();
    void print_contact(int index);
    void add_contact_to_phonebook(Contact &contact);
};

#endif