#include "ShrubberyCreationForm.hpp"

/* ========================================================================== */
/*                                                                            */
/*                       ~ constructors / destructors ~                       */
/*                                                                            */
/* ========================================================================== */

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target, bool verbose)
	:Form("ShrubberyCreation", 145, 137, verbose),
	_target(target)
{
	if (_verbose)
		displayMessage("Constructor with arguments called", SHRUBBERY_CREATION_COLOR);
}


ShrubberyCreationForm::	~ShrubberyCreationForm(void)
{
	if (_verbose)
		displayMessage("Destructor called", SHRUBBERY_CREATION_COLOR);
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
	:Form("ShrubberyCreation", 145, 137, false) 
{
	if (_verbose)
		displayMessage("Copy constructor called", SHRUBBERY_CREATION_COLOR);
		
	*this = src;
}


ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm &rhs)
{
	if (_verbose)
		displayMessage("Copy assignment constructor called", SHRUBBERY_CREATION_COLOR);
	_target = rhs.target();
	_verbose = rhs._verbose;

	return *this;
}


/* ========================================================================== */
/*                                                                            */
/*                             ~ member functions ~                           */
/*                                                                            */
/* ========================================================================== */
void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	try
	{
		Form::isExecutable(executor);
		std::string filename = target() + "_shrubbery";
		std::ofstream ofs(filename.c_str());

		if (!ofs.is_open())
			throw std::ofstream::failure(strerror(errno));
		ofs << "     ccee88oo" << std::endl
		<< "  C8O8O8Q8PoOb o8oo" << std::endl
		<< " dOB69QO8PdUOpugoO9bD" << std::endl
		<< "CgggbU8OU qOp qOdoUOdcb" << std::endl
		<< "    6OuU  /p u gcoUodpP" << std::endl
		<< "      \\\\\\//  /douUP" << std::endl
		<< "        \\\\\\////" << std::endl
		<< "         |||/\\" << std::endl
		<< "         |||\\/" << std::endl
		<< "         |||||" << std::endl
		<< "   .....//||||\\...." << std::endl;
		
		ofs.close();
		displayMessage(std::string("has been executed by " + executor.name()), SHRUBBERY_CREATION_COLOR);
	}
	catch(const std::exception &e)
	{
		std::cerr << BOLD << ERR_COLOR << "[ShrubberyCreationForm]" << END << " Can't be executed ("<< e.what() << ")" << '\n';
	}
}


std::string ShrubberyCreationForm::target(void) const
{
	return _target;
}



void ShrubberyCreationForm::displayMessage(std::string message, std::string color)
{
    std::cout << color + BOLD + "[ShrubberyCreationForm] " + END + message << std::endl;   
}


/* ========================================================================== */
/*                                                                            */
/*                            ~ operator overload ~                           */
/*                                                                            */
/* ========================================================================== */

std::ostream & operator << (std::ostream &os, const ShrubberyCreationForm &rhs)
{
	os << BOLD << SHRUBBERY_CREATION_COLOR << "[ShrubberyCreationForm]" << END << BOLD <<" name: \'" << END<< rhs.name()
	<< "\', " << BOLD << "target: " << END << rhs.target()
	<< ", " << BOLD << "gradeToSign: " << END << rhs.gradeToSign()
	<< ", " << BOLD << "gradeToExecute: " <<  END << rhs.gradeToExecute()
	<< ", " << BOLD << "isSigned: " << END << (rhs.isSigned() ? "yes" : "no");

	return os;
}