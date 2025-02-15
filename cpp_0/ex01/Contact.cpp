/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:47:15 by mzuloaga          #+#    #+#             */
/*   Updated: 2025/02/15 09:23:04 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact () {}; //default constructor

Contact::Contact(std::string fn, std::string ln, std::string nick,
	std::string pn, std::string ds, int valid) 
	{
		first_name = fn;
		last_name = ln;
		nickname = nick;
		phone_number = pn;
		darkest_secret = ds;
		this->valid = valid; //using "this->" here to diff member from param
	}

std::string Contact::get_first_name() {return first_name;};
std::string Contact::get_last_name() {return last_name;};
std::string Contact::get_nickname() {return nickname;};
std::string Contact::get_phone_number() {return phone_number;};
std::string Contact::get_darkest_secret() {return darkest_secret;};