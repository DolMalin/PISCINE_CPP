#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public virtual ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		~ScavTrap();
		ScavTrap(const ScavTrap &src);
		ScavTrap & operator = (const ScavTrap &rhs);

		void	attack(const std::string &target);
		void	guardGate();
};