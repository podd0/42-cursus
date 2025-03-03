#include "AMateria.hpp"
#include <string>
#include <iostream>

AMateria::AMateria(std::string const &type) : type(type)
{}

AMateria::~AMateria()
{

}

std::string const & AMateria::getType() const {
	return this->type;
}
