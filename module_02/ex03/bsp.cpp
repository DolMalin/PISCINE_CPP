#include "Point.hpp"
#include "Fixed.hpp"

float area(const Point a, const Point b, const Point point)
{
	float output = (((a.x().toFloat() - point.x().toFloat())
		* (b.y().toFloat() - point.y().toFloat()))
		- ((a.y().toFloat() - point.y().toFloat())
		* (b.x().toFloat() - point.x().toFloat())));
	
	return output;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float ab = area(a, b, point);
	float bc = area(b, c, point);
	float ca = area(c, a, point);

	return ((ab > 0 && bc > 0 && ca > 0) || (ab < 0 && bc < 0 && ca < 0));
}