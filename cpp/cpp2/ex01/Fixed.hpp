#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
private:
	int bits;
	static int precision;
	static float power;
public:
	Fixed();
	Fixed(Fixed const &fixed);
	~Fixed();
	Fixed(const int n);
	Fixed(const float x);
	
	float toFloat() const;
	int toInt() const;
	int getRawBits() const;
	void setRawBits( int const raw );
	
	void operator = (Fixed const &fixed);
};
std::ostream &operator << (std::ostream &stream, const Fixed& x);


#endif