#include "Scalar.hpp"

int main(int ac, char **av)
{
	std::string arg;

	if (ac != 2)
	{
		std::cerr << "Invalid input" << std::endl;
		return EXIT_FAILURE;
	}

	arg = av[1];



	std::string types [4] = {
		"char",
		"int",
		"float",
		"double"
	};

	Scalar s(arg);

	std::cout << s.typeString() << std::endl;

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
		std:: cout << s.toFloat() << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	// std::cout << 0.0f << std::endl;

}