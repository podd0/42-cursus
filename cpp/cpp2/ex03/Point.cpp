#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point(Fixed x, Fixed y) : _x(x), _y(y) {}
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
	return Point(getX() + p.getX(), getX() + p.getX());
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
	return (a - *this).cross(b - *this);
}

Fixed Point::cross(Point const &a) const
{
	return getX() * a.getY() - getY() * a.getX();
}
