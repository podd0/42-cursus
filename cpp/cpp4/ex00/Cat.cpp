#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("cat")
{
	std::cout << "Creating a cat\n";
}

Cat::~Cat()
{
	std::cout << "Destroying a cat\n";
}
Cat::Cat(const Cat& cat) : Animal(cat.getType())
{
	std::cout << "Copy construction of a cat\n";
}

Cat& Cat::operator =(const Cat& cat)
{
	std::cout << "Copy of a cat\n";
	this->type = cat.getType();
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
