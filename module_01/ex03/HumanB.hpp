#pragma once

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;
	
	public:
		HumanB(std::string name);
		void attack();
		void setWeapon(Weapon &weapon);
};