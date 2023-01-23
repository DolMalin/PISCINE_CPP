#include "Bureaucrat.hpp"

/* ========================================================================== */
/*                                                                            */
/*                       ~ constructors / destructors ~                       */
/*                                                                            */
/* ========================================================================== */

Bureaucrat::Bureaucrat(): _name("Acting Head"), _grade(150)
{
    displayMessage("default constructor called", BUREAUCRAT_COLOR);
}


Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
    displayMessage("constructor with name and grade called", BUREAUCRAT_COLOR);
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}


Bureaucrat::~Bureaucrat()
{
    displayMessage("destructor called", BUREAUCRAT_COLOR);
}


Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.name())
{
    displayMessage("copy constructor called", BUREAUCRAT_COLOR);
    _grade = src._grade;
}


Bureaucrat & Bureaucrat::operator = (const Bureaucrat &rhs)
{
    displayMessage("copy assignment constructor called (_name is const  and can't be overwritten within `=` overload)", BUREAUCRAT_COLOR);
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
    return ("Grade is too high");
}


const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}


