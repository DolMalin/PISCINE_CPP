#include "RobotomyRequestForm.hpp"

/* ========================================================================== */
/*                                                                            */
/*                       ~ constructors / destructors ~                       */
/*                                                                            */
/* ========================================================================== */

RobotomyRequestForm::RobotomyRequestForm(const std::string &target, bool verbose)
	:Form("RobotomyRequest", 72, 45, verbose),
	_target(target)
{
	if (_verbose)
		displayMessage("Constructor with arguments called", ROBOTOMY_REQUEST_COLOR);
}


RobotomyRequestForm::	~RobotomyRequestForm(void)
{
	if (_verbose)
		displayMessage("Destructor called", ROBOTOMY_REQUEST_COLOR);
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	:Form("RobotomyRequest", 72, 45, false) 
{
	if (_verbose)
		displayMessage("Copy constructor called", ROBOTOMY_REQUEST_COLOR);
		
	*this = src;
}


RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm &rhs)
{
	if (_verbose)
		displayMessage("Copy assignment constructor called", ROBOTOMY_REQUEST_COLOR);
	_target = rhs.target();
	_verbose = rhs._verbose;

	return *this;
}


/* ========================================================================== */
/*                                                                            */
/*                             ~ member functions ~                           */
/*                                                                            */
/* ========================================================================== */

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	try
	{
		Form::isExecutable(executor);
		displayMessage(std::string("has been executed by " + executor.name()), ROBOTOMY_REQUEST_COLOR);

		srand((unsigned)time(0));
		if (rand() < RAND_MAX / 2)
			displayMessage(std::string("* Drill noises *: " + target() + " has been robotomized"), ROBOTOMY_REQUEST_COLOR);
		else
			displayMessage(std::string("* Drill noises *:  robotomy failed, " + target() + " is still self-aware"), ROBOTOMY_REQUEST_COLOR);
	}
	catch(const std::exception &e)
	{
		std::cerr << BOLD << ERR_COLOR << "[RobotomyRequestForm]" << END << " Can't be executed ("<< e.what() << ")" << '\n';
	}
}


std::string RobotomyRequestForm::target(void) const
{
	return _target;
}



void RobotomyRequestForm::displayMessage(std::string message, std::string color)
{
    std::cout << color + BOLD + "[RobotomyRequestForm] " + END + message << std::endl;   
}


/* ========================================================================== */
/*                                                                            */
/*                            ~ operator overload ~                           */
/*                                                                            */
/* ========================================================================== */

std::ostream & operator << (std::ostream &os, const RobotomyRequestForm &rhs)
{
	os << BOLD << ROBOTOMY_REQUEST_COLOR << "[RobotomyRequestForm]" << END << BOLD <<" name: \'" << END<< rhs.name()
	<< "\', " << BOLD << "target: " << END << rhs.target()
	<< ", " << BOLD << "gradeToSign: " << END << rhs.gradeToSign()
	<< ", " << BOLD << "gradeToExecute: " <<  END << rhs.gradeToExecute()
	<< ", " << BOLD << "isSigned: " << END << (rhs.isSigned() ? "yes" : "no");

	return os;
}