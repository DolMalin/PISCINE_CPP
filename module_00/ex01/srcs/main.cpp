/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:21:00 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/11/19 21:00:51 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

std::string	getCommand(void)
{
	std::string  command;
	
	 command = "";
	while ( command.empty() && !std::cin.eof())
	{
		std::cout << std::endl << "=====================================" << std::endl;
		std::cout << "Enter a command [ADD - SEARCH - EXIT]: ";
		std::getline(std::cin, command);
		std::cout << "=====================================" << std::endl;
	}
	return  command;
}

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
	std::string	command;

	while(!std::cin.eof()) 
	{
		command = getCommand();
		if (command == "ADD")
		{
			if (repertory.getLen() == 8)
				repertory.setContact(0);
			else
				repertory.setContact(repertory.getLen());
		}
		else if (command == "SEARCH")
		{
			for (size_t i = 0; i < 4; i++)
			{
				std::cout << "|";
				for (size_t j = 0; j < repertory.getLen(); j++)
				{
					if (i == 0)
						std::cout << truncate(repertory.getContact(j).getFirstName()) << "|";
					else if (i == 1)
						std::cout << truncate(repertory.getContact(j).getLastName()) << "|";
					else if ( i == 2)
						std::cout << truncate(repertory.getContact(j).getNickName()) << "|";
					else
						std::cout << "         " << j << "|";
				}
				std::cout << std::endl;
			}
		}
		else if (command == "EXIT")
			break ;
	}
	return (0);
}
