#include <iostream>
#include "Harl.hpp"

int main(int ac, char *av[])
{	
	if (ac != 2) {
		std::cout << "Error: wrong arguments" << std::endl;
		return (1);
	}

	Harl harl;

	harl.complain(av[1]);
}