#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << SCAV_COLOR << "ScavTrap " << _name << " just appear! (Default constructor)" << END << std::endl; 
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}


ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
	std::cout << SCAV_COLOR << "ScavTrap " << _name << " just appear! (Default constructor with input name)" << END << std::endl; 
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}


ScavTrap::~ScavTrap()
{
	std::cout << SCAV_COLOR << "ScavTrap " << _name << " disappeared mysteriously!" << END << std::endl; 
}


ScavTrap::ScavTrap(const ScavTrap &src): ClapTrap(src)
{
	std::cout << SCAV_COLOR << "ScavTrap " << src._name << " just appear! (Copy constructor)" << END << std::endl;
}


ScavTrap & ScavTrap::operator = (const ScavTrap &rhs)
{
	std::cout << SCAV_COLOR << "ScavTrap " << rhs._name << " just appear! (Copy assignment constructor)" << END << std::endl;
	ClapTrap::operator=(rhs);
	return *this;
}


void ScavTrap::attack(const std::string &target)
{
	std::cout << SCAV_COLOR;
	if (_hitPoints == 0)
		std::cout << "ScavTrap " << _name << " is dead and can't attack !" << std::endl;
	else if (_energyPoints == 0)
		std::cout << "ScavTrap " << _name << " is exhausted and can't attack " << target << "." << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << "!" << std::endl;
		_energyPoints--;
	}
	std::cout << END;
}


void ScavTrap::guardGate()
{
	std::cout << SCAV_COLOR << "ScavTrap " << _name << " enter in Gate Keeper mode!" << END << std::endl;
}