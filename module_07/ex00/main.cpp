#include "whatever.hpp"

int main(void)
{
	std::cout << std::endl << "=============================" << std::endl;
	std::cout << "TEST #1 (int)" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		int a = 5;
		int b = 10;

		std::cout << "a: " << a << ", b: " << b << std::endl;
		::swap(a, b);
		std::cout << "swap(a,b) -> void" << std::endl;
		std::cout << "a: " << a << ", b: " << b << std::endl;

		std::cout << "min(a,b) -> " << ::min(a,b) << std::endl;

		std::cout << "max(a,b) -> " << ::max(a,b) << std::endl;
	}

	std::cout << std::endl << "=============================" << std::endl;
	std::cout << "TEST #2 (int)" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		int a = 100;
		int b = -1;

		std::cout << "a: " << a << ", b: " << b << std::endl;
		::swap(a, b);
		std::cout << "swap(a,b) -> void" << std::endl;
		std::cout << "a: " << a << ", b: " << b << std::endl;

		std::cout << "min(a,b) -> " << ::min(a,b) << std::endl;

		std::cout << "max(a,b) -> " << ::max(a,b) << std::endl;
	}

	std::cout << std::endl << "=============================" << std::endl;
	std::cout << "TEST #3 (char)" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		char a = 'a';
		char b = 'b';

		std::cout << "a: " << a << ", b: " << b << std::endl;
		::swap(a, b);
		std::cout << "swap(a,b) -> void" << std::endl;
		std::cout << "a: " << a << ", b: " << b << std::endl;

		std::cout << "min(a,b) -> " << ::min(a,b) << std::endl;

		std::cout << "max(a,b) -> " << ::max(a,b) << std::endl;
	}

	std::cout << std::endl << "=============================" << std::endl;
	std::cout << "TEST #4 (float)" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		float a = 0.32f;
		float b = 0.33f;

		std::cout << "a: " << a << ", b: " << b << std::endl;
		::swap(a, b);
		std::cout << "swap(a,b) -> void" << std::endl;
		std::cout << "a: " << a << ", b: " << b << std::endl;

		std::cout << "min(a,b) -> " << ::min(a,b) << std::endl;

		std::cout << "max(a,b) -> " << ::max(a,b) << std::endl;
	}


	std::cout << std::endl << "=============================" << std::endl;
	std::cout << "TEST #5 (string)" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		std::string a = "Hello";
		std::string b = "World";

		std::cout << "a: " << a << ", b: " << b << std::endl;
		::swap(a, b);
		std::cout << "swap(a,b) -> void" << std::endl;
		std::cout << "a: " << a << ", b: " << b << std::endl;

		std::cout << "min(a,b) -> " << ::min(a,b) << std::endl;

		std::cout << "max(a,b) -> " << ::max(a,b) << std::endl;
	}


	std::cout << std::endl << "=============================" << std::endl;
	std::cout << "TEST #6 (Fixed point from CPP_02)" << std::endl;
	std::cout << "=============================" << std::endl;
	{
		Fixed a(100.23f);
		Fixed b(-75.44f);
		
		std::cout << "a: " << a << ", b: " << b << std::endl;
		::swap(a, b);
		std::cout << "swap(a,b) -> void" << std::endl;
		std::cout << "a: " << a << ", b: " << b << std::endl;

		std::cout << "min(a,b) -> " << ::min(a,b) << std::endl;

		std::cout << "max(a,b) -> " << ::max(a,b) << std::endl;
	}

}