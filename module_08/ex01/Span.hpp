#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <ctime>


class Span
{
    private:
        unsigned int _len;
        std::vector<int> _array;

    public:
    /* ============== ~ constructors / destructors ~ ============== */
        Span(void);
        Span(unsigned int N);
        ~Span(void);
        Span(const Span &src);
        Span & operator = (const Span &rhs);

    /* ============== ~ member functions ~ ============== */
        void addNumber(int N);
        void addRangeNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan(void);
        int longestSpan(void);
        
    /* ============== ~ exceptions ~ ============== */
        class FullArrayException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class EmptyArrayException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class NoDistanceException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        
};