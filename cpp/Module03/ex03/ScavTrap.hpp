#ifndef SCAVTRAP_H
# define SCAVTRAP_H

# include "ClapTrap.hpp"

# define SCAV_INITVALUE_HP 100
# define SCAV_INITVALUE_EP 50
# define SCAV_INITVALUE_ATTACK_DMG 20

class ScavTrap: virtual public ClapTrap {
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