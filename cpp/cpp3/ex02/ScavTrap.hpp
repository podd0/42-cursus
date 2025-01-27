#ifndef SCAVTRAP_HPP
#include <string>
#include "ClapTrap.hpp"
#define SCAVTRAP_HPP

class ScavTrap : public ClapTrap
{
private:
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(const ScavTrap &x);
	ScavTrap& operator = (const ScavTrap &x);

	ScavTrap(std::string name);
	void attack(const std::string &target);
	void guardGate();
};


#endif