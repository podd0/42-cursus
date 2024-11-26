#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << _name << " has been created\n";
}

HumanB::~HumanB()
{
	std::cout << _name << " has been destroyed\n";
}

void HumanB::attack()
{
	std::string weapon = "bare hands";
	if (_weapon != NULL)
		weapon = _weapon->getType();
	std::cout << _name << " attacks with " << weapon << "\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
	std::cout << _name << " has obtained " << weapon.getType() << "\n";
}
