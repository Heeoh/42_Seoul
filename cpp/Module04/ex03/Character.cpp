#include "Character.hpp"

Character::Character() : ICharacter() {
	std::cout << "Character defalut constructor is called" << std::endl;
    this->name = "";
    for (int i=0; i<4; i++) {
        this->inventory[i] = NULL;
    }
}

Character::Character(const Character& obj) : ICharacter() {
	std::cout << "Character copy constructor is called" << std::endl;
	*this = obj;
}

Character& Character::operator=(const Character& obj) {
	std::cout << "Character assignment operator is called" << std::endl;
	if (this != &obj) {
        this->name = obj.getName();
        for (int i=0; i<4; i++) {
            if (obj.getInventory(i)) {
                std::cout << obj.getInventory(i)->getType();
            }
            // if (this->inventory[i])
            //     delete this->inventory[i];
            // this->inventory[i] = (obj.getInventory(i))->clone();
        }
    }
	return *this;
}

Character::~Character() {
	// std::cout << "Character destructor is called" << std::endl;
    for (int i=0; i<4; i++) {
        if (this->inventory[i])
            delete this->inventory[i];
    }
}

Character::Character(std::string name) : ICharacter() {
	// std::cout << "Character constructor is called." << std::endl;
    this->name = name;
    for (int i=0; i<4; i++) {
        this->inventory[i] = NULL;
    }
}

std::string const& Character::getName() const {
    return this->name;
}

void Character::equip(AMateria* m) {
    int idx = 0;
    for ( ; idx<4; idx++) {
        if (this->inventory[idx] == NULL) 
            break;
    }

    if (idx >= 4) {
        std::cout << "Inventory is full. Remove items to make space." << std::endl;
        return;
    } 

    this->inventory[idx] = m;
    std::cout << "Equipped " << m->getType() << " in slot " << idx << "." << std::endl;
}

void Character::unequip(int idx) {
    if (!this->inventory[idx]) {
        std::cout << "Slot " << idx << " is empty." << std::endl;
        return;
    }

    std::cout << "Unequipped " << this->inventory[idx]->getType() << " from slot " << idx << "." << std::endl;
    this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (!this->inventory[idx]) {
        std::cout << "Slot " << idx << " is empty." << std::endl;
        return;
    }

    this->inventory[idx]->use(target);
}

AMateria* Character::getInventory(int idx) const {
    return this->inventory[idx];
}