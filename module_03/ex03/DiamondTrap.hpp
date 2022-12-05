#pragma once

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
		// Constructors / Destructors
		DiamondTrap();
		DiamondTrap(const std::string &name);
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &src);
		DiamondTrap & operator = (const DiamondTrap &rhs);

		// Methods
		void whoAmI();
		void attack(const std::string &target);

		// Getters
		std::string		name();
		std::string		clapName();
		unsigned int	hitPoints();
		unsigned int	energyPoints();
		unsigned int	attackDamage();
};