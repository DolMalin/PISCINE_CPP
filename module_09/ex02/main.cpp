#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: not enough arguments" << std::endl;
		return EXIT_FAILURE;
	}

	try
	{
		PmergeMe PmergeMe(++av);
		std::cout << "before: ";
		PmergeMe.displayVector();
		std::cout << std::endl;

		PmergeMe.sort();

		std::cout << "after: ";
		PmergeMe.displayVector();
		std::cout << std::endl;

		std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << PmergeMe.vectorTime() << "ms" << std::endl;
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << PmergeMe.dequeTime() << "ms" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
}