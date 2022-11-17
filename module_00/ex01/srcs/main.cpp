/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:21:00 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/11/17 22:17:59 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	repertory;
	std::string	buffer;

	while(true)
	{
		buffer = "";
		while (buffer.empty())
		{
			std::cout << "Enter a command [ADD - SEARCH - EXIT]: ";
			std::getline(std::cin, buffer);
		}
		if (buffer == "ADD")
		{
			if (repertory.getLen() >= 7)
				repertory.setContact(0);
			else
				repertory.setContact(repertory.getLen());
			continue;
		}
		else if (buffer == "SEARCH")
		{
			
		}
		else if (buffer == "EXIT")
			break ;
	}
	return (0);
}
