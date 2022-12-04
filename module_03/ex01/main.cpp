#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	std::cout << "#1" << std::endl;
	{
		std::cout << "=============================" << std::endl;
		std::cout << "CONSTRUCTORS" << std::endl;
		std::cout << "=============================" << std::endl;

		ScavTrap michel;
		ScavTrap jacques("Jacques");

		std::cout << std::endl;
		std::cout << "=============================" << std::endl;
		std::cout << "ACTIONS" << std::endl;
		std::cout << "=============================" << std::endl;

		michel.guardGate();
		jacques.attack("michel");
		michel.takeDamage(100);

		std::cout << std::endl;
		std::cout << "=============================" << std::endl;
		std::cout << "DESTRUCTORS" << std::endl;
		std::cout << "=============================" << std::endl << std::endl;
	}

	std::cout << "#2" << std::endl;
	{
		std::cout << "=============================" << std::endl;
		std::cout << "CONSTRUCTORS" << std::endl;
		std::cout << "=============================" << std::endl;

		ScavTrap bernard("bernard");
		ScavTrap bernardCopy1(bernard);
		ScavTrap bernardCopy2 = bernard;

		std::cout << std::endl;
		std::cout << "=============================" << std::endl;
		std::cout << "ACTIONS" << std::endl;
		std::cout << "=============================" << std::endl;

		bernard.attack("bernard");
		bernardCopy1.takeDamage(100);
		bernard.attack("bernard");
		bernardCopy2.takeDamage(100);
		bernard.attack("bernard");
		bernard.takeDamage(100);

		std::cout << "Oh.. Bernard killed all the Bernards... Including himself ! :o"  << std::endl;
		std::cout << std::endl;
		std::cout << "=============================" << std::endl;
		std::cout << "DESTRUCTORS" << std::endl;
		std::cout << "=============================" << std::endl << std::endl;
	}
}