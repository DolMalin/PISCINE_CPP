#include "Point.hpp"

/* ========== ~ CONSTRUCTORS / DESTRUCTORS ~ ==========*/
Point::Point() {};

Point::~Point() { };

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y)) { }

Point::Point(const Point &src): _x(src._x), _y(src._y) { }

Point &Point::operator = (const Point &rhs)
{
	(void)rhs;
	return *this;
}

/* ========== ~ GETTERS ~ ==========*/
const Fixed Point::x() const 
{
	return _x.toFloat();
}

const Fixed Point::y() const 
{
	return _y.toFloat();
}