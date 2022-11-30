#include "Harl.hpp"

Harl::Harl(void)
{
	_functions[0] = &Harl::_debug;
	_functions[1] = &Harl::_info;
	_functions[2] = &Harl::_warning;
	_functions[3] = &Harl::_error;

	_levels[0] = "DEBUG";
	_levels[1] = "INFO";
	_levels[2] = "WARNING";
	_levels[3] = "ERROR";
}


void Harl::_debug(void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month" << std::endl;
}

void Harl::_error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == _levels[i])
		{
			(void)(this->*_functions[i])();
			return ;
		}
	}
}