#include "PhoneBook.hpp"
#include <string>

int	main(void)
{
	PhoneBook	repertory;
	std::string	command;

	while(!std::cin.eof())
	{
		command = repertory.askCommand();
		if (command == "ADD")
		{
			if (repertory.len() == 8)
				repertory.setContact(0);
			else
				repertory.setContact(repertory.len());
		}
		else if (command == "SEARCH")
		{
			if (repertory.len() == 0)
				continue;
			repertory.printContacts();
			repertory.printContact(repertory.askUserIndex());
		}
		else if (command == "EXIT")
			break ;
	}
	return 0;
}
