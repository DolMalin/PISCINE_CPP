#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream database(DATABASE_FILE);
	if (!database.is_open())
		throw DatabaseErrorException();
	
	std::string line;
	std::getline(database, line);
	size_t pos = 0;
	while(std::getline(database, line))
	{
		pos = line.find(",");
		if (pos == std::string::npos)
			throw DatabaseErrorException();
		
		// std::cout << std::atof(line.substr(pos + 1).c_str()) << std::endl;
		if (!isValidDate(line.substr(0, pos)))
			throw DateStringErrorException();
		
		_map[line.substr(0, pos)] = std::atof(line.substr(pos + 1).c_str());
	}

	// for (std::map<std::string, double>::const_iterator it = _map.begin(); it != _map.end(); it++)
	// {
	// 	std::cout << it->first << " " << it->second << std::endl;
	// }
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


bool BitcoinExchange::isValidDate(std::string str)
{
	std::cout << str << std::endl;
	int		dashes_count = 0;
	char 	*p_buffer = NULL;
	long	l_buffer = 0;
	size_t	dash1_p = 0;
	size_t	dash2_p = 0;

	for (std::string::iterator it = str.begin(); it != str.end(); it++)
		if (*it == '-') dashes_count++;
	if (dashes_count != 2)
		return false;
	
	// Parse year
	dash1_p = str.find('-');
	l_buffer = std::strtol(str.substr(0, dash1_p).c_str(), &p_buffer, 10);
	if (*p_buffer)
		return false;

	// Parse month
	dash1_p++;
	p_buffer = NULL;
	l_buffer = 0;
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

const char *BitcoinExchange::DatabaseErrorException::what() const throw()
{
	return "database error";
}

const char *BitcoinExchange::DateStringErrorException::what() const throw()
{
	return "date string error";
}