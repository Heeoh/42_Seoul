#include "RPN.hpp"
#include <iostream>

int main (int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: Invalid argument count" << std::endl;
		return 1;
	}

	try {
		std::cout << RPN::calculate(av[1]) << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}