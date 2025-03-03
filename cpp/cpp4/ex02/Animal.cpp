#include <iostream>
#include "Animal.hpp"

Animal::Animal() : type("abstract")
{
	std::cout << "Creating an abstract animal\n";
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Creating an animal\n";
}

Animal::~Animal()
{
	std::cout << "Destroying an abstract animal\n";
}
Animal::Animal(const Animal& animal)
{
	std::cout << "Copy construction of an abstract animal\n";
	*this = animal;
}

Animal& Animal::operator =(const Animal& animal)
{
	std::cout << "Copy of an abstract animal\n";
	this->type = animal.getType();
	return *this;
}

std::string Animal::getType() const
{
	return this->type;
}
