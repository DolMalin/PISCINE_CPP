#pragma once

#include <exception>
#include <algorithm>
#include <vector>
#include <iostream>
#include <list>
#include <stack>

class NoOccurenceException: public std::exception
{
	public:
		virtual const char *what() const throw ()
		{
			return ("No occurence");
		}
};


template<typename T>
typename T::iterator easyfind(T &array, int n)
{
	typename T::iterator it = std::find(array.begin(), array.end(), n);

	if (it == array.end())
		throw NoOccurenceException();
	return it;
}