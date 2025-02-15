/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:45:15 by mzuloaga          #+#    #+#             */
/*   Updated: 2025/02/15 09:22:35 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;
 public:
    Contact (); //providing a default constructor to not have issues when declaring an unitialized object
    Contact(std::string fn, std::string ln, std::string nick,
        std::string pn, std::string ds, int valid); 
    int valid; //if no data member is empty
    std::string get_first_name();
    std::string get_last_name();
    std::string get_nickname();
    std::string get_phone_number();
    std::string get_darkest_secret();

};

#endif 