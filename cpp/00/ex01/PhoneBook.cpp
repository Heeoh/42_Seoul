#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

int main() {
	PhoneBook		phonebook;
	std::string		cmd;
	
	while(std::cin >> cmd) {
		if (cmd == "EXIT")
			std::cout << "exit\n";
	}


}