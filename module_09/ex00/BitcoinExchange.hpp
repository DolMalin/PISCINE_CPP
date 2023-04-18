#pragma once

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <limits>

# define DATABASE_FILE "data.csv"

class BitcoinExchange
{

	private:
		std::map<std::string, double>_map;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & src);
		BitcoinExchange & operator = (const BitcoinExchange & rhs);
		~BitcoinExchange();

		bool isValidDate(std::string str);

		class DatabaseErrorException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class DateStringErrorException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};