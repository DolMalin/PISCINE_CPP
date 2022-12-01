#include "Fixed.hpp"

/* ========== ~ CONSTRUCTORS/DESTRUCTORS ~ ==========*/
Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}


Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed (const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


Fixed &Fixed::operator = (const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_rawBits = rhs.getRawBits();
	return *this;
}


/* ========== ~ MEMBER FUNCTIONS ~ ==========*/
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}


void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}