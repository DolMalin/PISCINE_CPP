#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

# define ERR_COLOR "\x1B[31m"
# define BUREAUCRAT_COLOR "\x1B[36m"
# define END "\033[0m"

class Bureaucrat
{
    private:
        const std::string   _name;
        short              _grade;
        Bureaucrat();
    
    public:
        Bureaucrat(std::string name, short grade);
        ~Bureaucrat();
        // Bureaucrat(const Bureaucrat &src);
        // Bureaucrat & operator = (const Bureaucrat &rhs);


        /* ============== ~ exceptions ~ ============== */
        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Grade is too high");
                }
        };

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char *what() const throw()
                {
                    return ("Grade is too low");
                }
        };


};

std::ostream & operator<<(std::ostream &os, const Bureaucrat &rhs);