#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int bits;
	static int precision;
public:
	Fixed();
	Fixed(Fixed &fixed);
	~Fixed();

	void operator = (Fixed &fixed);
	int getRawBits();
	void setRawBits( int const raw );
};


#endif