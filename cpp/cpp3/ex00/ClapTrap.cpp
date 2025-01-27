#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout<<"ClapTrap "<< name <<" initialized\n";
}

bool ClapTrap::opStart()
{
	if (hitPoints <= 0)
		std::cout << "ClapTrap " << name << " is dead and can't perform the operation\n";
	else if (energyPoints <= 0)
		std::cout << "ClapTrap " << name << " has no energy points to perform the operation\n";
	else return true;
	return false;
}

void ClapTrap::attack(const std::string &target)
{
	if (!opStart())
		return;
	energyPoints--;
	std::cout<<"ClapTrap "<<name<<" attacks "<<target<<" causing "<<attackDamage<<" points of damage\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " takes " << amount << " damage\n";
	hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!opStart())
		return;
	std::cout << "ClapTrap " << name << " repairs " << amount << " hit points\n";
	energyPoints--;
	hitPoints += amount;
}

ClapTrap::ClapTrap() : name("Billy"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Initialize default ClapTrap " << getName()<< "\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destroy ClapTrap " << getName() << "\n";
}

ClapTrap::ClapTrap(const ClapTrap &x)
{
	std::cout<<"Copy ClapTrap "<< x.getName() <<"\n";
	*this = x;
}

ClapTrap& ClapTrap::operator = (const ClapTrap &x)
{
	std::cout<<"Assign ClapTrap "<< x.getName() << " to "<< getName() << "\n";
	name = x.getName();
	hitPoints = x.hitPoints;
	attackDamage = x.attackDamage;
	energyPoints = x.energyPoints;
	return *this;
}

std::string ClapTrap::getName() const
{
	return name;
}