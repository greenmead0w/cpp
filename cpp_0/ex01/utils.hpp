/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzuloaga <mzuloaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:25:33 by mzuloaga          #+#    #+#             */
/*   Updated: 2025/02/15 09:38:20 by mzuloaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "Phonebook.hpp"

void ft_print_according_to_index(std::string &index_str, Phonebook &phonebook);
void ft_print_search_headers();
std::string ft_truncate(const std::string &str);
bool ft_is_valid_PN(std::string pn);

#endif