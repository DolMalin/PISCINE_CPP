#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap " << _name << " just appear!" << std::endl; 
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}


ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
	std::cout << "ScavTrap " << _name << " just appear!" << std::endl; 
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;	
}


ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " disappeared mysteriously!" << std::endl; 
}


ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src) { }


ScavTrap & ScavTrap::operator = (const ScavTrap &rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}


void ScavTrap::attack(const std::string &target)
{
	if (_hitPoints == 0)
		std::cout << "ScavTrap " << _name << " is dead and can't attack !" << std::endl;
	else if (_energyPoints == 0)
		std::cout << "ScavTrap " << _name << " is exhausted and can't attack " << target << "." << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << "!" << std::endl;
		_energyPoints--;
	}
}


void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " enter in Gate Keeper mode!" << std::endl;
}