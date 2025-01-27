#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap("Mario", 100, 100, 30)
{
	std::cout << "Create default FragTrap Mario\n";
}

FragTrap::~FragTrap()
{
	std::cout << "Destroy FragTrap " << getName() << "\n";
}

FragTrap::FragTrap(const FragTrap &x) : ClapTrap()
{
	std::cout<<"Copy FragTrap "<< x.getName() <<"\n";
	*this = x;
}

FragTrap& FragTrap::operator = (const FragTrap &x)
{
	ClapTrap::operator=(x);
	std::cout<<"Assign FragTrap "<< x.getName() << " to "<< getName() << "\n";
	return *this;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, 100, 100, 30)
{
	std::cout << "Created FragTrap " << name << "\n";
}

void FragTrap::attack(const std::string &target)
{
	if(opStart())
	{
		std::cout << "FragTrap " << getName() << " attacks " << target << " dealing " << getAttackDamage() << " points of damage\n";
	}
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << getName() << " proposes an high five\n";
}
