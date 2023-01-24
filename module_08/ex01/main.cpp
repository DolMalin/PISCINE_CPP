#include "Span.hpp"


int main(void)
{
	std::srand(unsigned(std::time(nullptr)));

	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #1" << std::endl;
	std::cout << "==============================================================" << std::endl;
	try
	{
		Span a = Span(5);
		
		a.addNumber(6);
		a.addNumber(3);
		a.addNumber(17);
		a.addNumber(9);
		a.addNumber(11);
		std::cout << "shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "longest span: " << a.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #2" << std::endl;
	std::cout << "==============================================================" << std::endl;
	try
	{
		Span a = Span(1);
		
		a.addNumber(6);
		a.addNumber(3);
		a.addNumber(17);
		a.addNumber(9);
		a.addNumber(11);
		std::cout << "shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "longest span: " << a.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #3" << std::endl;
	std::cout << "==============================================================" << std::endl;
	try
	{
		Span a = Span(0);
		
		std::cout << "shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "longest span: " << a.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #4" << std::endl;
	std::cout << "==============================================================" << std::endl;
	try
	{
		Span a = Span(1);

		a.addNumber(6);
		std::cout << "shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "longest span: " << a.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #6" << std::endl;
	std::cout << "==============================================================" << std::endl;
	try
	{
		Span a = Span(1000);
		
		std::vector<int> b(1000);
		std::generate(b.begin(), b.end(), std::rand);

		a.addRangeNumber(b.begin(), b.end());
		std::cout << "shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "longest span: " << a.longestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}



	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #7" << std::endl;
	std::cout << "==============================================================" << std::endl;
	try
	{
		Span a = Span(1000);
		
		std::vector<int> b(1001);
		std::generate(b.begin(), b.end(), std::rand);

		a.addRangeNumber(b.begin(), b.end());
		std::cout << "shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "longest span: " << a.longestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #8" << std::endl;
	std::cout << "==============================================================" << std::endl;
	try
	{
		Span a = Span(1000);

		a.addNumber(0);
		a.addNumber(1);
		
		std::vector<int> b(998);
		std::generate(b.begin(), b.end(), std::rand);

		a.addRangeNumber(b.begin(), b.end());
		std::cout << "shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "longest span: " << a.longestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #9" << std::endl;
	std::cout << "==============================================================" << std::endl;
	try
	{
		Span a = Span(1000);

		a.addNumber(0);
		a.addNumber(1);
		
		std::vector<int> b(999);
		std::generate(b.begin(), b.end(), std::rand);

		a.addRangeNumber(b.begin(), b.end());
		std::cout << "shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "longest span: " << a.longestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #10" << std::endl;
	std::cout << "==============================================================" << std::endl;
	try
	{
		Span a = Span(10000);
		
		std::vector<int> b(10000);
		std::generate(b.begin(), b.end(), std::rand);

		a.addRangeNumber(b.begin(), b.end());
		std::cout << "shortest span: " << a.shortestSpan() << std::endl;
		std::cout << "longest span: " << a.longestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}