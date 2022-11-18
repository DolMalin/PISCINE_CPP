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
		void		setContact(size_t index);
		Contact		getContact(size_t index);
		size_t		getLen(void);
};
