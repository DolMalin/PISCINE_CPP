#pragma once

#include "ClapTrap.hpp"

class FragTrap: public virtual ClapTrap
{
	public:
		FragTrap();
		FragTrap(const std::string &name);
		~FragTrap();
		FragTrap(const FragTrap &src);
		FragTrap & operator = (const FragTrap &rhs);

		void highFivesGuys(void);
};