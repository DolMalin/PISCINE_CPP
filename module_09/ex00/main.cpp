#include "BitcoinExchange.hpp"

int	main(void)
{
	try
	{
		BitcoinExchange btc = BitcoinExchange();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}
