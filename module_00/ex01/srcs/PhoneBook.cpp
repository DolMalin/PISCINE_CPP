#include "PhoneBook.hpp"

static std::string	truncate(std::string toTruncate)
{
	unsigned	len;

	len = toTruncate.size();
	if (len < 10)
		toTruncate.insert(0, 10 - len, ' '); 
	else if (len > 10)
		toTruncate = toTruncate.substr(0, 9) + ".";
	return toTruncate;
}

PhoneBook::PhoneBook(void)
{
	this->_len = 0;
	return ;
}


PhoneBook::~PhoneBook(void) {}


std::string	PhoneBook::askInfo(std::string str)
{
	std::string buffer;

	buffer = "";
	while (buffer.empty() && !std::cin.eof())
	{
		std::cout << "Enter a " << str << ": ";
		std::getline(std::cin, buffer);
	}
	return buffer;
}


void PhoneBook::setContact(size_t index)
{
	_contacts[index].setFirstName(askInfo("first name"));
	_contacts[index].setLastName(askInfo("last name"));
	_contacts[index].setNickName(askInfo("nick name"));
	_contacts[index].setPhoneNumber(askInfo("phone number"));
	_contacts[index].setSecret(askInfo("darkest secret"));

	if (_len < 8)
		_len++;
}


Contact PhoneBook::contact(size_t index)
{
	return _contacts[index];
}


size_t	PhoneBook::len(void)
{
	return _len;
}


void	PhoneBook::printContacts(void)
{
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << "|";
		for (size_t j = 0; j < this->_len; j++)
		{
			if (i == 0)
				std::cout << truncate(contact(j).firstName()) << "|";
			else if (i == 1)
				std::cout << truncate(contact(j).lastName()) << "|";
			else if ( i == 2)
				std::cout << truncate(contact(j).nickName()) << "|";
			else
				std::cout << "         " << j << "|";
		}
		std::cout << std::endl;
	}
}

void	PhoneBook::printContact(size_t index)
{
	if (index >= _len)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	std::cout << "First Name: " << contact(index).firstName() << std::endl;
	std::cout << "Last Name: " << contact(index).lastName()  << std::endl;
	std::cout << "Nick Name: " << contact(index).nickName()  << std::endl;
	std::cout << "Phone Number: " << contact(index).phoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact(index).secret() << std::endl;
}

std::string	PhoneBook::askCommand()
{
	std::string  command;
	
	while (command.empty() && !std::cin.eof())
	{
		std::cout << std::endl << "=====================================" << std::endl;
		std::cout << "Enter a command [ADD - SEARCH - EXIT]: ";
		std::getline(std::cin, command);
		std::cout << "=====================================" << std::endl;
	}
	return  command;
}


size_t	PhoneBook::askUserIndex()
{
	std::string  command;
	
	while (command.empty() && !std::cin.eof())
	{
		std::cout << std::endl << "=====================================" << std::endl;
		std::cout << "Enter a contact index [";
		for(size_t i = 0; i < this->_len; i++)
		{
			std::cout << i;
			if (i < this->_len - 1)
				std::cout << " - ";
		}
		std::cout << "]: ";
		std::getline(std::cin, command);
		std::cout << "=====================================" << std::endl;
	}
	if (command.length() != 1)
		return 9;
	return  (int)command.at(0) - '0'; 
}