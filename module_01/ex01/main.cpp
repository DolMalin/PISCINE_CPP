#include "Zombie.hpp"

int	main(void)
{
	int		 N;
	Zombie	*horde;

	/* ===================~ 2 ~=================*/
	std::cout << std::endl << "Let's create 2 Michels !" << std::endl;
	N = 2;
	horde = zombieHorde (N, "Michels");

	for(int i  = 0; i < N; i++)
		horde[i].announce();

	delete [] horde;

	/* ===================~ 10 ~=================*/
	std::cout << std::endl << "Let's create 10 Marcels !" << std::endl;
	N = 10;
	horde = zombieHorde (N, "Marcel");
	if (!horde)
		return 1;

	for(int i  = 0; i < N; i++)
		horde[i].announce();

	delete [] horde;

	/* ===================~ 1 ~=================*/
	std::cout << std::endl << "Let's create 1 Bruno !" << std::endl;
	N = 1;
	horde = zombieHorde (N, "Bruno");
	if (!horde)
		return 1;

	for(int i  = 0; i < N; i++)
		horde[i].announce();

	delete [] horde;


	/* ===================~ 1 ~=================*/
	std::cout << std::endl << "Let's create 1 Bruno !" << std::endl;
	N = 1;
	horde = zombieHorde (N, "Bruno");
	if (!horde)
		return 1;

	for(int i  = 0; i < N; i++)
		horde[i].announce();

	delete [] horde;

	/* ===================~ 0 ~=================*/
	std::cout << std::endl << "Let's create 0 Jacques !" << std::endl;
	N = 0;
	horde = zombieHorde (N, "Jacques");
	if (!horde)
		return 1;

	for(int i  = 0; i < N; i++)
		horde[i].announce();

	delete [] horde;


	return (0);
}
