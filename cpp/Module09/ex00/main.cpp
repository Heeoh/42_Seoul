#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: invalid argument count." << std::endl;
		return 1;
	}

	try {
		BitcoinExchange a = BitcoinExchange();
		a.execute(av[1]);
	} catch (std::exception & e) {
		std::cout << "Error: " << e.what() << "." << std::endl;
		return 1;
	}
}