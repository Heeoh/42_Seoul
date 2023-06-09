#include "Character.hpp"

Character::Character() {
	std::cout << "Character default constructor is called" << std::endl;
	for (int i=0; i<4; i++)
		slot[i] = NULL;
}

Character::Character(const Character& obj) {
	std::cout << "Character copy constructor is called" << std::endl;
	*this = obj;
}

Character& Character::operator= (const Character& obj) {
	std::cout << "Character operator= is called" << std::endl;
	if (this != &obj) {
		for (int i=0; i<4; i++)
			slot[i] = obj.getMateriaInSlot(i);
	}
	return *this;
}

Character::~Character() {
	std::cout << "Character destructor is called" << std::endl;
}

std::string const & Character::getName() const {

}

void Character::equip(AMateria* m) {

}

void Character::unequip(int idx) {

}

void Character::use(int idx, ICharacter& target) {

}

AMateria*	Character::getMateriaInSlot(int idx) {
	return slot[idx];
}