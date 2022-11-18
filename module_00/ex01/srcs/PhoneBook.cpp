/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:20:57 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/11/18 11:52:39 by pdal-mol         ###   ########.fr       */
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
	return buffer;
}


void PhoneBook::setContact(size_t index)
{
	_contacts[index].setFirstName(askInfo("first name"));
	_contacts[index].setLastName(askInfo("last name"));
	_contacts[index].setNickName(askInfo("nick name"));
	_contacts[index].setPhoneNumber(askInfo("phone number"));
	_contacts[index].setSecret(askInfo("darkest secret"));

	if (_len < 8)
		_len++;
}


Contact PhoneBook::getContact(size_t index)
{
	return _contacts[index];
}

size_t	PhoneBook::getLen(void)
{
	return _len;
}