/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:21:11 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/04/11 18:44:55 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

void	Contact::set(void)
{
	std::string buffer;
	
	for (int i = 0; i < FIELDS_LEN; i++)
	{
		buffer = "";
		while (buffer.empty())
		{
			switch (i)
			{
				case FIRST_NAME:
					std::cout << "Enter a first name: ";
					std::getline(std::cin, buffer);
					break;
				case LAST_NAME:
					std::cout << "Enter a last name: ";
					std::getline(std::cin, buffer);
					break;
				case NICK_NAME:
					std::cout << "Enter a nick name: ";
					std::getline(std::cin, buffer);
					break;
				case PHONE_NUMBER:
					std::cout << "Enter a phoner number: ";
					std::getline(std::cin, buffer);
					break;
				case DARKEST_SECRET:
					std::cout << "Enter a darkest secret: ";
					std::getline(std::cin, buffer);
					break;
			}
		}
		this->infos[i] = buffer;
	}
		std::cout << "New user add !" << std::endl;	
}

std::string	Contact::get_info(int type)
{
	if (type < 0 || type >= FIELDS_LEN)
		return ("");
	return (this->infos[type]);
}