#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string &file_path)
{
	std::ifstream database(file_path.c_str());
	if (!database.is_open())
		throw BadInputException();

	std::string	line;
	size_t 		pos = 0;
	std::getline(database, line);

	while(std::getline(database, line))
	{
		std::string date;
		std::string value;

		pos = line.find(",");
		if (pos == std::string::npos)
			throw BadDatabaseException();

		date = trim(line.substr(0, pos));
		value = trim(line.substr(pos+1));
		
		if (!isDate(date))
			throw InvalidDateException();
		
		if (!isNumber(value))
			throw InvalidValueException();
		
		_map[date] = std::atof(value.c_str());
	}
	if (_map.empty())
		throw BadDatabaseException();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	_map = src._map;
}

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange & rhs)
{
	_map = rhs._map;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}


bool BitcoinExchange::isDate(const std::string &str)
{
	int		dashes_count = 0;
	char 	*p_buffer = NULL;
	long	l_buffer = 0;
	size_t	dash1_p = 0;
	size_t	dash2_p = 0;

	if (str.empty())
		return false;

	for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
		if (*it == '-') dashes_count++;
	if (dashes_count != 2)
		return false;
	
	// Parse year
	dash1_p = str.find('-');
	l_buffer = std::strtol(str.substr(0, dash1_p).c_str(), &p_buffer, 10);
	if (*p_buffer || l_buffer > 9999)
		return false;


	// Parse month
	dash1_p++;
	dash2_p = str.find('-', dash1_p + 1);
	l_buffer = std::strtol(str.substr(dash1_p, dash2_p - dash1_p).c_str(), &p_buffer, 10);
	if (*p_buffer || l_buffer < 0 || l_buffer > 12)
		return false;
	
	// Parse day
	dash2_p++;
	p_buffer = NULL;
	l_buffer = 0;
	l_buffer = std::strtol(str.substr(dash2_p).c_str(), &p_buffer, 10);
	if (*p_buffer || l_buffer < 0 || l_buffer > 31)
		return false;
	
	return true;
}

bool BitcoinExchange::isNumber(std::string str)
{
	char 	*p_buffer = NULL;

	if (str.empty())
		return false;

	if (str.find(".") != std::string::npos || *str.rbegin() == 'f')
	{
		if (*str.rbegin() == 'f')
			str = str.substr(0, str.size() -1);
		std::strtof(str.c_str(), &p_buffer);
		if (*p_buffer)
			return false;
	}
	else
	{
		std::strtol(str.c_str(), &p_buffer, 10);
		if (*p_buffer)
			return false;
	}

	return true;
}


bool BitcoinExchange::isLowerThan(std::string str, int threshold)
{
	char 	*p_buffer = NULL;
	long	l_buffer = 0;
	double	d_buffer = 0;

	if (str.find(".") != std::string::npos || *str.rbegin() == 'f')
	{
		if (*str.rbegin() == 'f')
			str = str.substr(0, str.size() -1);

		d_buffer = std::strtof(str.c_str(), &p_buffer);
		if (*p_buffer || d_buffer > double(threshold))
			return false;
	}
	else
	{
		l_buffer = std::strtol(str.c_str(), &p_buffer, 10);
		if (*p_buffer || l_buffer > threshold)
			return false;
	}
	return true;
}


const std::string BitcoinExchange::lowestDate()
{
	return _map.begin()->first;
}


std::string BitcoinExchange::trim(const std::string &str)
{
    std::string::const_iterator it = str.begin();
    while (it != str.end() && isspace(*it))
        it++;

    std::string::const_reverse_iterator rit = str.rbegin();
    while (rit.base() != it && isspace(*rit))
        rit++;

    return std::string(it, rit.base());
}


float BitcoinExchange::convert(const std::string &date, const std::string &value)
{
	if (_map.find(date) == _map.end())
		return _map.lower_bound(date)->second * std::strtof(value.c_str(), NULL);
	else
		return _map[date] * std::strtof(value.c_str(), NULL);
}


const char *BitcoinExchange::BadInputException::what() const throw()
{
	return "bad input";
}

const char *BitcoinExchange::BadDatabaseException::what() const throw()
{
	return "bad database";
}

const char *BitcoinExchange::InvalidDateException::what() const throw()
{
	return "invalid date";
}

const char *BitcoinExchange::InvalidValueException::what() const throw()
{
	return "invalid number";
}

const char *BitcoinExchange::NotAPositiveNumberException::what() const throw()
{
	return "not a positive number";
}

const char *BitcoinExchange::TooLargeNumberException::what() const throw()
{
	return "too large number";
}