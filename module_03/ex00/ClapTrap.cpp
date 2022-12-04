#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Michel"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " has spawned! (Default constructor)" << std::endl; 
}


ClapTrap::ClapTrap(const std::string &name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " has spawned! (Default constructor with input name)" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "ClapTrap " << src._name << " has spawned! (Copy constructor)" << std::endl;
	*this = src;
}

ClapTrap & ClapTrap::operator = (const ClapTrap &rhs)
{
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;

	std::cout << "ClapTrap " << rhs._name << " has spawned! (Copy assignment constructor)" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " is dead and can't attack !" << std::endl;
	else if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " is exhausted and can't attack " << target << "." << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << "!" << std::endl;
		_energyPoints--;
	}
}


void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0 )
		std::cout << "ClapTrap " << _name << " is dead and can't take damages!" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << " damages!" << std::endl;
		if (amount >= _hitPoints)
		{
			_hitPoints = 0;
			std::cout << "ClapTrap " << _name << " died !" << std::endl;
		}
		else
			_hitPoints -= amount;
	}
}


void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
			std::cout << "ClapTrap " << _name << " is dead and can't be repaired!" << std::endl;
	else if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " is exhausted and can't be repaired!" << std::endl;
	else
	{
		amount = amount + _hitPoints > UINT_MAX ? UINT_MAX : amount;
		_hitPoints = amount;
		std::cout << "ClapTrap " << _name << " repaired " <<  amount << " hit points!" << std::endl;	
	}
}