#include "Zombie.hpp"

int	main(void)
{
	Zombie *michel = newZombie("Michel");
	michel->announce();
	delete michel;

	randomChump("Marcel");

	return (0);
}
