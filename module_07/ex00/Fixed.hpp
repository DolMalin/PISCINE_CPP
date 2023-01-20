#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_rawBits;
		int	const static _nBits = 8;

	public:
		/* Constructor / Destructor */
		Fixed ();
		~Fixed ();
		Fixed (const int n);
		Fixed (const float n);
		Fixed (const Fixed &src);
		Fixed & operator = (const Fixed &rhs);

		/* Getter / Setter */
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		/* Methods */
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed		&min(Fixed &f1, Fixed &f2);
		static Fixed		&max(Fixed &f1, Fixed &f2);
		static const Fixed	&min(const Fixed &f1, const Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);

		/* Comparison operators */
		bool operator > (const Fixed &f) const;
		bool operator < (const Fixed &f) const;
		bool operator >= (const Fixed &f) const;
		bool operator <= (const Fixed &f) const;
		bool operator == (const Fixed &f) const;
		bool operator != (const Fixed &f) const;

		/* Arithmetic operators */
		Fixed operator + (const Fixed &f) const;
		Fixed operator - (const Fixed &f) const;
		Fixed operator * (const Fixed &f) const;
		Fixed operator / (const Fixed &f) const;

		/* Incrementor / Decrementor */
		Fixed&	operator ++ ();
		Fixed	operator ++ (int);
		Fixed&	operator -- ();
		Fixed	operator -- (int);

};

std::ostream & operator<<(std::ostream &os, const Fixed &f);
