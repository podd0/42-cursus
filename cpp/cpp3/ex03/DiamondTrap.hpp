#ifndef DIAMONDTRAP_HPP
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#define DIAMONDTRAP_HPP

class DiamondTrap : public FragTrap, ScavTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &x);
	DiamondTrap& operator = (const DiamondTrap &x);

	DiamondTrap(std::string name);
	void attack(const std::string &target);
	void highFivesGuys();
	void whoAmI();
};

#endif