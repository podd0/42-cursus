#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>
bool bsp( Point const a, Point const b, Point const c, Point const p)
{
	Fixed double_area_abc = a.cross(b, c).abs();
	Fixed double_area_pab = p.cross(a, b).abs();
	Fixed double_area_pbc = p.cross(b, c).abs();
	Fixed double_area_pca = p.cross(c, a).abs();
	return double_area_abc == double_area_pab + double_area_pbc + double_area_pca && 
		Fixed(0) != Fixed::min(double_area_pbc, Fixed::min(double_area_pab, double_area_pca));
}
