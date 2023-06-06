#include "ScavTrap.hpp"

int main() {
	
	ScavTrap a("aaa");
	ScavTrap b("bbb");
	std::cout << std::endl;

	a.attack("bbb");
	b.takeDamage(a.getAttackDamageAmount());
	std::cout << std::endl;

	b.guardGate();
	std::cout << std::endl;

	

}