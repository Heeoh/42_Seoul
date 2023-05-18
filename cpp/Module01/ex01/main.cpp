#include "Zombie.hpp"
#include <iostream>

extern Zombie* zombieHorde(int, std::string);

int main()
{
	int	nZombie = 5;
	Zombie *zombies = zombieHorde(nZombie, "wowow");

	for (int i=0; i<nZombie; i++)
		zombies[i].announce();

	delete[] zombies;
}