#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "#1" << std::endl;
	{
		std::cout << "=============================" << std::endl;
		std::cout << "CONSTRUCTORS" << std::endl;
		std::cout << "=============================" << std::endl;

		ClapTrap michel;
		ClapTrap jacques("Jacques");

		std::cout << std::endl;
		std::cout << "=============================" << std::endl;
		std::cout << "ACTIONS" << std::endl;
		std::cout << "=============================" << std::endl;

		for (int i = 0; i < 11; i++)
		{
			michel.attack("Jacques");
			jacques.takeDamage(1);
		}
		jacques.beRepaired(1);
		michel.attack("Jacques");
		jacques.takeDamage(1);

		std::cout << std::endl;
		std::cout << "=============================" << std::endl;
		std::cout << "DESTRUCTORS" << std::endl;
		std::cout << "=============================" << std::endl;
	}

	std::cout << std::endl << "#2" << std::endl;
	{
		std::cout << "=============================" << std::endl;
		std::cout << "CONSTRUCTORS" << std::endl;
		std::cout << "=============================" << std::endl;

		ClapTrap michel;
		ClapTrap roger("Roger");
		ClapTrap rogerCopy1(roger);
		ClapTrap rogerCopy2 = rogerCopy1;

		std::cout << std::endl;
		std::cout << "=============================" << std::endl;
		std::cout << "ACTIONS" << std::endl;
		std::cout << "=============================" << std::endl;

		michel.attack("Roger");
		rogerCopy2.takeDamage(9);

		rogerCopy2.beRepaired(1);

		michel.attack("Roger");
		rogerCopy2.takeDamage(1);

		std::cout << std::endl;
		std::cout << "=============================" << std::endl;
		std::cout << "DESTRUCTORS" << std::endl;
		std::cout << "=============================" << std::endl;
	}

}