#pragma once

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string _name;
		Zombie();

	public:

		Zombie(std::string name);
		~Zombie();

		void	announce();

};