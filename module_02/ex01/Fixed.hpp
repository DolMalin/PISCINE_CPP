#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_rawBits;
		int	const static _nBits = 8;

	public:
		Fixed ();
		~Fixed ();
		
		Fixed (const int n);
		Fixed (const float n);
		Fixed (const Fixed &src);
		Fixed & operator = (const Fixed &rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream & operator<<(std::ostream &os, const Fixed &fixed);