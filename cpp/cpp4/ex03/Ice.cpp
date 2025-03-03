#include "Ice.hpp"
#include <iostream>

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

Ice::Ice() : AMateria("ice")
{}
Ice::~Ice()
{}
Ice::Ice(const Ice& ice) : AMateria("ice")
{
	*this = ice;
}
Ice& Ice::operator = (const Ice& ice)
{
	this->type = ice.getType();
	return *this;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
