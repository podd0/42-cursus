#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"
class Point{
private:
	Fixed _x, _y;
public:
	Point();
	Point(const Fixed &x, const Fixed &y);
	Point(Point const &p);
	~Point();

	Fixed getX() const;
	Fixed getY() const;
	void operator = (Point const &p);
	Point operator + (Point const &p) const;
	Point operator - () const;
	Point operator - (Point const &p) const;
	Fixed cross(Point const &a, Point const &b) const;
	Fixed cross(Point const &a) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
