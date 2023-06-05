#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor is called" << std::endl;
}

FragTrap::FragTrap(std::string _name)  : ClapTrap(_name) {
	hitPoint = 100;
	energyPoint = 100;
	attackDamage = 30;
	std::cout << "FragTrap " << name << " constructor is called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj) {
	std::cout << "FragTrap " << name << " copy constructor is called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
	if (this != &obj) {
		name = obj.name;
		hitPoint = obj.hitPoint;
		energyPoint = obj.energyPoint;
		attackDamage = obj.attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << name << " destructor is called" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	if (isDead())
		std::cout << "FragTrap " << name << "is dead, cannot do anything!";
	std::cout << "FragTrap " << name << " do high five!" << std::endl;
}