#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
	Point a(0, 0), b(1, 0), c(0, 1), p;
	std::cout<<"The triangle is made of the points (1, 0), (0, 0), (0, 1)\n";
	while (!std::cin.eof())
	{
		float x, y;
		std::cout<<"Insert x and y"<<std::endl;
		std::cin >> x >> y;
		p = Point(x, y);
		bool res = bsp(a, b, c, p);
		std::cout<<"RESULT : the point ("<<x<<", "<<y\
			<<") is "<<(res?"in":"out")<<"side the triangle"<<std::endl;
	}
	return 0;
}
