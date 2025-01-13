#include <iostream>
#include "Fixed.hpp"

int Fixed::precision = 8;

Fixed::Fixed() : bits(0)
{
	std::cout << "Default constructor called\n";
}

void Fixed::operator=(Fixed &b)
{
	std::cout << "Copy assignment operator called\n";
	bits = b.getRawBits();
}

Fixed::Fixed(Fixed &b)
{
	std::cout << "Copy constructor called\n";
	*this = b;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits()
{
	std::cout << "getRawBits member function called\n";
	return bits;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called\n";
	bits = raw;
}
