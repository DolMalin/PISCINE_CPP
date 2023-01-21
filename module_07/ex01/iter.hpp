#pragma once

#include <iostream>

template<typename T>
void iter(T *array, size_t len, void (*f)(const T&))
{
	for (size_t i = 0; i < len; i++)
		(*f)(array[i]);
}


template<typename T>
void printIncrement(T n)
{
	std::cout << n + 1 << " ";
}


template<typename T>
void print(T n)
{
	std::cout << n << " ";
}
