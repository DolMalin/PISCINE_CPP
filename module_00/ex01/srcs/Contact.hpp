/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:21:14 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/11/17 12:25:02 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
	
	public:
		Contact(void);
		~Contact(void);
		
		void		setFirstName(std::string str);
		void		setLastName(std::string str);
		void		setNickName(std::string str);
		void		setPhoneNumber(std::string str);
		void		setSecret(std::string str);

		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickName(void);
		std::string	getPhoneNumber(void);
		std::string	getSecret(void);
		
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _secret;
};

#endif
