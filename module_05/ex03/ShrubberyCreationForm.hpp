#pragma once

#include "Form.hpp"

#include <fstream>

class ShrubberyCreationForm: public Form
{
	public:
	
		/* ============== ~ constructors / destructors ~ ============== */
		ShrubberyCreationForm(const std::string &target, bool verbose);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm & operator = (const ShrubberyCreationForm &rhs);

		/* ============== ~ member functions ~ ============== */
		void		execute(const Bureaucrat &executor) const;
		std::string	target(void) const;
		static void	displayMessage(std::string message, std::string color);


	private:
		ShrubberyCreationForm(void);
		std::string _target;
};

std::ostream & operator << (std::ostream &os, const ShrubberyCreationForm &rhs);