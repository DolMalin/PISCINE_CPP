#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


static void displayTest(int testNumber, std::string testContent)
{
    std::cout << std::endl << BOLD << "======================================================================================" << std::endl;
    std::cout << "TEST #" << testNumber << END << std::endl;
    std::cout << testContent << std::endl;
    std::cout << BOLD <<"======================================================================================" << END << std::endl;
}

int main(void)
{
    bool verbose;
	std::string buffer;

	buffer = "";
	while (buffer.empty() && !std::cin.eof() && (buffer != "y" || buffer != "n"))
	{
		std::cout << "Verbose? [y/n]: ";
		std::getline(std::cin, buffer);
	}
    
    if (buffer == "y")
        verbose = true;
    else
        verbose = false;


	/* ============== ~ TEST #1 ~ ============== */
    {
        try
        {
            displayTest(1,
                "name: \'Xavier Niel\', grade: 1\nname: \'ShrubberyCreation\', target:42Lyon, gradeToSign: 145, gradeToExecute: 137"
            );
            std::cout << std::endl << BOLD << "Run this command to check permissions : `chmod 000 42Lyon_shrubbery && ./bureaucrat`" << std::endl << std::endl;

            Bureaucrat b("Xavier Niel", 1, verbose);
            Intern i(verbose);


            Form *f = i.makeForm("shrubbery creation", "42Lyon");


            std::cout << b << std::endl;
            std::cout << *f << std::endl;

            f->execute(b);

            b.signForm(*f);
            f->execute(b);

            std::cout << *f << std::endl;

            delete f;
        }
        catch(const std::exception& e)
        {
            std::cerr << BOLD << ERR_COLOR << "[Main]" << END << " Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }


	/* ============== ~ TEST #2 ~ ============== */
    {
        try
        {
            displayTest(2,
                "name: \'Xavier Niel\', grade: 1\nname: \'qweoiqwoei\', target:42Lyon, gradeToSign: 145, gradeToExecute: 137"
            );

            Bureaucrat b("Xavier Niel", 1, verbose);
            Intern i(verbose);


            Form *f = i.makeForm("qweoiqwoei", "42Lyon");


            std::cout << b << std::endl;
            std::cout << *f << std::endl;

            f->execute(b);

            b.signForm(*f);
            f->execute(b);

            std::cout << *f << std::endl;

            delete f;
        }
        catch(const std::exception& e)
        {
            std::cerr << BOLD << ERR_COLOR << "[Main]" << END << " Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }


	/* ============== ~ TEST #3 ~ ============== */
    {
        try
        {
            displayTest(3,
                "name: \'Xavier Niel\', grade: 1\nname: \'RobotomyRequest\', target:'Kwame Yamgnane', gradeToSign: 145, gradeToExecute: 137"
            );
            Bureaucrat b("Xavier Niel", 1, verbose);
            Intern i(verbose);

            Form *f = i.makeForm("robotomy request", "Kwame Yamgnane");

            std::cout << b << std::endl;
            std::cout << *f << std::endl;

            f->execute(b);

            b.signForm(*f);
            f->execute(b);

            std::cout << *f << std::endl;

            delete f;

        }
        catch(const std::exception& e)
        {
            std::cerr << ERR_COLOR << "[Main]" << END << "Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }

	/* ============== ~ TEST #4 ~ ============== */
    {
        try
        {
            displayTest(4,
                "name: \'Xavier Niel\', grade: 1\nname: \'PresidentialPardon\', target:'Nicolas Sadirac', gradeToSign: 25, gradeToExecute: 5"
            );
            Bureaucrat  b("Xavier Niel", 1, verbose);
            Intern      i(verbose);

            Form *f = i.makeForm("presidential pardon","Nicolas Sadirac");


            std::cout << b << std::endl;
            std::cout << *f << std::endl;

            f->execute(b);

            b.signForm(*f);
            f->execute(b);

            std::cout << *f << std::endl;

            delete f;

        }
        catch(const std::exception& e)
        {
            std::cerr << ERR_COLOR << "[Main]" << END << "Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }


	/* ============== ~ TEST #5 ~ ============== */
    {
        try
        {
            displayTest(5,
                "name: \'Bernard Arnault\', grade: 44\nname: \'RobotomyRequest\', target:'Serge Dassault' , gradeToSign: 72, gradeToExecute: 45"
            );
            Bureaucrat  b("Bernard Arnault", 44, verbose);
            Intern      i(verbose);

            Form *f = i.makeForm("robotomy request", "Serge Dassault");

            std::cout << b << std::endl;
            std::cout << *f << std::endl;

            f->execute(b);

            b.signForm(*f);
            f->execute(b);

            std::cout << *f << std::endl;

            delete f;
        }
        catch(const std::exception& e)
        {
            std::cerr << ERR_COLOR << "[Main]" << END << "Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }
    
}