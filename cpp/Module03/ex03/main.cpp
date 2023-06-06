#include "DiamondTrap.hpp"
#include <iostream>

int main() {
	
	DiamondTrap a("aaa");
	std::cout << std::endl;

	a.printState();
	std::cout << std::endl;

	a.attack("bbb");
	std::cout << std::endl;

	a.takeDamage(10);
	std::cout << std::endl;

	a.beRepaired(10);
	std::cout << std::endl;

	a.guardGate();
	std::cout << std::endl;

	a.highFivesGuys();
	std::cout << std::endl;

	a.whoAmI();
	std::cout << std::endl;

}