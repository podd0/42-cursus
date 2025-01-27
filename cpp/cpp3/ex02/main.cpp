#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	ScavTrap ciro("Ciro");
	ScavTrap copia(ciro);
	std::cout<<&copia<<std::endl;
	std::cout<<&((ClapTrap&)copia)<<std::endl;
	return 0;
	ClapTrap pippo("Pippo");
	pippo.attack("Ciro");
	ciro.takeDamage(0);
	ciro.attack("Pippo");
	pippo.takeDamage(0);
	pippo.takeDamage(2);
	pippo.beRepaired(3);

	std::cout<<"\n\n";
	ScavTrap angry;
	for(int i = 0; i < 55; i++)
		angry.attack("boh");
	std::cout<<"\n\n";

	ClapTrap poeRatcho("Poe Ratcho");
	poeRatcho.takeDamage(69);
	poeRatcho.beRepaired(20);
	std::cout<<"\n\n";

	ScavTrap poeRello("Poe Rello");
	poeRello.takeDamage(69);
	poeRello.beRepaired(20);
	poeRello.guardGate();

	std::cout<<"\n\n";

	FragTrap mario;
	mario.attack("nemico");
	mario.highFivesGuys();

	std::cout<<"\n\n";

}