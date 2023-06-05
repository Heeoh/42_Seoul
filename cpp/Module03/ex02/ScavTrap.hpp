#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string _name);
	ScavTrap(const ScavTrap& obj);
	ScavTrap& operator=(const ScavTrap& obj);
	~ScavTrap();

	void	attack(const std::string& target);
	void	guardGate();
};




#endif