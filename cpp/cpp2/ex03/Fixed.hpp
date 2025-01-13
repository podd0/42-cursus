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
	Fixed abs() const;
	
	void operator = (Fixed const &fixed);
	Fixed operator + (Fixed const &other) const;
	Fixed operator - (Fixed const &other) const;
	Fixed operator * (Fixed const &other) const;
	Fixed operator / (Fixed const &other) const;
	Fixed &operator ++();
	Fixed operator ++(int);
	Fixed &operator --();
	Fixed operator --(int);

	bool operator < (Fixed const &other) const;
	bool operator <= (Fixed const &other) const;
	bool operator >= (Fixed const &other) const;
	bool operator > (Fixed const &other) const;
	bool operator == (Fixed const &other) const;
	bool operator != (Fixed const &other) const;

	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
	static const Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& max(Fixed& a, Fixed& b);
};
std::ostream &operator << (std::ostream &stream, const Fixed& x);


#endif