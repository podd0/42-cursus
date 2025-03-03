#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("dog")
{
	std::cout << "Creating a dog\n";
}

Dog::~Dog()
{
	std::cout << "Destroying a dog\n";
}
Dog::Dog(const Dog& dog) : Animal(dog.getType())
{
	std::cout << "Copy construction of a dog\n";
}

Dog& Dog::operator =(const Dog& dog)
{
	std::cout << "Copy of a dog\n";
	this->type = dog.getType();
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Bau" << std::endl;
}
