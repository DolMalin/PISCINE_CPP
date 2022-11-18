/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:21:00 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/11/18 13:09:11 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	truncate(std::string toTruncate)
{
	unsigned	len;

	len = toTruncate.size();
	if (len < 10)
		toTruncate.insert(0, 10 - len, ' '); 
	else if (len > 10)
		toTruncate = toTruncate.substr(0, 9) + ".";
	return toTruncate;
}

int	main(void)
{
	PhoneBook	repertory;
	std::string	buffer;

	while(true)
	{
		buffer = "";
		while (buffer.empty())
		{
			std::cout << std::endl << "=====================================" << std::endl;
			std::cout << "Enter a command [ADD - SEARCH - EXIT]: ";
			std::getline(std::cin, buffer);
			std::cout << "=====================================" << std::endl;
		}
		if (buffer == "ADD")
		{
			if (repertory.getLen() == 8)
				repertory.setContact(0);
			else
				repertory.setContact(repertory.getLen());
			continue;
		}
		else if (buffer == "SEARCH")
		{
			for (size_t i = 0; i < repertory.getLen(); i++)
			{
				std::cout << i << std::endl;
				std::cout << truncate(repertory.getContact(i).getFirstName()) << std::endl;
				std::cout << truncate(repertory.getContact(i).getLastName()) << std::endl;
				std::cout << truncate(repertory.getContact(i).getNickName()) << std::endl;
				std::cout << truncate(repertory.getContact(i).getPhoneNumber()) << std::endl;
				std::cout << truncate(repertory.getContact(i).getSecret()) << std::endl;
				std::cout << std::endl;
			}
		}
		else if (buffer == "EXIT")
			break ;
	}
	return (0);
}
