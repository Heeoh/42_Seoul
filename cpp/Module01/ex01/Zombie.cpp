#include "Zombie.hpp"

Zombie::Zombie() : name("")
{
	std::cout << "Zombie is created" << std::endl;	
}

Zombie::Zombie(std::string _name) : name(_name)
{
	std::cout << "Zombie " << name << " is created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " is dead" << std::endl;
}

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string _name)
{
	name = _name;
}
