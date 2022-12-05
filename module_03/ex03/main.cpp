#include "DiamondTrap.hpp"

static void	printStats(DiamondTrap &src)
{
	std::cout << "name: " << DIAMOND_COLOR << src.name() << END << std::endl;
	std::cout << "clapName: " << DIAMOND_COLOR << src.clapName() << END << std::endl;
	std::cout << "hitPoints: " << DIAMOND_COLOR << src.hitPoints() << END << std::endl;
	std::cout << "energyPoints: " << DIAMOND_COLOR << src.energyPoints() << END <<  std::endl;
	std::cout << "attackDamage: " << DIAMOND_COLOR << src.attackDamage() << END << std::endl;
	std::cout << std::endl;
}


int	main(void)
{
	std::cout << "=============================" << std::endl;
	std::cout << "CONSTRUCTORS" << std::endl;
	std::cout << "=============================" << std::endl;

	DiamondTrap giuseppe("Giuseppe");
	std::cout << std::endl;

	DiamondTrap giuseppeCopy1(giuseppe);
	std::cout << std::endl;

	DiamondTrap giuseppeCopy2(giuseppeCopy1);
	std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "STATS" << std::endl;
	std::cout << "=============================" << std::endl;
	printStats(giuseppe);
	printStats(giuseppeCopy1);
	printStats(giuseppeCopy2);

	std::cout << "=============================" << std::endl;
	std::cout << "ACTION" << std::endl;
	std::cout << "=============================" << std::endl;
	giuseppe.whoAmI();
	giuseppe.highFivesGuys();
	giuseppe.guardGate();

	giuseppe.attack("giuseppe");
	giuseppe.takeDamage(100);

	std::cout << std::endl;
	std::cout << "=============================" << std::endl;
	std::cout << "DESTRUCTOR" << std::endl;
	std::cout << "=============================" << std::endl;
}