#pragma once

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <limits>

# define DATABASE_FILE "data.csv"
# define WHITESPACE " \n\r\t\f\v"

class BitcoinExchange
{

	private:
		std::map<std::string, double>	_map;
		BitcoinExchange();

	public:
		BitcoinExchange(const std::string &file_path);
		BitcoinExchange(const BitcoinExchange & src);
		BitcoinExchange & operator = (const BitcoinExchange & rhs);
		~BitcoinExchange();

		bool isDate(const std::string &str);
		bool isNumber(const std::string &str);
		bool isLowerThan(const std::string &str, int threshold);

		std::string trim(const std::string &str);
		float 		convert(const std::string &date, const std::string &value);

		class BadInputException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class BadDatabaseException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class InvalidDateException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class InvalidValueException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotAPositiveNumberException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class TooLargeNumberException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};