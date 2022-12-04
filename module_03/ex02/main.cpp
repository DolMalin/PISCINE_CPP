#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << "#1" << std::endl;
	{
		std::cout << "=============================" << std::endl;
		std::cout << "CONSTRUCTORS" << std::endl;
		std::cout << "=============================" << std::endl;

		FragTrap michel;
		FragTrap jacques("Jacques");

		std::cout << std::endl;
		std::cout << "=============================" << std::endl;
		std::cout << "ACTIONS" << std::endl;
		std::cout << "=============================" << std::endl;

		michel.highFivesGuys();
		jacques.attack("michel");
		michel.takeDamage(100);

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

		FragTrap bernard("bernard");
		FragTrap bernardCopy1(bernard);
		FragTrap bernardCopy2 = bernardCopy1;

		ScavTrap marcel("marcel");

		std::cout << std::endl;
		std::cout << "=============================" << std::endl;
		std::cout << "ACTIONS" << std::endl;
		std::cout << "=============================" << std::endl;

		bernardCopy2.attack("marcel");
		marcel.takeDamage(100);

		std::cout << std::endl;
		std::cout << "=============================" << std::endl;
		std::cout << "DESTRUCTORS" << std::endl;
		std::cout << "=============================" << std::endl;
	}
}