#include "Point.hpp"
#include <iostream>

Point::Point() : _x(0), _y(0) {
	std::cout<<"Point created as 0, 0"<<std::endl;

}
Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y) {
	std::cout<<"Point created as "<<x<<", "<<y<<std::endl;
}
Point::Point(Point const &p){
	*this = p;
}
Point::~Point() {}

void Point::operator = (Point const &p){
	_x = p.getX();
	_y = p.getY();
}

Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}

Point Point::operator + (Point const &p) const
{
	return Point(getX() + p.getX(), getY() + p.getY());
}


Point Point::operator - () const
{
	return Point(Fixed(-1) * getX(), Fixed(-1) * getY());
}

Point Point::operator - (Point const &p) const
{
	return *this + (- p);
}

Fixed Point::cross(Point const &a, Point const &b) const
{
	std::cout<<"cross called\n";
	return (a - *this).cross(b - *this);
}

Fixed Point::cross(Point const &a) const
{
	return getX() * a.getY() - getY() * a.getX();
}
