#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
private:
	int nContacts;
	Contact contacts[8];

public:
	PhoneBook(): nContacts(0) {}

	void addNewContact();
	void searchContact();
	void printContactList();
};

#endif