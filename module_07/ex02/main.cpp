#include "Array.hpp"
#include <iostream>

template <typename T>
void printArray(Array<T> &array, size_t len)
{
	std::cout << "array: ";
	for (size_t i = 0; i < len; i++)
	{
		std::cout << array[i];
		if (i < len - 1)
			std::cout << ", ";
	}
		std::cout << std::endl;
}

int main(void)
{
	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #1 (Int array)" << std::endl;
	std::cout << "==============================================================" << std::endl;
	{
		Array<int> array(10);
		std::cout << "len: " << array.len() << std::endl;
		for (int i = 0; i < 10; i++)
			array[i] = i;
		printArray<int>(array, array.len());
	}
	
	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #2 (Char array)" << std::endl;
	std::cout << "==============================================================" << std::endl;
	{
		Array<char> array(25);
		std::cout << "len: " << array.len() << std::endl;
		for (char i = 'a'; i < 'z'; i++)
			array[i - 'a'] = i;
		printArray<char>(array, array.len());
	}

	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #3 (Empty char array)" << std::endl;
	std::cout << "==============================================================" << std::endl;
	{
		Array<char> array;
		std::cout << "len: " << array.len() << std::endl;
		printArray<char>(array, array.len());
	}

	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #4 (String array)" << std::endl;
	std::cout << "==============================================================" << std::endl;
	{
		Array<std::string> array(2);
		std::cout << "len: " << array.len() << std::endl;
		array[0] = "Hello";
		array[1] = ", world!";
		printArray<std::string>(array, array.len());
	}

	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #5 (const String array)" << std::endl;
	std::cout << "==============================================================" << std::endl;
	{
		const Array<std::string> array(2);
		std::cout << "len: " << array.len() << std::endl;
		std::cout << array[0] << std::endl;

		// uncomment this line !
		// array[0] = "Hello"; 
	}

	std::cout << std::endl << "==============================================================" << std::endl;
	std::cout << "TEST #6 (Out of range index)" << std::endl;
	std::cout << "==============================================================" << std::endl;
	{
		Array<int> array(10);
		std::cout << "len: " << array.len() << std::endl;
		try
		{
			std::cout << array[11] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}