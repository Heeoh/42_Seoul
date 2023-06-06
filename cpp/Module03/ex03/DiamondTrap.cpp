#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap(), ScavTrap(), FragTrap(), name(ClapTrap::name) {
	ClapTrap::name = name + "_clap_name";
	this->energyPoint = SCAV_INITVALUE_EP;
	std::cout << "DiamondTrap default constructor is called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name) 
	: ClapTrap(_name + "_clap_name"),  ScavTrap(_name), FragTrap(_name), name(_name) {
	ClapTrap::name = name + "_clap_name";
	this->energyPoint = SCAV_INITVALUE_EP;
	std::cout << "DiamondTrap " << name << " constructor is called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) {
	*this = obj;
	std::cout << "DiamondTrap " << name << " copy constructor is called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
	if (this != &obj) {
		this->name = obj.name;
		this->hitPoint = obj.hitPoint;
		this->energyPoint = obj.energyPoint;
		this->attackDamage = obj.attackDamage;
	}
	return *this;
}
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << name << " destructor is called" << std::endl;
}


void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}

void	DiamondTrap::printState() {
	std::cout << "name: " << name 
			  << ", hp: " << hitPoint 
			  << ", ep: " << energyPoint 
			  << ", attack_dmg: " << attackDamage << std::endl;
}