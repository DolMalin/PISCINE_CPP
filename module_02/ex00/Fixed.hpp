#pragma once

#include <iostream>

class Fixed
{
	private:
		int	_rawBits;
		int	const static _fraction = 8;

	public:
		Fixed ();
		~Fixed ();
		Fixed (const Fixed &src);
		Fixed & operator = (const Fixed &rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};