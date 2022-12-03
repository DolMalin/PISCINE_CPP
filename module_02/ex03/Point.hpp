#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		// Constructors / Destructors
		Point();
		~Point();
		Point(const float x, const float y);
		Point(const Point &src);
		Point & operator = (const Point &rhs);

		// Getters
		const Fixed x() const;
		const Fixed y() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);