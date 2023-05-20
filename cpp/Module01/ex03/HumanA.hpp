#ifndef HUMAN_A_H
# define HUMAN_A_H

# include "Weapon.hpp"
# include <iostream>

class HumanA {
public:
	HumanA(std::string _name, Weapon &_weapon);

private: 
	std::string name;
	Weapon &weapon;

public:
	void attack();
};

#endif