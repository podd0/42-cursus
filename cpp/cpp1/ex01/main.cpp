#include "Zombie.hpp"

int main()
{
	int n = 42;
	Zombie *horde = zombieHorde(n, "horde");
	Zombie *horde2 = zombieHorde(10, "horde2");

	for(int i = 0; i < n; i++)
		horde[i].announce();

	for(int i = 0; i < 10; i++)
		horde2[i].announce();

	delete[] horde2;
	delete[] horde;
}
