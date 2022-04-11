/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:38:22 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/04/11 14:53:44 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{	
	std::string	elem;
	
	if (ac < 2)
	{
		std::cout << "LOUD AND UNBEARABLE FEEDBACK NOISE" << std::endl;
		return (1);
	}
	
	for (int i = 1; i < ac; i++)
	{
		elem = av[i];
		for (std::string::iterator it = elem.begin(); it < elem.end(); it++)
			*it = toupper(*it);
		std::cout << elem;
	}
		
	std::cout << std::endl;
	return (0);
}
