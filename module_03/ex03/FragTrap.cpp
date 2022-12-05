#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << FRAG_COLOR << "FragTrap " << _name << " dropped here! (Default constructor)" << END << std::endl; 
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}


FragTrap::FragTrap(const std::string &name): ClapTrap(name)
{
	std::cout << FRAG_COLOR << "FragTrap " << _name << " dropped here! (Default constructor with input name)" << END << std::endl; 
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;	
}


FragTrap::~FragTrap()
{
	std::cout << FRAG_COLOR << "FragTrap " << _name << " suddenly explode!" << END << std::endl; 
}


FragTrap::FragTrap(const FragTrap &src): ClapTrap(src)
{
	std::cout << FRAG_COLOR << "FragTrap " << src._name << " dropped here! (Copy constructor)" << END << std::endl;
}


FragTrap & FragTrap::operator = (const FragTrap &rhs)
{
	std::cout << FRAG_COLOR << "FragTrap " << rhs._name << " dropped here! (Copy assignment constructor)" << END << std::endl;
	ClapTrap::operator=(rhs);
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << FRAG_COLOR << "FragTrap " << _name << " wanna high Fives his buddies!" << END << std::endl;
}