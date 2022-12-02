#include "Fixed.hpp"

/* ========== ~ CONSTRUCTORS / DESTRUCTORS ~ ==========*/
Fixed::Fixed() : _rawBits(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const int n)
{
	setRawBits(n << _nBits);
}

Fixed::Fixed(const float n)
{
	setRawBits(int(roundf(n * (1 << _nBits))));
}

Fixed::Fixed(const Fixed &src)
{
	_rawBits = src.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	_rawBits = rhs.getRawBits();
	return *this;
}

/* ========== ~ GETTERS / SETTERS ~ ==========*/

int Fixed::getRawBits(void) const
{
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

/* ========== ~ METHODS ~ ==========*/
float Fixed::toFloat(void) const
{
	return float(_rawBits) / (1 << _nBits);
}

int Fixed::toInt(void) const
{
	return _rawBits >> _nBits;
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	return ((f1 > f2) ? f2 : f1);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return ((f1 > f2) ? f2 : f1);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	return ((f1 > f2) ? f1 : f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return ((f1 > f2) ? f1 : f2);
}


/* ========== ~ COMPARISON OPERATORS ~ ==========*/
bool Fixed::operator > (const Fixed &f) const
{
	return (getRawBits() > f.getRawBits());
}

bool Fixed::operator < (const Fixed &f) const
{
	return (getRawBits() < f.getRawBits());
}

bool Fixed::operator >= (const Fixed &f) const
{
	return (getRawBits() >= f.getRawBits());
}

bool Fixed::operator <= (const Fixed &f) const
{
	return (getRawBits() <= f.getRawBits());
}

bool Fixed::operator == (const Fixed &f) const
{
	return (getRawBits() == f.getRawBits());
}

bool Fixed::operator != (const Fixed &f) const
{
	return (getRawBits() != f.getRawBits());
}

/* ========== ~ ARITHMETIC OPERATORS ~ ==========*/
Fixed Fixed::operator + (const Fixed &f) const
{
	Fixed temp;

	temp.setRawBits(getRawBits() + f.getRawBits());
	return temp;
}

Fixed Fixed::operator - (const Fixed &f) const
{
	Fixed temp;

	temp.setRawBits(getRawBits() - f.getRawBits());
	return temp;
}

Fixed Fixed::operator * (const Fixed &f) const
{
	Fixed temp;

	temp.setRawBits(getRawBits() * f.getRawBits() >> _nBits);
	return temp;
}

Fixed Fixed::operator / (const Fixed &f) const
{
	Fixed temp;

	temp.setRawBits(getRawBits() * (1 << _nBits) / f.getRawBits());
	return temp;
}

/* ========== ~ INCREMENT/DECREMENT OPERATORS ~ ==========*/
Fixed &Fixed::operator ++ ()
{
	setRawBits(getRawBits() + 1);
	return *this;
}


Fixed Fixed::operator ++ (int)
{
	Fixed temp = *this;
	setRawBits(getRawBits() + 1);
	return temp;
}


Fixed &Fixed::operator -- ()
{
	setRawBits(getRawBits() - 1);
	return *this;
}


Fixed Fixed::operator -- (int)
{
	Fixed temp = *this;
	setRawBits(getRawBits() - 1);
	return temp;
}


std::ostream &operator<<(std::ostream &os, const Fixed &f)
{
	os << f.toFloat();
	return os;
}