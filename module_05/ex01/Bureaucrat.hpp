#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include "Form.hpp"

# define ERR_COLOR "\x1B[31m"
# define BUREAUCRAT_COLOR "\x1B[36m"
# define BOLD "\033[1m"
# define END "\033[0m"

class Form;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
        bool                _verbose;
    
    public:

        /* ============== ~ constructors / destructors ~ ============== */
        Bureaucrat();
        Bureaucrat(std::string name, int grade, bool verbose);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat & operator = (const Bureaucrat &rhs);

        /* ============== ~ member functions ~ ============== */
        const std::string   name(void) const;
        int                 grade(void) const;

        void                upgrade(void);
        void                downgrade(void);
        void                signForm(Form &f);

        static void         displayMessage(std::string message, std::string color);


        /* ============== ~ exceptions ~ ============== */
        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };


};

std::ostream & operator<<(std::ostream &os, const Bureaucrat &rhs);