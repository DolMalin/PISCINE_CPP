#include "Harl.hpp"

static int getComplainCode(std::string complain, std::string *complainList)
{
	for (int i = 0; i < 4; i++)
	{
		if (complain == complainList[i])
			return i;
	}
	return -1;
}

int main(int ac, char **av)
{
	Harl harl;

	std::string complainList[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	if (ac != 2)
	{
		std::cout << "Invalid arguments" << std::endl;
		return 1;
	}

	switch(getComplainCode(av[1], complainList))
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain(complainList[0]);
			// fall through
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain(complainList[1]);
			// fall through
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain(complainList[2]);
			// fall through
		case 3:
			std::cout << "[ ERROR ]"  << std::endl;
			harl.complain(complainList[3]);
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	};

	return 0;
}