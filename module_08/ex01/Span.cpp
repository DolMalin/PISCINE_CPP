#include "Span.hpp"
/* ========================================================================== */
/*                                                                            */
/*                       ~ constructors / destructors ~                       */
/*                                                                            */
/* ========================================================================== */
Span::Span(void): _len(0) { }

Span::Span(unsigned int N): _len(N) { }

Span::~Span(void) { }

Span::Span(const Span &src)
{
    *this = src;
}

Span &Span::operator = (const Span &rhs)
{
    _len = rhs._len;
    _array = rhs._array;
    return *this;
}

/* ========================================================================== */
/*                                                                            */
/*                             ~ member functions ~                           */
/*                                                                            */
/* ========================================================================== */

void Span::addNumber(int N)
{
    if (_array.size() >= _len)
        throw FullArrayException();
    _array.push_back(N);
}


void Span::addRangeNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    std::vector<int> tmp;
    for (std::vector<int>::iterator it = begin; it < end; it++)
        tmp.push_back(*it);

    if (tmp.size() + _array.size() > _len)
        throw FullArrayException();
        
    for (std::vector<int>::iterator it = begin; it < end; it++)
        _array.push_back(*it);
}


int Span::shortestSpan(void)
{
    if (_array.size() < 2)
        throw NoDistanceException();

 	int min = std::numeric_limits<int>::max ();
	for (size_t i = 0; i < _array.size (); i += 1)
	{
		for (size_t j = i + 1; j < _array.size (); j += 1)
		{
			if (std::abs (_array[i] - _array[j]) < min)
				min = std::abs (_array[i] - _array[j]);
		}
	}
	return min;   
    
}


int Span::longestSpan(void)
{
    if (_array.size() < 2)
        throw NoDistanceException();
    return *std::max_element (_array.begin (), _array.end ()) - *std::min_element (_array.begin (), _array.end ());
}

/* ========================================================================== */
/*                                                                            */
/*                                ~ exceptions ~                              */
/*                                                                            */
/* ========================================================================== */

const char *Span::EmptyArrayException::what() const throw()
{
    return "array is empty";
}

const char *Span::FullArrayException::what() const throw()
{
    return "array is full";
}

const char *Span::NoDistanceException::what() const throw()
{
    return "No distance can be found";
}