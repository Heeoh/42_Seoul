#ifndef FRAGTRAP_H
# define FRAGTRAP_H

# include "ClapTrap.hpp"

# define FRAG_INITVALUE_HP 100
# define FRAG_INITVALUE_EP 100
# define FRAG_INITVALUE_ATTACK_DMG 30

class FragTrap : virtual public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string _name);
	FragTrap(const FragTrap& obj);
	FragTrap& operator=(const FragTrap& obj);
	~FragTrap();

	void	highFivesGuys(void);
};


#endif