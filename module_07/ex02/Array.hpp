#pragma once

#include <exception>
#include <cstddef>

template <typename T>
class Array
{
	private:
		size_t	_len;
		T 		*_array;
	
	public:
	/* ============== ~ constructors / destructors ~ ============== */
		Array(): _len(0), _array(new T[0]) { }

		~Array() { delete [] _array; }

		Array(unsigned int n): _len(n), _array(new T[n]) { }

		Array<T> & operator = (const Array &rhs)
		{
			_len = rhs._len;
			_array = new T[rhs._len];
			for (size_t i = 0; i < rhs._len; i++)
				_array[i] = rhs._array[i];
			return *this;
		}

		Array(const Array &src)
		{
			*this = src;
		}

	/* ============== ~ member functions ~ ============== */
		size_t len(void) const { return _len; }

	/* ============== ~ operator overload ~ ============== */
		T& operator[](unsigned int i)
		{
			if (i >= _len)
				throw IndexOutOfRangeException();
			return _array[i];
		}

		const T& operator[](unsigned int i) const
		{
			if (i >= _len)
				throw IndexOutOfRangeException();
			return _array[i];
		}

	/* ============== ~ exceptions ~ ============== */									
		class	IndexOutOfRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Index out of range");
				}
		};
};