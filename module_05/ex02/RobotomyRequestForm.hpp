#pragma once

#include "Form.hpp"

#include <fstream>
#include <cstdlib>
#include <ctime> 


class RobotomyRequestForm: public Form
{
	public:

		/* ============== ~ constructors / destructors ~ ============== */
		RobotomyRequestForm(const std::string &target, bool verbose);
		~RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm & operator = (const RobotomyRequestForm &rhs);

		/* ============== ~ member functions ~ ============== */
		void		execute(const Bureaucrat &executor) const;
		std::string	target(void) const;
		static void	displayMessage(std::string message, std::string color);

	private:
		RobotomyRequestForm(void);
		std::string _target;
};

std::ostream & operator << (std::ostream &os, const RobotomyRequestForm &rhs);
