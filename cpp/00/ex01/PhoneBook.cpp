#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

void PhoneBook::addNewContact() {
	std::cout << "Please input information of the new contact" << std::endl;
	
	Contact new_contact;
	new_contact.setContact();
	
	contacts[nContacts % 8] = new_contact;
	nContacts++;
}

void PhoneBook::searchContact() {
	int	idx;

	printContactList();
	std::cout << "Please input the index of contact you want to search for: ";
	std::cin >> idx;
	if (!(0 <= idx && (idx < nContacts || i < 8)))
		std::cout << "Error: the index is out of range or wrong" << std::endl;
	else
		contacts[idx].printContact();
}

void printStringByFormat(std::string str, std::string sep) {
	if (str.length() > 10)
		std::cout << str.replace(str.begin() + 9, str.end(), ".") << sep;
	else
		std::cout << std::setw(10) << str << sep; 
}

void PhoneBook::printContactList() {
	std::cout << "================= saved contacts =================" << std::endl;
	std::cout << "1234567890 | 1234567890 | 1234567890 | 1234567890" << std::endl;
	for (int i=0; i < nContacts && i < 8; i++) {
		printStringByFormat(std::to_string(i), " | ");
		printStringByFormat(contacts[i].getFirstName(), " | ");
		printStringByFormat(contacts[i].getLastName(), " | ");
		printStringByFormat(contacts[i].getNickname(), "\n");
	}
}