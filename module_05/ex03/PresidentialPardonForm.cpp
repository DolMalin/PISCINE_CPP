#include "PresidentialPardonForm.hpp"


/* ========================================================================== */
/*                                                                            */
/*                       ~ constructors / destructors ~                       */
/*                                                                            */
/* ========================================================================== */

PresidentialPardonForm::PresidentialPardonForm(const std::string &target, bool verbose)
	:Form("PresidentialPardon", 25, 5, verbose),
	_target(target)
{
	if (_verbose)
		displayMessage("Constructor with arguments called", PRESIDENTIAL_PARDON_COLOR);
}


PresidentialPardonForm::~PresidentialPardonForm(void)
{
	if (_verbose)
		displayMessage("Destructor called", PRESIDENTIAL_PARDON_COLOR);
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
	:Form("PresidentialPardon", 25, 5, false) 
{
	if (_verbose)
		displayMessage("Copy constructor called", PRESIDENTIAL_PARDON_COLOR);
		
	*this = src;
}


PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm &rhs)
{
	if (_verbose)
		displayMessage("Copy assignment constructor called", PRESIDENTIAL_PARDON_COLOR);
	_target = rhs.target();
	_verbose = rhs._verbose;

	return *this;
}


/* ========================================================================== */
/*                                                                            */
/*                             ~ member functions ~                           */
/*                                                                            */
/* ========================================================================== */

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	try
	{
		Form::isExecutable(executor);
		displayMessage(std::string("has been executed by " + executor.name()), PRESIDENTIAL_PARDON_COLOR);
		displayMessage(std::string(target() + " has been pardoned by Zaphod Beeblebrox"), PRESIDENTIAL_PARDON_COLOR);
	}
	catch(const std::exception &e)
	{
		std::cerr << BOLD << ERR_COLOR << "[PresidentialPardonForm]" << END << " Can't be executed ("<< e.what() << ")" << '\n';
	}
}


std::string PresidentialPardonForm::target(void) const
{
	return _target;
}



void PresidentialPardonForm::displayMessage(std::string message, std::string color)
{
    std::cout << color + BOLD + "[PresidentialPardonForm] " + END + message << std::endl;   
}


/* ========================================================================== */
/*                                                                            */
/*                            ~ operator overload ~                           */
/*                                                                            */
/* ========================================================================== */

std::ostream & operator << (std::ostream &os, const PresidentialPardonForm &rhs)
{
	os << BOLD << PRESIDENTIAL_PARDON_COLOR << "[PresidentialPardonForm]" << END << BOLD <<" name: \'" << END<< rhs.name()
	<< "\', " << BOLD << "target: " << END << rhs.target()
	<< ", " << BOLD << "gradeToSign: " << END << rhs.gradeToSign()
	<< ", " << BOLD << "gradeToExecute: " <<  END << rhs.gradeToExecute()
	<< ", " << BOLD << "isSigned: " << END << (rhs.isSigned() ? "yes" : "no");

	return os;
}