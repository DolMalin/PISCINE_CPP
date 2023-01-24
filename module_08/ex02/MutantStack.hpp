#pragma once

#include <stack>
#include <iostream>
#include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

    const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }
};