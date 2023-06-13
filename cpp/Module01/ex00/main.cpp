#include "Zombie.hpp"
#include <iostream>

int main()
{
	Zombie *new_a = newZombie("new_A");
	Zombie *new_b = newZombie("new_B");
	Zombie stk_a = Zombie("stk_A");

	new_a->announce();
	new_b->announce();
	stk_a.announce();
	
	delete new_a;

	randomChump("random_A");
	randomChump("random_B");

	delete new_b;
}