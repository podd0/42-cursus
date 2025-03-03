#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("cat"), brain(new Brain)
{
	std::cout << "Creating a cat\n";
	brain->ideas[0] = "sleeping";
	brain->ideas[1] = "catnip";
	for (int i = 2; i < 100; i ++)
	{
		brain->ideas[i] = brain->ideas[i % 2];
	}
}

Cat::~Cat()
{
	std::cout << "Destroying a cat\n";
	delete brain;
}
Cat::Cat(const Cat& cat) : Animal(cat.getType()), brain(new Brain)
{
	std::cout << "Copy construction of a cat\n";
	*this = cat;
}

Cat& Cat::operator =(const Cat& cat)
{
	std::cout << "Copy of a cat\n";
	this->type = cat.getType();
	*this->brain = *cat.brain;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}
