#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "main.hpp"

Base *generate(void)
{
	int randn = rand() % 3;
	
	switch (randn)
	{
		case 0:
			std::cout << "A class generated" << std::endl;
			return new A();
		case 1:
			std::cout << "B class generated" << std::endl;
			return new B();
		case 2:
			std::cout << "C class generated" << std::endl;
			return new C();
		default:
			return NULL;
	}
}


void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A class identified" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B class identified" << std::endl ;
	else if (dynamic_cast<C*>(p))
		std::cout << "C class identified" << std::endl ;
	else
		std::cout << "Error" << std::endl;
}

void identify(Base &p)
{
	try
	{
		if (dynamic_cast<A*>(&p))
			std::cout << "A class identified" << std::endl;
		else if (dynamic_cast<B*>(&p))
			std::cout << "B class identified" << std::endl;
		else if (dynamic_cast<C*>(&p))
			std::cout << "C class identified" << std::endl;
		else
			std::cout << "Error" << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << "Error" << std::endl;
	}

	
}

int main(void)
{
	srand((unsigned)time(0));

	std::cout << "=============================" << std::endl;
	std::cout << "TEST #1 (pointer)" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		Base *tmp;
		
		tmp = generate();
		identify(tmp);

		delete tmp;
	}

	std::cout << std::endl << "=============================" << std::endl;
	std::cout << "TEST #2 (reference)" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		Base *tmp = generate();
		Base &tmpRef = *tmp;

		identify(tmpRef);

		delete tmp;
	}

	std::cout << std::endl << "=============================" << std::endl;
	std::cout << "TEST #3 (bad pointer)" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		Base *tmp = new Base();
		identify(tmp);

		delete tmp;
	}

	std::cout << std::endl << "=============================" << std::endl;
	std::cout << "TEST #4 (bad reference)" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		Base *tmp = new Base();
		identify(*tmp);

		delete tmp;
	}


	return 0;
}