#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: Invalid Argument" << std::endl;
		return 1;
	}
	try {
		ScalarConverter converter(av[1]);
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}