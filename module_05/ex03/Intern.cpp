#include "Intern.hpp"

/* ========================================================================== */
/*                                                                            */
/*                       ~ constructors / destructors ~                       */
/*                                                                            */
/* ========================================================================== */

Intern::Intern(bool verbose): _verbose(verbose)
{
	if (verbose)
		displayMessage("Constructor with arguments called", INTERN_COLOR);
}


Intern::~Intern(void)
{
	if (_verbose)
		displayMessage("Destructor called", INTERN_COLOR);
}


Intern::Intern(const Intern &src): _verbose(src._verbose)
{
	if (_verbose)
		displayMessage("Copy constructor called", INTERN_COLOR);

	*this = src;
}


Intern &Intern::operator = (const Intern &rhs)
{
	if (_verbose)
		displayMessage("Copy assignment constructor called", INTERN_COLOR);
	_verbose = rhs._verbose;

	return *this;
}


/* ========================================================================== */
/*                                                                            */
/*                             ~ member functions ~                           */
/*                                                                            */
/* ========================================================================== */

Form *Intern::makeForm(std::string name, std::string target)
{
	std::string formList[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	int i = 0;

	while (i < 3 && name != formList[i])
		i++;
	switch (i)
	{
		case 0:
			displayMessage("created a Shrubbery Creation form", INTERN_COLOR);
			return new ShrubberyCreationForm(target, _verbose);
		case 1:
			displayMessage("created a Robotomy Request form", INTERN_COLOR);
			return new RobotomyRequestForm(target, _verbose);
		case 2:
			displayMessage("created a Presidential Pardon form", INTERN_COLOR);
			return new PresidentialPardonForm(target, _verbose);	
		default:
			throw Intern::InvalidFormNameException();		
	}

}


void Intern::displayMessage(std::string message, std::string color)
{
    std::cout << color + BOLD + "[Intern] " + END + message << std::endl;   
}


/* ========================================================================== */
/*                                                                            */
/*                                ~ exceptions ~                              */
/*                                                                            */
/* ========================================================================== */

const char *Intern::InvalidFormNameException::what() const throw()
{
	return ("invalid form name");
}
