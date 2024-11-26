#include <string>
#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "A weapon of type \"" << _type << "\" has been created\n";
}
Weapon::~Weapon()
{
	std::cout << "A weapon of type \"" << _type << "\" has been destroyed\n";
}
std::string Weapon::getType()
{
	return _type;
}
void Weapon::setType(std::string type)
{
	// std::cout << "change type from " << _type<< " to " << type << "\n";
	_type = type;
}