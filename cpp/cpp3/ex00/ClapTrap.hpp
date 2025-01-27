#ifndef CLAPTRAP_HPP
#include <string>

#define CLAPTRAP_HPP

class ClapTrap{
private:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
	bool opStart();
public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap &x);
	ClapTrap& operator = (const ClapTrap &x);

	std::string getName() const;
	ClapTrap(std::string name);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif