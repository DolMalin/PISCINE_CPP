
#include "Fixed.hpp"
#include "Point.hpp"

#include <iostream>
#include <string>
#include <sstream>

static Point parsePoint(std::string str)
{
	std::stringstream	ss;
	size_t				n;
	float				x;
	float				y;


	n = str.find(",");
	if (n == std::string::npos)
	{
		std::cerr << "Usage: ./a.out <float A: x,y> <float b: x,y> <float c: x,y> <float point: x,y>" << std::endl;
		exit(EXIT_FAILURE);
	}
	ss << str.substr(0, n);
	ss >> x;
	ss.clear();

	ss << str.substr(n + 1, str.length());
	ss >> y;
	ss.clear();
	
	return Point(x, y);
}

int main(int ac, char **av)
{
	std::cout << "You can generate coordinate points on: https://www.geogebra.org/classic?lang=en" << std::endl;
	if (ac != 5)
	{
		std::cerr << "Usage: ./a.out <float A: x,y> <float b: x,y> <float c: x,y> <float point: x,y>" << std::endl;

		return 1;
	}
	
	Point a = parsePoint(av[1]);
	Point b = parsePoint(av[2]);
	Point c = parsePoint(av[3]);
	Point point = parsePoint(av[4]);

	std::cout << "==============================================" << std::endl;
	std::cout << "a: " << a.x() << "," << a.y() << std::endl;
	std::cout << "b: " << b.x() << "," << b.y() << std::endl;
	std::cout << "c: " << c.x() << "," << c.y() << std::endl;
	std::cout << "point: " << point.x() << "," << point.y() << std::endl;
	std::cout << "==============================================" << std::endl;
	std::cout << std::endl;

	if (bsp(a, b, c, point))
		std::cout << "The point is inside" << std::endl;
	else
		std::cout << "The point is not inside" << std::endl;
	return 0;
}
