#include "ClapTrap.hpp"

int main() {
	
	ClapTrap a("aaa");
	ClapTrap b("bbb");

	a.attack("bbb");
	b.takeDamage(3);

	b.attack("aaa");
	a.takeDamage(5);

	a.attack("bbb");
	b.takeDamage(3);

	b.beRepaired(5);

	a.attack("bbb");
	b.takeDamage(3);

	a.attack("bbb");
	b.takeDamage(3);

	a.attack("bbb");
	b.takeDamage(3);

	a.attack("bbb");
	b.takeDamage(3);
}