#include "Weapon.hpp"

Weapon::Weapon() : type("") {}

Weapon::Weapon(std::string _type)
	: type(_type) {}

std::string Weapon::getType()
{
	return type;
}

void Weapon::setType(std::string _type)
{
	type = _type;
}