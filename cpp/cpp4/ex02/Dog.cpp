#include <iostream>
#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("dog"), brain(new Brain)
{
	std::cout << "Creating a dog\n";
	brain->ideas[0] = "ball";
	brain->ideas[1] = "walk";
	brain->ideas[2] = "bone";
	for (int i = 3; i < 100; i ++)
	{
		brain->ideas[i] = brain->ideas[i % 3];
	}
}

Dog::~Dog()
{
	std::cout << "Destroying a dog\n";
	delete brain;
}
Dog::Dog(const Dog& dog) : Animal(dog.getType()), brain(new Brain)
{
	std::cout << "Copy construction of a dog\n";
	*this = dog;
}

Dog& Dog::operator =(const Dog& dog)
{
	std::cout << "Copy of a dog\n";
	this->type = dog.getType();
	*this->brain = *dog.brain;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Bau" << std::endl;
}
