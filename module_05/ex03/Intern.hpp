#pragma once

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern
{
	private:
		bool _verbose;
		Intern();

	public:
		/* ============== ~ constructors / destructors ~ ============== */
		Intern(bool verbose);
		~Intern(void);
		Intern(const Intern &src);
		Intern & operator = (const Intern &rhs);

		/* ============== ~ member functions ~ ============== */
		Form 		*makeForm(std::string name, std::string target);
		static void	displayMessage(std::string message, std::string color);


		/* ============== ~ exceptions ~ ============== */
        class InvalidFormNameException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};