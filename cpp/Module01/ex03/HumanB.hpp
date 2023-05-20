#ifndef HUMAN_B_H
# define HUMAN_B_H

# include "Weapon.hpp"
# include <iostream>

class HumanB {
public:
	HumanB(std::string _name);

private: 
	std::string name;
	Weapon *weapon;

public:
	void attack();
	void setWeapon(Weapon &_weapon);
};

#endif