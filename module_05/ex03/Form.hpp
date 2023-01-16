#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <stdexcept>

#include "Bureaucrat.hpp"

# define ERR_COLOR "\x1B[31m"
# define FORM_COLOR "\x1B[35m"
# define ROBOTOMY_REQUEST_COLOR "\x1B[33m"
# define SHRUBBERY_CREATION_COLOR "\x1B[34m"
# define PRESIDENTIAL_PARDON_COLOR "\x1B[32m"
# define INTERN_COLOR "\x1B[30m"
# define BOLD "\033[1m"
# define END "\033[0m"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		bool				_isSigned;

	protected:
		bool				_verbose;

	public:

		/* ============== ~ constructors / destructors ~ ============== */
		Form(void);
		Form(std::string name, int gradeToSign, int gradeToExecute, bool verbose);
		virtual ~Form(void);
		Form(const Form &src);
		Form & operator = (const Form &rhs);


		/* ============== ~ member functions ~ ============== */
		const std::string	name(void) const;
		int					gradeToSign(void) const;
		int					gradeToExecute(void) const;
		bool				isSigned(void) const;

		void				beSigned(const Bureaucrat &b);
		static void         displayMessage(std::string message, std::string color);
		void				isExecutable(const Bureaucrat &b) const;

		virtual void		execute(const Bureaucrat &executor) const = 0;

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

		class FormAlreadySignedException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

		class FormNotSignedException: public std::exception
		{
			public:
                virtual const char *what() const throw();
		};
};

std::ostream & operator << (std::ostream &os, const Form &rhs);

#endif