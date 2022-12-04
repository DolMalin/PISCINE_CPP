#include "ClapTrap.hpp"

int	main(void)
{
	{
		ClapTrap michel;
		ClapTrap jacques("Jacques");

		for (int i = 0; i < 11; i++)
		{
			michel.attack("Jacques");
			jacques.takeDamage(1);
		}
		jacques.beRepaired(1);
		michel.attack("Jacques");
		jacques.takeDamage(1);
	}
	{
		std::cout << std::endl;
		ClapTrap michel;
		ClapTrap roger("Roger");

		michel.attack("Roger");
		roger.takeDamage(9);

		roger.beRepaired(1);

		michel.attack("Roger");
		roger.takeDamage(1);
	}

}