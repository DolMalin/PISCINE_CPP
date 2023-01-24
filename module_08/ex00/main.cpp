#include "easyfind.hpp"


int main(void)
{
	std::vector<int> vectorInt(3);
	std::list<int> listInt(4);
	std::stack<int> stackInt;
	
	
	vectorInt[0] = 1;
	vectorInt[1] = 2;
	vectorInt[2] = 3;

	listInt.push_back(4);
	listInt.push_back(5);
	listInt.push_back(6);
	listInt.push_back(7);

	stackInt.push(8);
	stackInt.push(9);
	stackInt.push(10);
	stackInt.push(11);
	
	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #1 (Vector int)" << std::endl;
	std::cout << "==============================================================" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind<std::vector<int> >(vectorInt, 2);
		std::cout << "Found : " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #2 (Vector int)" << std::endl;
	std::cout << "==============================================================" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind<std::vector<int> >(vectorInt, 10);
		std::cout << "Found : " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #3 (List int)" << std::endl;
	std::cout << "==============================================================" << std::endl;
	try
	{
		std::list<int>::iterator it = easyfind<std::list<int> >(listInt, 5);
		std::cout << "Found : " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #4 (List int)" << std::endl;
	std::cout << "==============================================================" << std::endl;
	try
	{
		std::list<int>::iterator it = easyfind<std::list<int> >(listInt, 10);
		std::cout << "Found : " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}