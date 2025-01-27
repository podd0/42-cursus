#include <iostream>
#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap ciro("Ciro");
	ClapTrap copia(ciro);
	ClapTrap pippo("Pippo");
	pippo.attack("Ciro");
	ciro.takeDamage(0);
	ciro.attack("Pippo");
	pippo.takeDamage(0);
	pippo.takeDamage(2);
	pippo.beRepaired(3);

	ClapTrap angry;
	for(int i = 0; i < 15; i++)
		angry.attack("boh");
	
	ClapTrap poeRatcho("Poe Ratcho");
	poeRatcho.takeDamage(69);
	poeRatcho.beRepaired(20);

}