#include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << std::endl << "DEBUG" << std::endl;
	harl.complain("DEBUG");

	std::cout << std::endl << "INFO" << std::endl;
	harl.complain("INFO");

	std::cout << std::endl << "WARNING" << std::endl;
	harl.complain("WARNING");

	std::cout << std::endl << "ERROR" << std::endl;
	harl.complain("ERROR");

	std::cout << std::endl << "_blank_" << std::endl;
	harl.complain("");
	return 0;
}