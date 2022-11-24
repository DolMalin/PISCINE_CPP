#pragma once

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		size_t	_len;
		
	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		std::string	askInfo(std::string str);
		size_t		askUserIndex();
		std::string	askCommand();

		void		setContact(size_t index);
		void		printContacts(void);
		void		printContact(size_t index);
		
		Contact		contact(size_t index);
		size_t		len(void);
};
