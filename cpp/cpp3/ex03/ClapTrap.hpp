#ifndef CLAPTRAP_HPP
#include <string>

#define CLAPTRAP_HPP

class ClapTrap{
private:
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
protected:
	bool opStart();
	int getHitPoints();
	int getEnergyPoints();
	int getAttackDamage();
public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap &x);
	ClapTrap& operator = (const ClapTrap &x);

	std::string getName() const;
	ClapTrap(std::string name);
	ClapTrap(std::string name, int hitPoints, int energyPoints, int attackDamage);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};


#endif