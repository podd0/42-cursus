#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap("Bobby", 100, 50, 20)
{
	std::cout << "Create default ScavTrap Bobby\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destroy ScavTrap " << getName() << "\n";
}

ScavTrap::ScavTrap(const ScavTrap &x) : ClapTrap()
{
	std::cout<<"Copy ScavTrap "<< x.getName() <<"\n";
	*this = x;
}

ScavTrap& ScavTrap::operator = (const ScavTrap &x)
{
	ClapTrap::operator=(x);
	std::cout<<"Assign ScavTrap "<< x.getName() << " to "<< getName() << "\n";
	return *this;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, 100, 50, 20)
{
	std::cout << "Created ScavTrap " << name << "\n";
}

void ScavTrap::attack(const std::string &target)
{
	if(opStart())
	{
		std::cout << "ScavTrap " << getName() << " attacks " << target << " dealing " << getAttackDamage() << " points of damage\n";
	}
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " is guarding the gate\n";
}
