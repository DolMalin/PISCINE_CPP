#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, short grade): _name(name)
{
    std::cout << BUREAUCRAT_COLOR << "[Bureaucrat]: constructor called" << END <<std::endl;
    try
    {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else
            _grade = grade;
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << ERR_COLOR << e.what() << END <<std::endl;
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << ERR_COLOR << e.what() << END << std::endl;
    }
    
}

Bureaucrat::~Bureaucrat()
{
    std::cout << BUREAUCRAT_COLOR << "[Bureaucrat]: destructor called" << END << std::endl;
}

std::ostream &operator << (std::ostream &os, const Bureaucrat &rhs)
{
	os << "";
	return os;
}