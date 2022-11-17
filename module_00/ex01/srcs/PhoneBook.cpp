/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:20:57 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/11/17 12:45:40 by pdal-mol         ###   ########.fr       */
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

std::string	PhoneBook::askInfo(std::string str)
{
	std::string buffer;

	buffer = "";
	while (buffer.empty())
	{
		std::cout << "Enter a " << str << ": ";
		std::getline(std::cin, buffer);
	}
	return (buffer);
}


void PhoneBook::setContact(size_t index)
{
	if (index > 7)
	{
		std::cout << "Phonebook is full, last contact has been replaced" << std::endl;
		return ;
	}

	_contacts[index].setFirstName(askInfo("first name"));
	_contacts[index].setLastName(askInfo("last name"));
	_contacts[index].setNickName(askInfo("nick name"));
	_contacts[index].setPhoneNumber(askInfo("phone number"));
	_contacts[index].setSecret(askInfo("darkest secret"));
	
	_len++;
}