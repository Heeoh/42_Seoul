#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
private:
	std::string	name;

public:
	DiamondTrap();
	DiamondTrap(std::string _name);
	DiamondTrap(const DiamondTrap& obj);
	DiamondTrap& operator=(const DiamondTrap& obj);
	~DiamondTrap();

	void	attack(const std::string& target);
	void	whoAmI();
	void	printState();
};



#endif