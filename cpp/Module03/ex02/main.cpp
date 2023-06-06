#include "FragTrap.hpp"

int main() {
	
	FragTrap a("aaa");
	FragTrap b("bbb");
	std::cout << std::endl;

	a.attack("bbb");
	b.takeDamage(a.getAttackDamageAmount());
	std::cout << std::endl;

	b.highFivesGuys();
	std::cout << std::endl;
}