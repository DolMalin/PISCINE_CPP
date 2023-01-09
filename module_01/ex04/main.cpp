#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

static std::string replace(std::string &inputStr, const std::string toReplace, const std::string toInsert)
{
	std::string left;
	std::string right;
	size_t 		n;

	if (inputStr.empty() || toReplace.empty() || toReplace == toInsert)
		return inputStr;
	while( (n = inputStr.find(toReplace)) != std::string::npos)
	{
		left = inputStr.substr(0, n);
		right = inputStr.substr(n + toReplace.length(), inputStr.length() - n + toReplace.length());
		right = right.insert(0, toInsert);
 		inputStr = left + right;
	}
	return inputStr;
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Wrong number of arguments" << std::endl;
		return 1;
	}

	std::ifstream file1(av[1]);
	if (!file1.is_open())
	{
		std::cerr << "Can't open file: " << av[1] << std::endl;
		return 1;
	}

	std::string inputStr;
	std::ostringstream ss;
	ss << file1.rdbuf();
	inputStr = ss.str();
	file1.close();

	std::ofstream outfile (std::string(av[1]).append(".replace").data());
	if (!outfile.is_open())
	{
		std::cerr << "Can't create file: " << av[1] << std::endl;
		return 1;
	}
	
	outfile << replace(inputStr, std::string(av[2]), std::string(av[3]));;
	outfile.close();

	return 0;
}