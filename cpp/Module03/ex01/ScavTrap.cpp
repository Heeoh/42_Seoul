#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor is called" << std::endl;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name) {
	hitPoint = 100;
	energyPoint = 50;
	attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor is called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj) {
	std::cout << "ScavTrap " << name << " copy constructor is called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
	if (this != &obj) {
		name = obj.name;
		hitPoint = obj.hitPoint;
		energyPoint = obj.energyPoint;
		attackDamage = obj.attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " destructor is called" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	if (isDead())
		std::cout << "ScavTrap " << name << " is dead, cannot do anythig!";
	else if (!hasEnergy())
		std::cout << "ScavTrap " << name << " has no energy, cannot do anythig!" << std::endl;
	else {
		energyPoint--;
		std::cout << "ScavTrap " << name << " attacks " << target
				<< ", causing " << attackDamage << " points of damage! "
				<< "[hp: " << hitPoint << ", ep: " << energyPoint << "]"
				<< std::endl;
	}
}

void	ScavTrap::guardGate() {
	if (isDead())
		std::cout << "ScavTrap " << name << "is dead, cannot do anything!";
	std::cout << "ScavTrap " << name << " is now in Gate Keepter Mode!" << std::endl;
}