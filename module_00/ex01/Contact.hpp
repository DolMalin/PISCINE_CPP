#pragma once

#include <iostream>

class Contact {
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _secret;
	
	public:
		Contact(void);
		~Contact(void);
		
		void	setFirstName(std::string str);
		void	setLastName(std::string str);
		void	setNickName(std::string str);
		void	setPhoneNumber(std::string str);
		void	setSecret(std::string str);

		std::string	firstName(void);
		std::string	lastName(void);
		std::string	nickName(void);
		std::string	phoneNumber(void);
		std::string	secret(void);
		
};

