/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:21:11 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/11/17 21:50:47 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

/* =================== SET INFOS =================== */

void Contact::setFirstName(std::string str)
{
	_firstName = str;
}


void Contact::setLastName(std::string str)
{
	_lastName = str;
}


void Contact::setNickName(std::string str)
{
	_nickName = str;
}


void Contact::setPhoneNumber(std::string str)
{
	_phoneNumber = str;
}


void Contact::setSecret(std::string str)
{
	_secret = str;
}


/* =================== GET INFOS =================== */

std::string Contact::getFirstName(void)
{
	return _firstName;
}


std::string Contact::getLastName(void)
{
	return _lastName;
}


std::string Contact::getNickName(void)
{
	return _nickName;
}


std::string Contact::getPhoneNumber(void)
{
	return _phoneNumber;
}


std::string Contact::getSecret(void)
{
	return _secret;
}