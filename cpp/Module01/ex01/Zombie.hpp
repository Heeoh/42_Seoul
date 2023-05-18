#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie {
private:
	std::string name;

public:
	Zombie();
	Zombie(std::string _name);
	~Zombie();
	
	void announce( void );
	void setName(std::string name);
};

# endif
