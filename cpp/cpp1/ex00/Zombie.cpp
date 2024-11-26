#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout<<"Zombie " << name << " created\n";
}

Zombie::~Zombie()
{
	std::cout<<"Zombie " << name << " destroyed\n";
}