#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"

void PhoneBook::addNewContact()
{
	std::cout << "\nPlease input information of the new contact" << std::endl;
	
	Contact new_contact;
	new_contact.setContact();
	
	contacts[nContacts % 8] = new_contact;
	nContacts++;
	std::cout << "\nThe contact is saved" << std::endl;
	contacts[(nContacts - 1) % 8].printContact();
}

void PhoneBook::searchContact()
{
	int	idx;

	printContactList();
	std::cout << "\nPlease input the index of contact you want to search for: ";
	std::cin >> idx;
	if (!(0 <= idx && (nContacts < 8 ? idx < nContacts : idx < 8)))
		std::cout << "Error: the index is out of range or wrong" << std::endl;
	else
		contacts[idx].printContact();
}

void PhoneBook::printContactList()
{
	std::string fieldName[4] = {"index", "first name", "last name", "nickname"};

	std::cout << "================= saved contacts =================" << std::endl;

	for (int i = 0; i < 3; i++)
		printStringByFormat(fieldName[i], " | ");
	printStringByFormat(fieldName[3], "\n");

	for (int i = 0; i < nContacts && i < 8; i++) {
		printStringByFormat(std::to_string(i), " | ");
		printStringByFormat(contacts[i].getFirstName(), " | ");
		printStringByFormat(contacts[i].getLastName(), " | ");
		printStringByFormat(contacts[i].getNickname(), "\n");
	}

	std::cout << "==================================================" << std::endl;
}

void PhoneBook::printStringByFormat(std::string str, std::string sep)
{
	if (str.length() > 10)
		std::cout << str.replace(str.begin() + 9, str.end(), ".") << sep;
	else
		std::cout << std::setw(10) << str << sep; 
}