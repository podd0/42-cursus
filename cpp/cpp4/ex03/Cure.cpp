#include "Cure.hpp"
#include <iostream>

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

Cure::Cure() : AMateria("cure")
{}
Cure::~Cure()
{}
Cure::Cure(const Cure& cure) : AMateria("cure")
{
	*this = cure;
}
Cure& Cure::operator = (const Cure& cure)
{
	this->type = cure.getType();
	return *this;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
