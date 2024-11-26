#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	std::cout << name << " has been created, holding a weapon of type ";
	std::cout << weapon.getType() <<"\n";
}

HumanA::~HumanA()
{
	std::cout << _name << " has been destryed\n";
}

void HumanA::attack()
{
	std::cout << _name << " attacks with a " << _weapon.getType() << "\n";
}
