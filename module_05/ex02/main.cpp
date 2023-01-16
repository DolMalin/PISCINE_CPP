#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


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
            ShrubberyCreationForm f("42Lyon", verbose);


            std::cout << b << std::endl;
            std::cout << f << std::endl;

            f.execute(b);

            b.signForm(f);
            f.execute(b);

            std::cout << f << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << ERR_COLOR << "[Main]" << END << "Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }


	/* ============== ~ TEST #2 ~ ============== */
    {
        try
        {
            displayTest(2,
                "name: \'Bernard Arnault\', grade: 138\nname: \'ShrubberyCreation\', target:LVMHOffice, gradeToSign: 145, gradeToExecute: 137"
            );
            Bureaucrat b("Bernard Arnault", 138, verbose);
            ShrubberyCreationForm f("LVMHOffice", verbose);


            std::cout << b << std::endl;
            std::cout << f << std::endl;

            f.execute(b);

            b.signForm(f);
            f.execute(b);

            std::cout << f << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << ERR_COLOR << "[Main]" << END << "Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }

    /* ============== ~ TEST #3 ~ ============== */
    {
        try
        {
            displayTest(3,
                "name: \'Cyril Hannouna\', grade: 146\nname: \'ShrubberyCreation\', target:Fouquettes, gradeToSign: 145, gradeToExecute: 137"
            );
            Bureaucrat b("Cyril Hannouna", 146, verbose);
            ShrubberyCreationForm f("Fouquettes", verbose);


            std::cout << b << std::endl;
            std::cout << f << std::endl;

            f.execute(b);

            b.signForm(f);
            f.execute(b);

            std::cout << f << std::endl;
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
                "name: \'Xavier Niel\', grade: 1\nname: \'RobotomyRequest\', target:'Kwame Yamgnane', gradeToSign: 145, gradeToExecute: 137"
            );
            Bureaucrat b("Xavier Niel", 1, verbose);
            RobotomyRequestForm f("Kwame Yamgnane", verbose);


            std::cout << b << std::endl;
            std::cout << f << std::endl;

            f.execute(b);

            b.signForm(f);
            f.execute(b);

            std::cout << f << std::endl;
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
            Bureaucrat b("Bernard Arnault", 44, verbose);
            RobotomyRequestForm f("Serge Dassault", verbose);


            std::cout << b << std::endl;
            std::cout << f << std::endl;

            f.execute(b);

            b.signForm(f);
            f.execute(b);

            std::cout << f << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << ERR_COLOR << "[Main]" << END << "Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }

    /* ============== ~ TEST #6 ~ ============== */
    {
        try
        {
            displayTest(6,
                "name: \'Cyril Hannouna\', grade: 46\nname: \'RobotomyRequest\', target:'Vincent Bolloré', gradeToSign: 72, gradeToExecute: 45"
            );
            Bureaucrat b("Cyril Hannouna", 46, verbose);
            RobotomyRequestForm f("Vincent Bolloré", verbose);


            std::cout << b << std::endl;
            std::cout << f << std::endl;

            f.execute(b);

            b.signForm(f);
            f.execute(b);

            std::cout << f << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << ERR_COLOR << "[Main]" << END << "Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }


    /* ============== ~ TEST #7 ~ ============== */
    {
        try
        {
            displayTest(7,
                "name: \'Xavier Niel\', grade: 1\nname: \'PresidentialPardon\', target:'Nicolas Sadirac', gradeToSign: 25, gradeToExecute: 5"
            );
            Bureaucrat b("Xavier Niel", 1, verbose);
            PresidentialPardonForm f("Nicolas Sadirac", verbose);


            std::cout << b << std::endl;
            std::cout << f << std::endl;

            f.execute(b);

            b.signForm(f);
            f.execute(b);

            std::cout << f << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << ERR_COLOR << "[Main]" << END << "Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }

    /* ============== ~ TEST #8 ~ ============== */
    {
        try
        {
            displayTest(8,
                "name: \'Bernard Arnault\', grade: 1\nname:\'Vincent Bolloré\', grade: 1\nname: \'PresidentialPardon\', target:'Michel Houellebecq', gradeToSign: 25, gradeToExecute: 5"
            );
            Bureaucrat b1("Xavier Niel", 1, verbose);
            Bureaucrat b2("Vincent Bolloré", 1, verbose);

            PresidentialPardonForm f("Michel Houellebecq", verbose);


            std::cout << b1 << std::endl;
            std::cout << b2 << std::endl;

            std::cout << f << std::endl;

            f.execute(b1);
            b1.signForm(f);
            b2.signForm(f);
            f.execute(b2);

            std::cout << f << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << ERR_COLOR << "[Main]" << END << "Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }

}