#include <iostream>
#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap gino("G1N0");

	gino.whoAmI();
	gino.attack("G4$P4R3");
	gino = DiamondTrap();

	gino.whoAmI();
	
}