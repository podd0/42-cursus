#ifndef FRAGTRAP_HPP
#include <string>
#include "ClapTrap.hpp"
#define FRAGTRAP_HPP

class FragTrap : public virtual ClapTrap
{
private:
public:
	FragTrap();
	~FragTrap();
	FragTrap(const FragTrap &x);
	FragTrap& operator = (const FragTrap &x);

	FragTrap(std::string name);
	void attack(const std::string &target);
	void highFivesGuys();
};


#endif