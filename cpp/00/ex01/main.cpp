#include <iostream>
#include "PhoneBook.hpp"

int main()
{
	PhoneBook		phonebook;
	std::string		cmd;
	
    std::cout << "input cmd: ";
	while(std::cin >> cmd) {
        if (cmd == "ADD")
            phonebook.addNewContact();
        else if (cmd == "SEARCH")
            phonebook.searchContact();
		else if (cmd == "EXIT") {
			std::cout << "exit\n";
            return 0;
        }
        std::cout << "\ninput cmd: ";
	}
}