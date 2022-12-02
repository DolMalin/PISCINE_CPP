
#include "Fixed.hpp"
#include <iostream>
#include <string>
#include <sstream>

# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define END "\033[0m"

int main( int ac, char **av)
{
	std::stringstream	ss;
	float 				a_f;
	float 				b_f;

	if (ac != 3)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return 1;
	}

	ss << (std::string(av[1]));
	ss >> a_f;
	ss.clear();
	ss << (std::string(av[2]));
	ss >> b_f;

	Fixed a(a_f);
	Fixed b(b_f);

	std::cout << "===================================" << std::endl;
	std::cout << "Comparison operators" << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << (a > b ? GREEN : RED) << a << " > " << b << END <<std::endl;
	std::cout << (a < b ? GREEN : RED) << a << " < " << b << END <<std::endl;
	std::cout << (a >= b ? GREEN : RED) << a << " >= " << b << END <<std::endl;
	std::cout << (a <= b ? GREEN : RED) << a << " <= " << b << END <<std::endl;
	std::cout << (a == b ? GREEN : RED) << a << " == " << b << END <<std::endl;
	std::cout << (a != b ? GREEN : RED) << a << " != " << b << END <<std::endl;

	std::cout << std::endl;

	std::cout << "===================================" << std::endl;
	std::cout << "Arithmetic operators" << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::cout << a << " - " << b << " = " << a - b << std::endl;
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::cout << a << " / " << b << " = " << a / b << std::endl;

	std::cout << std::endl;

	std::cout << "===================================" << std::endl;
	std::cout << "Increment/Decrement operators" << std::endl;
	std::cout << "===================================" << std::endl;
	std::cout << "a = " << a << "; ++a = " << ++a << "; a = " << a << std::endl;
	std::cout << "a = " << a << "; a++ = " << a++ << "; a = " << a << std::endl;
	std::cout << "a = " << a << "; --a = " << --a << "; a = " << a << std::endl;
	std::cout << "a = " << a << "; a-- = " << a-- << "; a = " << a << std::endl;

	std::cout << std::endl;

	std::cout << "b = " << b << "; ++b = " << ++b << "; b = " << b << std::endl;
	std::cout << "b = " << b << "; b++ = " << b++ << "; b = " << b << std::endl;
	std::cout << "b = " << b << "; --b = " << --b << "; b = " << b << std::endl;
	std::cout << "b = " << b << "; b-- = " << b-- << "; b = " << b << std::endl;

	std::cout << std::endl;

	std::cout << "===================================" << std::endl;
	std::cout << "Min/Max methods" << std::endl;
	std::cout << "===================================" << std::endl;
	const Fixed aConst = a;
	const Fixed bConst = b;
	std::cout << "min(" << a << ", " << b << ") = " << Fixed::min(a, b) << std::endl;
	std::cout << "const min(" << aConst << ", " << bConst << ") = " << Fixed::min(aConst, bConst) << std::endl;
	std::cout << "max(" << a << ", " << b << ") = " << Fixed::max(a, b) << std::endl;
	std::cout << "const max(" << aConst << ", " << bConst << ") = " << Fixed::max(aConst, bConst) << std::endl;

	return 0;
}
