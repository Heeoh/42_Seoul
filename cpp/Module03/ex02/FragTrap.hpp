#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : ClapTrap {
public:
	FragTrap();
	FragTrap(std::string _name);
	FragTrap(const FragTrap& obj);
	FragTrap& operator=(const FragTrap& obj);
	~FragTrap();

	void	highFivesGuys(void);
};


#endif