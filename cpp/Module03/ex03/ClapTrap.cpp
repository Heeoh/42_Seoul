#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: name(""), hitPoint(10), energyPoint(10), attackDamage(0) {
	std::cout << "ClapTrap default constructor is called" << std::endl;
}

ClapTrap::ClapTrap(std::string _name)
	: name(_name), hitPoint(10), energyPoint(10), attackDamage(0)  {
	std::cout << "ClapTrap " << name << " constructor is called" << std::endl;

}

ClapTrap::ClapTrap(const ClapTrap& obj) {
	*this = obj;
	std::cout << "ClapTrap " << name << " copy constructor is called" << std::endl;
}
	
ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
	if (this != &obj) {
		name = obj.name;
		hitPoint = obj.hitPoint;
		energyPoint = obj.energyPoint;
		attackDamage = obj.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " destructor is called" << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (isDead())
		std::cout << "ClapTrap " << name << " is dead, cannot do anythig!" << std::endl;
	else if (!hasEnergy())
		std::cout << "ClapTrap " << name << " has no energy, cannot do anythig!" << std::endl;
	else {
		energyPoint--;
		std::cout << "ClapTrap " << name << " attacks " << target
				<< ", causing " << attackDamage << " points of damage! "
				<< "[hp: " << hitPoint << ", ep: " << energyPoint << "]"
				<< std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (isDead()) {
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;
		return ;
	}
	hitPoint = (amount < hitPoint) ? hitPoint - amount : 0;
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!"
			  << "[hp: " << hitPoint << ", ep: " << energyPoint << "]"
			  << std::endl;
	if (isDead())
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (isDead())
		std::cout << "ClapTrap " << name << " is dead, cannot do anythig!" << std::endl;
	else if (!hasEnergy())
		std::cout << "ClapTrap " << name << " has no energy, cannot do anythig!" << std::endl;
	else {
		energyPoint--;
		hitPoint += amount;
		std::cout << "ClapTrap " << name << " repairs itself and gets " 
				<< amount << " of hit points back! " 
				<< "[hp: " << hitPoint << ", ep: " << energyPoint << "]"
				<< std::endl;
	}
}

bool	ClapTrap::isDead() {
	return (hitPoint <= 0) ? true : false;
}

bool	ClapTrap::hasEnergy() {
	return (energyPoint > 0) ? true : false;
}

unsigned int	ClapTrap::getAttackDamageAmount() {
	return attackDamage;
}
