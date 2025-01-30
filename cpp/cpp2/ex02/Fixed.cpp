#include <iostream>
#include <cmath>
#include "Fixed.hpp"

int Fixed::precision = 8;
float Fixed::power = 256.0;

Fixed::Fixed() : bits(0)
{
	std::cout << "Default constructor called\n";
}

void Fixed::operator=(Fixed const &b)
{
	std::cout << "Copy assignment operator called\n";
	bits = b.getRawBits();
}

Fixed::Fixed(Fixed const &b)
{
	std::cout << "Copy constructor called\n";
	*this = b;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const
{
	return bits;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called\n";
	bits = raw;
}

Fixed::Fixed(const int n)
{
	std::cout<<"Int constructor called\n";
	setRawBits(n << precision);
}
Fixed::Fixed(const float x)
{
	std::cout<<"Float constructor called\n";
	setRawBits(roundf(x * power));
}

float Fixed::toFloat() const
{
	return float(getRawBits()) / power;
}
int Fixed::toInt() const
{
	return getRawBits() >> precision;
}

std::ostream& operator << (std::ostream &stream, const Fixed &x)
{
	return stream << x.toFloat();
}

Fixed Fixed::Fixed::operator + (Fixed const &other) const
{
	Fixed result;
	result.setRawBits(getRawBits() + other.getRawBits());
	return result;
}
Fixed Fixed::Fixed::operator - (Fixed const &other) const
{
	Fixed result;
	result.setRawBits(getRawBits() - other.getRawBits());
	return result;
}

Fixed Fixed::Fixed::operator * (Fixed const &other) const
{
	Fixed result;
	result.setRawBits(( ((long)getRawBits()) * other.getRawBits()) >> precision);
	return result;
}

Fixed Fixed::Fixed::operator / (Fixed const &other) const
{
	Fixed result;
	result.setRawBits(( ((long)getRawBits()) << precision) / other.getRawBits());
	return result;
}

bool Fixed::operator < (Fixed const &other) const
{
	return (getRawBits() < other.getRawBits());
}
bool Fixed::operator <= (Fixed const &other) const
{
	return (getRawBits() <= other.getRawBits());
}
bool Fixed::operator >= (Fixed const &other) const
{
	return (getRawBits() >= other.getRawBits());
}
bool Fixed::operator > (Fixed const &other) const
{
	return (getRawBits() > other.getRawBits());
}
bool Fixed::operator == (Fixed const &other) const
{
	return (getRawBits() == other.getRawBits());
}
bool Fixed::operator != (Fixed const &other) const
{
	return (getRawBits() != other.getRawBits());
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if(a < b)
		return a;
	return b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if(a > b)
		return a;
	return b;
}
const Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if(a < b)
		return a;
	return b;
}
const Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if(a > b)
		return a;
	return b;
}


Fixed& Fixed::operator ++()
{
	bits++;
	return (*this);
}
Fixed Fixed::operator ++(int)
{
	Fixed copy(*this);
	bits++;
	return copy;
}

Fixed& Fixed::operator --()
{
	bits--;
	return (*this);
}

Fixed Fixed::operator --(int)
{
	Fixed copy(*this);
	bits--;
	return copy;
}
