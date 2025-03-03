#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("wrong")
{
	std::cout << "Creating a wrong animal\n";
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "Creating a wrong animal\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destroying a wrong animal\n";
}
WrongAnimal::WrongAnimal(const WrongAnimal& animal)
{
	std::cout << "Copy construction of a wrong animal\n";
	*this = animal;
}

WrongAnimal WrongAnimal::operator =(const WrongAnimal& animal)
{
	std::cout << "Copy of a wrong animal\n";
	this->type = animal.getType();
	return *this;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "I'm WrongAnimal :(" << std::endl;
}


