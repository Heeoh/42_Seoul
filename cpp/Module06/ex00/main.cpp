#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: Invalid number of Argument" << std::endl;
		return 1;
	}
	try {
		ScalarConverter::convert(av[1]);
	}
	catch (std::exception & e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}