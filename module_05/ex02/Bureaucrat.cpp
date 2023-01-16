#include "Bureaucrat.hpp"

/* ========================================================================== */
/*                                                                            */
/*                       ~ constructors / destructors ~                       */
/*                                                                            */
/* ========================================================================== */

Bureaucrat::Bureaucrat(): _name("Acting Head"), _grade(150), _verbose(true)
{
    if (_verbose)
      displayMessage("Default constructor called", BUREAUCRAT_COLOR);
}


Bureaucrat::Bureaucrat(const std::string name, int grade, bool verbose): _name(name), _grade(grade), _verbose(verbose)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (_verbose)
        displayMessage("Constructor with arguments called", BUREAUCRAT_COLOR);
}


Bureaucrat::~Bureaucrat()
{
    if (_verbose)
        displayMessage("Destructor called", BUREAUCRAT_COLOR);
}


Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.name())
{
    if (_verbose)
        displayMessage("Copy constructor called", BUREAUCRAT_COLOR);
    _grade = src._grade;
}


Bureaucrat & Bureaucrat::operator = (const Bureaucrat &rhs)
{
    if (_verbose)
        displayMessage("Copy assignment constructor called (_name is const and can't be overwritten within `=` overload)", BUREAUCRAT_COLOR);
    _grade = rhs._grade;
    return *this;
}

/* ========================================================================== */
/*                                                                            */
/*                             ~ member functions ~                           */
/*                                                                            */
/* ========================================================================== */

const std::string Bureaucrat::name(void) const
{
    return _name;
}


int Bureaucrat::grade(void) const
{
    return _grade;
}


void Bureaucrat::upgrade(void)
{
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    else
        _grade--;
}


void Bureaucrat::downgrade(void)
{
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    else
        _grade++;
}


void Bureaucrat::signForm(Form &f)
{
    try
    {
        f.beSigned(*this);
        displayMessage(std::string(
            _name + " signed the " + f.name() + " form"
        ), BUREAUCRAT_COLOR);
    }
    catch(const std::exception& e)
    {
        displayMessage(std::string(
            _name + " couldn't sign the " + f.name() + " form ("  + e.what() + ")"
        ), ERR_COLOR);
    }
    
}


void Bureaucrat::displayMessage(std::string message, std::string color)
{
    std::cout << color + BOLD + "[Bureaucrat] " + END + message << std::endl;   
}

/* ========================================================================== */
/*                                                                            */
/*                            ~ operator overload ~                           */
/*                                                                            */
/* ========================================================================== */

std::ostream &operator << (std::ostream &os, const Bureaucrat &rhs)
{
	os << BOLD << BUREAUCRAT_COLOR << "[Bureaucrat]" << END 
    << BOLD << " name: " "\'" << END << rhs.name()
    << "\', " << BOLD <<"grade: " << END << rhs.grade();
	return os;
}

/* ========================================================================== */
/*                                                                            */
/*                                ~ exceptions ~                              */
/*                                                                            */
/* ========================================================================== */

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("grade is too high");
}


const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("grade is too low");
}


