#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: wrong arguments" << std::endl;
		return EXIT_FAILURE;
	}

	RPN rpn(av[1]);
	try
	{
		rpn.processExpression();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}