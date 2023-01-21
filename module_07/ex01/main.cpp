#include "iter.hpp"
#include "Fixed.hpp"



int main(void)
{
	std::cout << std::endl << "=============================" << std::endl;
	std::cout << "TEST #1 (Int array)" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
		::iter<int>(array, 10, printIncrement);
		std::cout << std::endl;
	}

	std::cout << std::endl << "=============================" << std::endl;
	std::cout << "TEST #2 (Char array)" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		char array[14] = "hello, world!";
		::iter<char>(array, 14, print);
		std::cout << std::endl;
	}

	std::cout << std::endl << "=============================" << std::endl;
	std::cout << "TEST #3 (String array)" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		std::string array[2] = {
			"hello, ",
			"world!"
		};

		::iter<std::string>(array, 2, print);
		std::cout << std::endl;
	}

	std::cout << std::endl << "=============================" << std::endl;
	std::cout << "TEST #4 (Fixed point array from CPP_02)" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		Fixed *array = new Fixed[4]; 

		for (int i = 0; i < 4; i++)
			array[i].setRawBits(i << 8);
		
		::iter<Fixed>(array, 4, print);
		std::cout << std::endl;

		delete [] array;
	}

	std::cout << std::endl << "=============================" << std::endl;
	std::cout << "TEST #5 (Fixed point array from CPP_02)" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		Fixed array[10]; 

		for (int i = 0; i < 10; i++)
			array[i].setRawBits(int(roundf((i * 0.25) * (1 << 8))));
		
		::iter<Fixed>(array, 10, print);
		std::cout << std::endl;
	}
}