#include "PhoneBook.hpp"
#include <string>

static std::string	getCommand(void)
{
	std::string  command;
	
	command = "";
	while (command.empty() && !std::cin.eof())
	{
		std::cout << std::endl << "=====================================" << std::endl;
		std::cout << "Enter a command [ADD - SEARCH - EXIT]: ";
		std::getline(std::cin, command);
		std::cout << "=====================================" << std::endl;
	}
	return  command;
}

static size_t	getUserIndex(size_t n)
{
	std::string  command;
	
	command = "";
	while (command.empty() && !std::cin.eof())
	{
		std::cout << std::endl << "=====================================" << std::endl;
		std::cout << "Enter a contact index [";
		for(size_t i = 0; i < n; i++)
		{
			std::cout << i;
			if (i < n - 1)
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

int	main(void)
{
	PhoneBook	repertory;
	std::string	command;

	while(!std::cin.eof())
	{
		command = getCommand();
		if (command == "ADD")
		{
			if (repertory.getLen() == 8)
				repertory.setContact(0);
			else
				repertory.setContact(repertory.getLen());
		}
		else if (command == "SEARCH")
		{
			repertory.printContacts();
			repertory.printContact(getUserIndex(repertory.getLen()));
		}
		else if (command == "EXIT")
			break ;
	}
	return EXIT_SUCCESS;
}
