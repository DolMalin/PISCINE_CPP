#pragma once

#include <string>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>

class Scalar
{
	/* ============== ~ enum ~ ============== */
	enum Type
	{
		eChar,
		eInt,
		eFloat,
		eDouble,
		eNan
	};

	private:
		Type		_type;
		std::string _litteral;
		
	public:
		/* ============== ~ constructors / destructors ~ ============== */
		Scalar();
		Scalar(std::string litteral);
		~Scalar();
		Scalar(const Scalar &src);
		Scalar & operator = (const Scalar &rhs);


		/* ============== ~ member functions ~ ============== */
		std::string 	litteral(void) const;
		Type			type(void) const;
		std::string 	typeString(void) const;

		std::string	toString(void) const;
		char		toChar(void) const;
		int 		toInt(void) const;
		float		toFloat(void) const;
		double		toDouble(void) const;

		/* ============== ~ exceptions ~ ============== */
		class NonDisplayableException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};


		class ImpossibleConversionException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};


		class NotANumberException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};


		class NotANumberFloatException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};