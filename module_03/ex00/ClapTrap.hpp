#pragma once

#include <string>
#include <iostream>
#include <limits.h>

class ClapTrap
{
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		// Constructors / Destructors
		ClapTrap();
		ClapTrap(const std::string &name);
		~ClapTrap();
		ClapTrap(const ClapTrap &src);
		ClapTrap & operator = (const ClapTrap & rhs);

		// Methods
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};