#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout<<"create Brain\n";
}
Brain::~Brain()
{
	std::cout<<"delete Brain\n";
}
Brain::Brain(const Brain &brain)
{
	std::cout<<"copy construct Brain\n";
	*this = brain;
}
Brain& Brain::operator =(const Brain &brain)
{
	std::cout << "copy Brain\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = brain.ideas[i];
	return *this;
}