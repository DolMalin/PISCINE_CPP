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


Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(n << _nBits);
}


Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(int(roundf(n * (1 << _nBits))));
}


Fixed::Fixed (const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	_rawBits = src.getRawBits();
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


float Fixed::toFloat(void) const
{
	return float(_rawBits) / (1 << _nBits);
}


int Fixed::toInt(void) const
{
	return _rawBits >> _nBits;
}

std::ostream &operator << (std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}