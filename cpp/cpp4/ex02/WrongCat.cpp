#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("wrong cat")
{
	std::cout << "Creating a wrong cat\n";
}

WrongCat::~WrongCat()
{
	std::cout << "Destroying a wrong cat\n";
}
WrongCat::WrongCat(const WrongCat& cat) : WrongAnimal(cat.getType())
{
	std::cout << "Copy construction of a wrong cat\n";
}

WrongCat& WrongCat::operator =(const WrongCat& cat)
{
	std::cout << "Copy of a wrong cat\n";
	this->type = cat.getType();
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
