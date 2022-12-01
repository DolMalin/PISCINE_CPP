#pragma once

#include <string>
#include <iostream>

class Harl 
{
	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);

		std::string 		_levels[4];
		void		(Harl::	*_functions[4])(void);

	public:
		Harl();
		void complain(std::string level);
};