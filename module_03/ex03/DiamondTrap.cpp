#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << DIAMOND_COLOR << "DiamondTrap " << _name << " arrives majestically! (Default constructor)" << END << std::endl; 
	this->_name = ClapTrap::_name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;

}

DiamondTrap::DiamondTrap(const std::string &name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
	std::cout << DIAMOND_COLOR << "DiamondTrap " << name << " arrives majestically! (Default constructor with input name)" << END << std::endl; 
	this->_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
}


DiamondTrap::~DiamondTrap()
{
	std::cout << DIAMOND_COLOR << "DiamondTrap " << _name << " vanished into sparkly stardust!" << END << std::endl;
}


DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src), ScavTrap(src), FragTrap(src)
{
	std::cout << DIAMOND_COLOR << "DiamondTrap " << src._name << " arrives majestically! (Copy constructor)" << END << std::endl; 
	*this = src;
}


DiamondTrap & DiamondTrap::operator = (const DiamondTrap &rhs)
{
	std::cout << DIAMOND_COLOR << "DiamondTrap " << rhs._name << " arrives majestically! (Copy assignment constructor)" << END << std::endl;
	ClapTrap::_name = rhs._name + "_clap_name";
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints =  rhs._energyPoints;
	_attackDamage = rhs._attackDamage;

	return *this;
}


void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}


void DiamondTrap::whoAmI()
{
	std::cout << DIAMOND_COLOR << "I'm " << name() << ", but you can call me " << clapName() << END << std::endl;
}


std::string DiamondTrap::name()
{
	return _name;
}


std::string DiamondTrap::clapName()
{
	return _name;
}

unsigned int DiamondTrap::hitPoints()
{
	return _hitPoints;
}


unsigned int DiamondTrap::attackDamage()
{
	return _attackDamage;
}



unsigned int DiamondTrap::energyPoints()
{
	return _energyPoints;
}