#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
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
			std::string err_buffer;

			try {
				pos = line.find("|");

				err_buffer = "no separator `|`";
				if (pos == std::string::npos)
					throw BitcoinExchange::BadInputException();

				date = btc.trim(line.substr(0, pos));
				value = btc.trim(line.substr(pos+1));

				// check date
				err_buffer = date.empty() ? "empty value" : date;
				if (!btc.isDate(date))
					throw BitcoinExchange::InvalidDateException();
				else if (btc.lowestDate().compare(date) > 0)
					throw BitcoinExchange::InvalidDateException();
	
				// check value
				err_buffer = value.empty() ? "empty value" : value;
				if (!btc.isNumber(value))
					throw BitcoinExchange::InvalidValueException();
				else if (btc.isLowerThan(value, 0))
					throw BitcoinExchange::NotAPositiveNumberException();
				else if (!btc.isLowerThan(value, 1000))
					throw BitcoinExchange::TooLargeNumberException();

				std::cout << date << " => " << value
				<< " = " << btc.convert(date, value) << std::endl;
				
			}
			catch(const std::exception &e)
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
