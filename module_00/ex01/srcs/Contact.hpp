/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdal-mol <dolmalinn@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:21:14 by pdal-mol          #+#    #+#             */
/*   Updated: 2022/04/11 18:31:14 by pdal-mol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

# define FIELDS_LEN		5

# define FIRST_NAME 	0
# define LAST_NAME		1
# define NICK_NAME		2
# define PHONE_NUMBER	3
# define DARKEST_SECRET	4

class Contact {
	
	public:
		Contact(void);
		~Contact(void);
		void		set(void);
		std::string	get_info(int type);
		
	private:
		std::string infos[FIELDS_LEN];
};

#endif
