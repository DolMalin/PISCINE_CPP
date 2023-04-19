#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 2)
	{
		std::cout << "Error: invalid number of arguments" << std::endl;
		return EXIT_FAILURE;
	}

	try
	{
		BitcoinExchange btc = BitcoinExchange(DATABASE_FILE);

		std::ifstream input_file(av[1]);
		if (!input_file.is_open())
			throw BitcoinExchange::BadInputException();

		std::string	line;
		size_t 		pos = 0;
		std::getline(input_file, line);
		while(std::getline(input_file, line))
		{
			std::string date;
			std::string value;
			std::string err_buffer = "empty";

			try {
				pos = line.find("|");
				if (pos == std::string::npos)
					throw BitcoinExchange::BadInputException();

				date = btc.trim(line.substr(0, pos));
				value = btc.trim(line.substr(pos+1));

				err_buffer = date;
				if (!btc.isDate(date))
					throw BitcoinExchange::InvalidDateException();
				
				err_buffer = value;
				if (!btc.isNumber(value))
					throw BitcoinExchange::InvalidValueException();

				if (btc.isLowerThan(value, 0))
					throw BitcoinExchange::NotAPositiveNumberException();

				if (!btc.isLowerThan(value, 1000))
					throw BitcoinExchange::TooLargeNumberException();

				std::cout << date << " => " << value
				<< " = " << btc.convert(date, value) << std::endl;
				
			} catch(const std::exception &e)
			{
				std::cerr << "Error: " << e.what() << " (" << err_buffer << ")" << std::endl;
			}
			
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
}
