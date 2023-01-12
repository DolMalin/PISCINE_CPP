#include "Bureaucrat.hpp"

static void displayTest(int testNumber, std::string testContent)
{
    std::cout << std::endl << BOLD << "===================================================" << std::endl;
    std::cout << "TEST #" << testNumber << END << std::endl;
    std::cout << testContent << std::endl;
    std::cout << BOLD <<"===================================================" << END << std::endl;
}

int main(void)
{
    {
        displayTest(1, "name: \'Xavier Niel\', grade: 1");
        try
        {
            Bureaucrat b("Xavier Niel", 1);
            std::cout << b << std::endl;
        }
        catch(const std::exception &e)
        {
            Bureaucrat::displayMessage(e.what(), ERR_COLOR);
        }
    }


    {
        displayTest(2, "name: \'Vincent Bolloré\', grade: 0");
        try
        {
            Bureaucrat b("Vincent Bolloré", 0);
            std::cout << b << std::endl;
        }
        catch(const std::exception &e)
        {
            Bureaucrat::displayMessage(e.what(), ERR_COLOR);
        }
    }


    {
        displayTest(3, "name: \'Bernard Arnault\', grade: -1");
        try
        {
            Bureaucrat b("Bernard Arnault", -1);
            std::cout << b << std::endl;
        }
        catch(const std::exception &e)
        {
            Bureaucrat::displayMessage(e.what(), ERR_COLOR);
        }
    }


    {
        displayTest(4, "name: \'Cyril Hannouna\', grade: 151");
        try
        {
            Bureaucrat b("Cyril Hannouna", 151);
            std::cout << b << std::endl;
        }
        catch(const std::exception &e)
        {
            Bureaucrat::displayMessage(e.what(), ERR_COLOR);
        }
    }


    {
        displayTest(5, "name: \'Cyril Hannouna\', grade: 150");
        try
        {
            Bureaucrat b("Cyril Hannouna", 150);
            std::cout << b << std::endl << std::endl;

            Bureaucrat bClone1(b);
            std::cout << bClone1 << std::endl << std::endl;

            Bureaucrat bClone2;
            bClone2 = bClone1;
            std::cout << bClone2 << std::endl << std::endl;

            // Try to upgrade 2 times bClone1 (150 -> 148)
            std::cout << BOLD <<"* Try to upgrade 2 times bClone1 (150 -> 148) *" << END << std::endl;
            bClone1.upgrade();
            std::cout << bClone1 << std::endl;
            bClone1.upgrade();
            std::cout << bClone1 << std::endl << std::endl;

            // Try to downgrade bClone2 (150 -> 151)
            std::cout << BOLD <<"* Try to downgrade bClone2 (150 -> 151) *" << END << std::endl;

            bClone2.downgrade();
            std::cout << bClone2 << std::endl;
        }
        catch(const std::exception &e)
        {
            Bureaucrat::displayMessage(e.what(), ERR_COLOR);
        }
    }


    {
        displayTest(6, "name: \'Cyril Hannouna\', grade: 1");
        try
        {
            Bureaucrat b("Cyril Hannouna", 1);
            std::cout << b << std::endl << std::endl;

            // Try to upgrade b (1 -> 0)
            std::cout << BOLD <<"* Try to upgrade b (1 -> 0) *" << END << std::endl;
            b.upgrade();
            std::cout << b << std::endl << std::endl;
        }
        catch(const std::exception &e)
        {
            Bureaucrat::displayMessage(e.what(), ERR_COLOR);
        }
    }
}