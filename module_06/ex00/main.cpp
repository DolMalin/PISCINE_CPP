#include "Scalar.hpp"
#include <iomanip>

int main(int ac, char **av)
{
	std::string arg;

	if (ac != 2)
	{
		std::cerr << "Invalid input" << std::endl;
		return EXIT_FAILURE;
	}

	arg = av[1];
	Scalar s(arg);

	try
	{
		std::cout << "char: ";
		std:: cout << s.toChar() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "int: ";
		std:: cout << s.toInt() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	try
	{
		std::cout << "float: ";
		double tmp;
		if (modf(s.toFloat(), &tmp) == 0)
			std::cout << std::setprecision(1) << std::fixed;
		std::cout << s.toFloat() << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	

	try
	{
		std::cout << "double: ";
		double tmp;
		if (modf(s.toDouble(), &tmp) == 0)
			std::cout << std::setprecision(1) << std::fixed;
		std::cout << s.toDouble() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}