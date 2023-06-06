#include "ClapTrap.hpp"

int main() {
	
	ClapTrap a("aaa");
	ClapTrap b("bbb");
	std::cout << std::endl;

	a.attack("bbb");
	b.takeDamage(a.getAttackDamageAmount());
	std::cout << std::endl;

	b.attack("aaa");
	a.takeDamage(7);
	std::cout << std::endl;

	b.beRepaired(3);
	std::cout << std::endl;

	a.attack("bbb");
	b.takeDamage(15);
	std::cout << std::endl;

	a.attack("bbb");
	b.takeDamage(5);
	std::cout << std::endl;

	b.beRepaired(10);
	std::cout << std::endl;

	b.attack("aaa");
	std::cout << std::endl;	

}