#include "Zombie.hpp"


Zombie::Zombie () {};

Zombie::~Zombie () {
	std::cout << _name << " just died !" << std::endl;
};

void	Zombie::announce()
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


void	Zombie::setName(std::string name)
{
	_name = name;
}