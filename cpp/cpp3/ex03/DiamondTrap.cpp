#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : 
	ClapTrap("3L10_clap_name", 100, 50, 30),
	FragTrap(),
	ScavTrap(),
	name("3L10")
{
	std::cout << "Create default DiamondTrap " << getName() << "\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destroy DiamondTrap " << getName() << "\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &x) : 
	ClapTrap(),
	FragTrap(),
	ScavTrap(),
	name("3L10")
{
	std::cout<<"Copy DiamondTrap "<< x.getName() <<"\n";
	*this = x;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap &x)
{
	std::cout<<"Assign DiamondTrap "<< x.name << " to "<< name << "\n";
	ClapTrap::operator=(x);
	name = x.name;
	return *this;
}

DiamondTrap::DiamondTrap(std::string name) : 
	ClapTrap(name+"_clap_name", 100, 50, 30),
	FragTrap(),
	ScavTrap(),
	name(name)
{
	std::cout << "Created DiamondTrap " << name << "\n";
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::highFivesGuys()
{
	std::cout << "DiamondTrap " << getName() << " proposes an high five\n";
}

void DiamondTrap::whoAmI()
{
	std::cout<<"ClapTrap::name " << getName() << " DiamondTrap::name " << name << "\n";
}
