/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:20:57 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/04/11 18:35:10 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_len = 0;
	return ;
}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::add_contact(void)
{
	if (this->_len > 7)
	{
		std::cout << "Phonebook is full, last contact has been replaced" << std::endl;
		return ;
	}
	this->_contacts[this->_len].set();
	
	std::cout << this->_contacts[this->_len].get_info(FIRST_NAME) << std::endl;
	std::cout << this->_contacts[this->_len].get_info(LAST_NAME) << std::endl;
	std::cout << this->_contacts[this->_len].get_info(NICK_NAME) << std::endl;
	std::cout << this->_contacts[this->_len].get_info(PHONE_NUMBER) << std::endl;
	std::cout << this->_contacts[this->_len].get_info(DARKEST_SECRET) << std::endl;
	
	this->_len++;
}