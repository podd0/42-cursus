#include "Zombie.hpp"

int main()
{
	Zombie* pippo = newZombie("Pippo");
	Zombie* mario = newZombie("Mario");

	randomChump("sgrodo");
	pippo->announce();
	mario->announce();
	delete pippo;
	delete mario;
}
