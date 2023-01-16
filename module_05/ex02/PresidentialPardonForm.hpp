#pragma once

#include "Form.hpp"

class PresidentialPardonForm: public Form
{
	public:

		/* ============== ~ constructors / destructors ~ ============== */
		PresidentialPardonForm(const std::string &target, bool verbose);
		~PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm & operator = (const PresidentialPardonForm &rhs);

		/* ============== ~ member functions ~ ============== */
		void		execute(const Bureaucrat &executor) const;
		std::string	target(void) const;
		static void	displayMessage(std::string message, std::string color);

	private:
		PresidentialPardonForm(void);
		std::string _target;
};

std::ostream & operator << (std::ostream &os, const PresidentialPardonForm &rhs);
