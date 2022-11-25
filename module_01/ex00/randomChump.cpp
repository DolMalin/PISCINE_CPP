#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie marcel = Zombie(name);
	marcel.announce();
}