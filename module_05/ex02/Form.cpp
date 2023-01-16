#include "Form.hpp"

/* ========================================================================== */
/*                                                                            */
/*                       ~ constructors / destructors ~                       */
/*                                                                            */
/* ========================================================================== */

Form::Form(void):
	_name("molluscs reproduction survey"),
	_gradeToSign(150), 
	_gradeToExecute(150),
	_isSigned(false),
	_verbose(true)
{
	if (_verbose)
		displayMessage("Default constructor called", FORM_COLOR);
}


Form::~Form(void)
{
	if (_verbose)
		displayMessage("Destructor called", FORM_COLOR);
}


Form::Form(std::string name, int gradeToSign, int gradeToExecute, bool verbose):
	_name(name),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute),
	_isSigned(false),
	_verbose(verbose)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else if (_verbose)
		displayMessage("Constructor with arguments called", FORM_COLOR);
}


Form::Form(const Form &src):
	_name(src.name()),
	_gradeToSign(src.gradeToSign()),
	_gradeToExecute(src.gradeToExecute())
{
	if (_verbose)
		displayMessage("Copy constructor called", FORM_COLOR);
	*this = src;
}

Form & Form::operator = (const Form &rhs)
{
	if (_verbose)
    	displayMessage("copy assignment constructor called (_name, _gradeToSign and _gradeToExecute are const and can't be overwritten within `=` overload)", BUREAUCRAT_COLOR);

	_isSigned = rhs._isSigned;
	return *this;
}

/* ========================================================================== */
/*                                                                            */
/*                             ~ member functions ~                           */
/*                                                                            */
/* ========================================================================== */

const std::string Form::name(void) const
{
	return _name;
}


int Form::gradeToSign(void) const
{
	return _gradeToSign;
}


int Form::gradeToExecute(void) const
{
	return _gradeToExecute;
}


bool Form::isSigned(void) const
{
	return _isSigned;
}


void Form::beSigned(const Bureaucrat &b)
{
	if (b.grade() <= _gradeToSign)
	{
		if (_isSigned)
			throw Form::FormAlreadySignedException();
		else
			_isSigned = true;
	}
	else
		throw Form::GradeTooLowException();
}


void Form::isExecutable(const Bureaucrat &b) const
{
	if (!isSigned())
		throw Form::FormNotSignedException();
	else if (b.grade() > gradeToExecute())
		throw Form::GradeTooLowException();
}


void Form::displayMessage(std::string message, std::string color)
{
    std::cout << color + BOLD + "[Form] " + END + message << std::endl;   
}

/* ========================================================================== */
/*                                                                            */
/*                            ~ operator overload ~                           */
/*                                                                            */
/* ========================================================================== */
std::ostream & operator << (std::ostream &os, const Form &rhs)
{
	os << BOLD << FORM_COLOR << "[Form]" << END << BOLD <<" name: \'" << END<< rhs.name()
	<< "\', " << BOLD << "gradeToSign: " << END << rhs.gradeToSign()
	<< ", " << BOLD << "gradeToExecute: " <<  END << rhs.gradeToExecute()
	<< ", " << BOLD << "isSigned: " << END << (rhs.isSigned() ? "yes" : "no");

	return os;
}

/* ========================================================================== */
/*                                                                            */
/*                                ~ exceptions ~                              */
/*                                                                            */
/* ========================================================================== */

const char *Form::GradeTooHighException::what() const throw()
{
    return ("grade is too high");
}


const char *Form::GradeTooLowException::what() const throw()
{
    return ("grade is too low");
}

const char *Form::FormAlreadySignedException::what() const throw()
{
	return ("form already signed");
}


const char *Form::FormNotSignedException::what() const throw()
{
	return ("form not signed");
}
