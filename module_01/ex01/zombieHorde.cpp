#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde;
	
	if (N < 1)
	{
		std::cout << "Invalid number of zombies (" << N << ")" << std::endl;
		return NULL;
	}
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return horde;
}
