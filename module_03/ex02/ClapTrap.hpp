#pragma once

#include <string>
#include <iostream>
#include <limits.h>

# define CLAP_COLOR "\x1B[36m"
# define SCAV_COLOR "\x1B[35m"
# define FRAG_COLOR "\x1B[32m"
# define END "\033[0m"

class ClapTrap
{
	protected:
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