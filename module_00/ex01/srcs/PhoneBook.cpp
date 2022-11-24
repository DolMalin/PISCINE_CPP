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


Contact PhoneBook::getContact(size_t index)
{
	return _contacts[index];
}


size_t	PhoneBook::getLen(void)
{
	return _len;
}


void	PhoneBook::printContacts(void)
{
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << "|";
		for (size_t j = 0; j < getLen(); j++)
		{
			if (i == 0)
				std::cout << truncate(getContact(j).getFirstName()) << "|";
			else if (i == 1)
				std::cout << truncate(getContact(j).getLastName()) << "|";
			else if ( i == 2)
				std::cout << truncate(getContact(j).getNickName()) << "|";
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
	std::cout << "First Name: " << getContact(index).getFirstName() << std::endl;
	std::cout << "Last Name: " <<getContact(index).getLastName()  << std::endl;
	std::cout << "Nick Name: " << getContact(index).getNickName()  << std::endl;
	std::cout << "Phone Number: " << getContact(index).getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << getContact(index).getSecret() << std::endl;
}