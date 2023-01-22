#include "Bureaucrat.hpp"
#include "Form.hpp"

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
                "name: \'Xavier Niel\', grade: 1\nname: \'Destroy Humankind\', gradeToSign: 150, gradeToExecute: 1"
            );
            Bureaucrat b("Xavier Niel", 1, verbose);
            Form       f("Destroy Humankind", 150, 1, verbose);

            std::cout << b << std::endl;
            std::cout << f << std::endl;

            b.signForm(f);
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
            displayTest(2, "name: \'Xavier Niel\', grade: 2\nname: \'Open 42Limoges\', gradeToSign: 1, gradeToExecute: 1");
            Bureaucrat b("Xavier Niel", 2, verbose);
            Form       f("Open 42Limoges", 1, 1, verbose);

            std::cout << b << std::endl;
            std::cout << f << std::endl;

            b.signForm(f);
            std::cout << f << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << BOLD << ERR_COLOR << "[Main] " << END << "Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }


	/* ============== ~ TEST #3 ~ ============== */
    {
        try
        {
            displayTest(3,"name: \'Buy Mediapart\', gradeToSign: 0, gradeToExecute: 1");
            Form       f("Buy Mediapart", 0, 1, verbose);

            std::cout << f << std::endl;

            std::cout << f << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << BOLD << ERR_COLOR << "[Main] " << END << "Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }


	/* ============== ~ TEST #4 ~ ============== */
    {
        try
        {
            displayTest(4,"name: \'Buy Liberation\', gradeToSign: 151, gradeToExecute: 1");
            Form       f("Buy Liberation", 151, 1, verbose);

            std::cout << f << std::endl;

            std::cout << f << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << BOLD << ERR_COLOR << "[Main] " << END << "Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }


	/* ============== ~ TEST #5 ~ ============== */
    {
        try
        {
            displayTest(5,"name: \'Buy Liberation\', gradeToSign: 1, gradeToExecute: 151");
            Form       f("Buy Liberation", 1, 151, verbose);

            std::cout << f << std::endl;

            std::cout << f << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << BOLD << ERR_COLOR << "[Main] " << END << "Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }


	/* ============== ~ TEST #6 ~ ============== */
    {
        try
        {
            displayTest(6,"name: \'Buy Liberation\', gradeToSign: 1, gradeToExecute: 0");
            Form       f("Buy Liberation", 1, 0, verbose);

            std::cout << f << std::endl;

            std::cout << f << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << BOLD << ERR_COLOR << "[Main] " << END << "Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }


	/* ============== ~ TEST #7 ~ ============== */
    {
        try
        {
            displayTest(7, "name: \'Bernard Arnault\', grade: 1\nname: \'Vincent Bolloré\', grade:1\nname: \'Buy Mediapart\', gradeToSign: 1, gradeToExecute: 1");
            Bureaucrat b1("Bernard Arnault", 1, verbose);
            Bureaucrat b2("Vincent Bolloré", 1, verbose);

            Form       f("Buy Mediapart", 1, 1, verbose);

            std::cout << b1 << std::endl;
            std::cout << b2 << std::endl;
            std::cout << f << std::endl;

            b1.signForm(f);
            std::cout << f << std::endl;

            b2.signForm(f);
            std::cout << f << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << BOLD << ERR_COLOR << "[Main] " << END << "Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }


	/* ============== ~ TEST #8 ~ ============== */
    {
        try
        {
            displayTest(8, "name: \'Bernard Arnault\', grade: 3\nname: \'Buy Mediapart\', gradeToSign: 1, gradeToExecute: 1");
            Bureaucrat b1("Bernard Arnault", 3, verbose);

            Form       f("Buy Mediapart", 1, 1, verbose);

            std::cout << b1 << std::endl;
            std::cout << f << std::endl;

            b1.upgrade();
            b1.upgrade();
            b1.signForm(f);
            std::cout << f << std::endl;

        }
        catch(const std::exception& e)
        {
            std::cerr << BOLD << ERR_COLOR << "[Main] " << END << "Can't instantiate class ("<< e.what() << ")" << '\n';
        }
    }

}